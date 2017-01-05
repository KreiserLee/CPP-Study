class StrVec {
    // vector类的一个简化版本，只用于string
    // 将其元素保存在连续内存中
    public:
        StrVec():elements(nullptr), first_free(nullptr), cap(nullptr) {}
        StrVec(const StrVec&); // 拷贝构造函数
        StrVec& operator=(const StrVec&); // 拷贝赋值运算符
        ~StrVec(); // 析构函数
        
        void push_back(const std::string&); // 拷贝元素
        size_t size() const { return first_free - elements; }
        size_t capacity() const { return cap - elements; }
        std::string* begin() const { return elements; }
        std::string* end() const { return first_free; }
    private:
        std::string* elements; // 指向分配的内存中的首元素
        std::string* first_free; // 指向最后一个实际元素之后的位置
        std::string* cap; // 指向分配的内存末尾之后的位置
        
        static std::allocator<string> alloc; // 分配StrVec使用的内存
        
        void chk_n_alloc(){
            if (size() == capacity())
                reallocate();
        }
        
        // 工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
        std::pair<std::string*,, std::string*> alloc_n_copy
            (const std::string*, const std::string*);
        void free(); // 销毁元素并释放内存
        void reallocate(); // 获得更多内存并拷贝已有元素
};

void StrVec::push_back(const string& s) {
    chk_n_alloc(); // 确保有空间容纳新元素
    alloc.construct(first_free++, s); // 使用string的拷贝构造函数
}