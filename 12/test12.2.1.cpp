#include <iostream>
#include <vector>
#include <string>
#include <memory>

int main()
{
    // 调用get_size() 确定分配多少个int
    int *pia = new int[30]; // pia指向第一个int
    delete [] pia;
    
    typedef int arrType[40]; // arrType 表示40个int的数组类型
    int *p = new arrType; // 分配一个40个元素的int数组；p指向第一个int；编译器执行表达式时还是会有new []
    delete [] p;
    
    // 使用unique_ptr管理动态数组
    std::unique_ptr<int[]> up(new int[10]);
    for (int index = 0; index < 10; ++index)
        std::cout << up[index] << " ";
    std::cout << "End!" << std::endl;
    up.release();
    
    // 为了使用shared_ptr，必须提供一个删除器
    std::shared_ptr<int> sp(new int[10]), [](int *p) { delete [] p; });
    // shared_ptr未定义下标运算符，并且不支持指针的算术运算
    for (std::size_t i = 0; i != 10; ++i)
        *(sp.get() + i) = i; // 使用get获取一个内置指针
    
    sp.reset(); // 使用我们提供的lambda释放数组，它使用 delete []
    
    return 0;
}