#include "Quote.h"

class Bulk_quote : public Quote { // Bulk_quote�̳���Quote
public:
    // ��������������ڲ����������¶�����麯������������
    double net_price(std::size_t) const override;
};