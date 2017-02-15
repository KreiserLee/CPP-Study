#include "Quote.h"

class Bulk_quote : public Quote { // Bulk_quote继承了Quote
public:
    // 派生类必须在其内部对所有重新定义的虚函数进行声明。
    double net_price(std::size_t) const override;
};