#include <iostream>
#include <vector>
#include <string>
#include <memory>

int main()
{
    // ����get_size() ȷ��������ٸ�int
    int *pia = new int[30]; // piaָ���һ��int
    delete [] pia;
    
    typedef int arrType[40]; // arrType ��ʾ40��int����������
    int *p = new arrType; // ����һ��40��Ԫ�ص�int���飻pָ���һ��int��������ִ�б��ʽʱ���ǻ���new []
    delete [] p;
    
    // ʹ��unique_ptr����̬����
    std::unique_ptr<int[]> up(new int[10]);
    for (int index = 0; index < 10; ++index)
        std::cout << up[index] << " ";
    std::cout << "End!" << std::endl;
    up.release();
    
    // Ϊ��ʹ��shared_ptr�������ṩһ��ɾ����
    std::shared_ptr<int> sp(new int[10]), [](int *p) { delete [] p; });
    // shared_ptrδ�����±�����������Ҳ�֧��ָ�����������
    for (std::size_t i = 0; i != 10; ++i)
        *(sp.get() + i) = i; // ʹ��get��ȡһ������ָ��
    
    sp.reset(); // ʹ�������ṩ��lambda�ͷ����飬��ʹ�� delete []
    
    return 0;
}