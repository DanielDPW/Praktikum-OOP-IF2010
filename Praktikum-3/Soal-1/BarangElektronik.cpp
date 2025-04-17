#include "BarangElektronik.hpp"

BarangElektronik::BarangElektronik(string nama, int berat, int voltase) : Barang(nama, berat) {
    this->voltase = voltase;
}

int BarangElektronik::getVoltase() const {
    return voltase;
}

string BarangElektronik::getJenis() const {
    return "Elektronik";
}