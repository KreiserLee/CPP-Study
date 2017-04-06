#include "Quote.h"

class Bulk_quote : public Quote { // Bulk_quote继承了Quote
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &, double, std::size_t, double);

    // 派生类必须在其内部对所有重新定义的虚函数进行声明。
    double net_price(std::size_t) const override;
private:
    std::size_t min_qty = 0; // 使用折扣政策的最低购买量
    double discount = 0.0;   // 以小数表示的折扣额
};

Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc):
    Quote(book, p), min_qty(qty), discount(disc) { }

