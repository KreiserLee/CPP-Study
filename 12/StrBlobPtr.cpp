class StrBlobPtr {
    public:
        StrBlobPtr(): curr(0) { }
        StrBlobPtr(StrBlob &a, size_t sz = 0):
            wptr(a.data), curr(sz) { }
        std::string& deref() const;
        StrBlobPtr& incr(); //前缀递增
    private:
        // 若检查成功，check返回一个指向vector的shared_ptr
        std::shared_ptr<std::vector<std::string>>
            check(std::size_t,, const std::string&) const;
        // 保存一个weak_ptr，意味着底层vector可能会被销毁
        std::weak_ptr<std::vector<std::string>> wptr;
        std::size_t curr; //在数组中的当前位置
};

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string&msg) const
{
    auto ret = wptr.lock();// 检查动态vector是否存在
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret-size())
        throw std::out_of_range(msg);
    return ret; // 否则，返回指向动态vector的shared_ptr
}

std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; //(*p)是对象所指向的vector
}

//前缀递增，返回递增后的对象的引用
StrBlobPtr& StrBlobPtr::incr()
{
    //如果curr已经指向容器的尾后位置，就不能递增它
    check(curr, "increment past end of StrBlobPtr");
    ++curr; //推进当前位置
    return *this;
}