#include <iostream>
#include <string>
using namespace std;

class Sales_data {
    public:
        Sales_data(){}
        Sales_data(string s, int u, double r):bookNo(s), units_sold(u), revenue(r){}
        Sales_data(const Sales_data&);
        void showData();
    private:
        string bookNo;
        int units_sold;
        double revenue;
};

Sales_data::Sales_data(const Sales_data& orig):
    bookNo(orig.bookNo),
    units_sold(orig.units_sold),
    revenue(orig.revenue)    
{
    cout << "This is in copy constructor!" << endl;
}

void Sales_data::showData() {
    cout << bookNo << " " << units_sold << " " << revenue << endl;   
}

int main()
{
    Sales_data a("ABC", 10, 19.99);
    a.showData();
    Sales_data b(a);
    b.showData();
    Sales_data c = a;
    c.showData();
    Sales_data d;
    d.showData();
    d = a;// ¿½±´¸³ÖµÔËËã·û
    d.showData();
    return 0;   
}