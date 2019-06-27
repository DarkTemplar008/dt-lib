#include <iostream>
#include "../instance_counter.hpp"

struct Base : dt::base::InstanceCounter<Base> {
    Base(const std::string& name) : dt::base::InstanceCounter<Base>(name) {

    }
    Base() : dt::base::InstanceCounter<Base>() {

    }
};

struct Base2 : dt::base::InstanceCounter<> {
    Base2(const std::string& name) : dt::base::InstanceCounter<>(name) {

    }
    Base2() : dt::base::InstanceCounter<>() {

    }
};

int main(int argc, char* argv[]) {
    Base b1("Hello");
    std::cout << b1.Name() << "(" << b1.ID() << "):"<< b1.UUID() << std::endl;
    Base b2;
    std::cout << b2.Name() << "(" << b2.ID() << "):"<< b2.UUID() << std::endl;
    Base2 b11("Hello");
    std::cout << b11.Name() << "(" << b11.ID() << "):"<< b11.UUID() << std::endl;
    Base2 b22;
    std::cout << b22.Name() << "(" << b22.ID() << "):"<< b22.UUID() << std::endl;
    return 0;
}