#include <iostream>
#include <memory>
using namespace std;

int main()
{
    // std::allocator<int> alloInt; // 可以分配int的allocator对象
    // auto const p = alloInt.allocate(10); // 分配n个未初始化的int
    
    typedef int T;
    int n = 10;
    
    allocator<T> a; // 定义了一个名为啊的allocator对象，它可以为类型为T的对象分配内存
    
    T* p = a.allocate(n); // 分配一段原始的、未构造的内存，保存n个类型为T的对象
    
    for (T* q = p; q != p + n; ++q)
        a.construct(q, 1); // p是一个类型为T*的指针，指向一块原始内存；
                           // args被传递给类型为T的构造函数,
                           // 用来在p指向的内存中构造一个对象
        
    for (T* q = p; q != p + n; ++q) {
        cout << *q << endl;
        a.destroy(q);      // p为T*类型的指针，此算法对p指向的对象执行析构函数
    }
     
    a.deallocate(p, n);    // 释放从T*指针p中地址开始的内存，这块内存保存了n个类型为T的对象；
                           // p必须是一个先前由allocate返回的指针，且n必须是p创建时所要求的大小。
                           // 在调用deallocate之前，用户必须对每个在这块内存中创建的对象调用destroy
    
    return 0;
}