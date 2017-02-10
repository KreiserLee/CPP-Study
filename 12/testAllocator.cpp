#include <iostream>
#include <memory>
using namespace std;

int main()
{
    // std::allocator<int> alloInt; // ���Է���int��allocator����
    // auto const p = alloInt.allocate(10); // ����n��δ��ʼ����int
    
    typedef int T;
    int n = 10;
    
    allocator<T> a; // ������һ����Ϊ����allocator����������Ϊ����ΪT�Ķ�������ڴ�
    
    T* p = a.allocate(n); // ����һ��ԭʼ�ġ�δ������ڴ棬����n������ΪT�Ķ���
    
    for (T* q = p; q != p + n; ++q)
        a.construct(q, 1); // p��һ������ΪT*��ָ�룬ָ��һ��ԭʼ�ڴ棻
                           // args�����ݸ�����ΪT�Ĺ��캯��,
                           // ������pָ����ڴ��й���һ������
        
    for (T* q = p; q != p + n; ++q) {
        cout << *q << endl;
        a.destroy(q);      // pΪT*���͵�ָ�룬���㷨��pָ��Ķ���ִ����������
    }
     
    a.deallocate(p, n);    // �ͷŴ�T*ָ��p�е�ַ��ʼ���ڴ棬����ڴ汣����n������ΪT�Ķ���
                           // p������һ����ǰ��allocate���ص�ָ�룬��n������p����ʱ��Ҫ��Ĵ�С��
                           // �ڵ���deallocate֮ǰ���û������ÿ��������ڴ��д����Ķ������destroy
    
    return 0;
}