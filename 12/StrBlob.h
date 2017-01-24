// 对于StrBlob中的友元声明来说，此前置声明是必要的
class StrBlobPtr;
class StrBlob {
    public:
        typedef std::vector<std::string>::size_type size_type;

        //核查指针类（伴随指针类）操作
        friend class StrBlobPtr;
        StrBlobPtr begin() { return StrBlobPtr(*this); }
        StrBlobPtr end()
        {
            auto ret = StrBlobPtr(*this, data->size());
            return ret;
        }

        StrBlob();
        StrBlob(std::initializer_list<std::string> il);
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        // ���Ӻ�ɾ��Ԫ��
        void push_back(const std::string &t) {data->push_back(t); }
        void pop_back();
        // Ԫ�ط���
        std::string& front();
        std::string& back();
    private:
        std::shared_ptr<std::vector<std::string>> data;
        // ����data[i]���Ϸ����׳�һ���쳣
        void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob(): data(make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(initializer_list<std::string> il):
    data(make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}

std::string& StrBlob::front() {
    // ����vectorΪ�գ�check���׳�һ���쳣
    check(0, "front on empty StrBlob!");
    return data->front();
}

std::string& StrBlob::back() {
    check(0, "back on empty StrBlob!");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob!");
    data->pop_back();
}

