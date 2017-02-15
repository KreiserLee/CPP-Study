#include <string>
class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    
    // ���ظ����������鼮�������ܶ�
    // �����ฺ���д��ʹ�ò�ͬ���ۿۼ����㷨
    virtual double net_price(std::size_t n) const
        { return n*price; }
    virtual ~Quote() = default; // �������������ж�̬��
private:
    std::string bookNo; // �鼮��ISBN���
protected:
    double price = 0.0; // ������ͨ״̬�²����۵ļ۸�
};