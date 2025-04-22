#include "Kompleks.hpp"

Kompleks::Kompleks() : real(0), imag(0) {}

Kompleks::Kompleks(double r, double i) : real(r), imag(i) {}

Kompleks::Kompleks(const Kompleks &other) {
    if (this != &other) {
        this->real = other.getReal();
        this->imag = other.getImag();
    }
}

double Kompleks::getReal() const {
    return real;
}

double Kompleks::getImag() const {
    return imag;
}

double Kompleks::setReal(double r) {
    this->real = r;
    return r;
}

double Kompleks::setImag(double i) {
    this->imag = i;
    return i;
}

Kompleks Kompleks::operator+(const Kompleks &other) const {
    return Kompleks(this->getReal() + other.getReal(), this->getImag() + other.getImag());
}

Kompleks Kompleks::operator-(const Kompleks &other) const {
    return Kompleks(this->getReal() - other.getReal(), this->getImag() - other.getImag());
}

Kompleks Kompleks::operator*(const Kompleks &other) const {
    double newReal = this->getReal() * other.getReal() - this->getImag() * other.getImag();
    double newImag = this->getReal() * other.getImag() + this->getImag() * other.getReal();
    return Kompleks(newReal, newImag);
}

bool Kompleks::operator==(const Kompleks &other) const {
    return (this->getReal() == other.getReal()) && (this->getImag() == other.getImag());
}

Kompleks &Kompleks::operator=(const Kompleks &other) {
    if (this != &other) {
        this->real = other.getReal();
        this->imag = other.getImag();
    }
    return *this;
}

ostream &operator<<(ostream &os, const Kompleks &c) {
    os << c.getReal();
    if (c.getImag() < 0) {
        os << " - " << -1 * c.getImag() << "i";
    } else if (c.getImag() > 0) {
        os << " + " << c.getImag() << "i";
    }

    return os;
}
