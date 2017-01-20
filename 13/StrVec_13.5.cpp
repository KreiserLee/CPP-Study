class StrVec {
    // vector���һ���򻯰汾��ֻ����string
    // ����Ԫ�ر����������ڴ���
    public:
        StrVec():elements(nullptr), first_free(nullptr), cap(nullptr) {}
        StrVec(const StrVec&); // �������캯��
        StrVec& operator=(const StrVec&); // ������ֵ�����
        ~StrVec(); // ��������
        
        void push_back(const std::string&); // ����Ԫ��
        size_t size() const { return first_free - elements; }
        size_t capacity() const { return cap - elements; }
        std::string* begin() const { return elements; }
        std::string* end() const { return first_free; }
    private:
        std::string* elements; // ָ�������ڴ��е���Ԫ��
        std::string* first_free; // ָ�����һ��ʵ��Ԫ��֮���λ��
        std::string* cap; // ָ�������ڴ�ĩβ֮���λ��
        
        static std::allocator<string> alloc; // ����StrVecʹ�õ��ڴ�
        
        void chk_n_alloc(){
            if (size() == capacity())
                reallocate();
        }
        
        // ���ߺ��������������캯������ֵ�����������������ʹ��
        std::pair<std::string*, std::string*> alloc_n_copy
            (const std::string*, const std::string*);
        void free(); // ����Ԫ�ز��ͷ��ڴ�
        void reallocate(); // ��ø����ڴ沢��������Ԫ��
};

void StrVec::push_back(const string& s) {
    chk_n_alloc(); // ȷ���пռ�������Ԫ��
    alloc.construct(first_free++, s); // ʹ��string�Ŀ������캯��
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e) {
    
}

void StrVec::reallocate()
{
    // ���ǽ����䵱ǰ��С�������ڴ�ռ�
    auto newcapacity = size() ? 2*size() : 1;
    // �������ڴ�
    auto newdata = alloc.allocate(newcapacity);
    // �����ݴӾ��ڴ��ƶ������ڴ�
    auto dest = newdata; // ָ������������һ������λ��
    auto elem = elements; // ָ�����������һ��Ԫ��
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free(); // �ƶ���Ԫ�ؾ��ͷž��ڴ�ռ�
    // �������ݽṹ��ִ����Ԫ��
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}