#include "Dragon.hpp"
#include <iostream>

int main(void) {
    Dragon X("Draco");
    Creature Y = X;
    Creature &Z = X;
    X.speak();
    X.wound();
    X.wound();
    X.print();
    X.speak();
    Y.wound();
    Y.print();
    Z.wound();
    X.print();
    Y.speak();
    Y.wound();
    Y.print();
    X.print();
}