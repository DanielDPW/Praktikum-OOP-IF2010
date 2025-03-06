#include "Item.hpp"
using namespace std;

int Item::totalItems = 0;
int Item::totalRevenue = 0;

Item::Item() : serialNum(totalItems + 1) {
    this->stock = 0;
    this->price = 0;
    this->sold = 0;
    totalItems++;
}

Item::Item(int stock, int price) : serialNum(totalItems + 1) {
    this->stock = stock;
    this->price = price;
    this->sold = 0;
    totalItems++;
}

Item::Item(const Item& other) : serialNum(totalItems + 1) {
    this->stock = other.stock;
    this->price = other.price;
    this->sold = other.sold;
    totalItems++;
}

Item::~Item() {

}

int Item::getSerialNum() const {
    return serialNum;
}

int Item::getSold() const {
    return sold;
}

int Item::getPrice() const {
    return price;
}

void Item::addStock(int addedStock) {
    this->stock += addedStock;
}

void Item::sell(int soldStock) {
    int itemsSold = (stock >= soldStock) ? soldStock : stock;
    this->stock -= itemsSold;
    this->sold += itemsSold;
    totalRevenue += itemsSold * this->price;
}

void Item::setPrice(int newPrice) {
    this->price = newPrice;
}