#include <iostream>
#include <string>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

struct TypeS {
    int x[10000];
};

TypeS* factory() {
    TypeS* t = new TypeS();
    return t;
}

void use() {
    TypeS* t = factory();
    return;
}

shared_ptr<TypeS> factory1() {
    shared_ptr<TypeS> t = make_shared<TypeS>();
    return t;
}

void use1() {
    shared_ptr<TypeS> t = factory1();
    return;
}

int main()
{
    int i = 100000;
    cout << i << endl;
    while(--i) {
        use1();
    }
    cout << i << endl;
    
    return 0;   
}

