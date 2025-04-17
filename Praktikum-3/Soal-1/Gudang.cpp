#include "Gudang.hpp"
#include "BarangMakanan.hpp"
#include "BarangElektronik.hpp"
#include "Exception.hpp"
#include <iostream>

Gudang::Gudang() : kapasitasTotal(DEFAULT_KAPASITAS), kapasitasTerpakai(0), tenagaKerja(DEFAULT_TENAGA_KERJA), uang(DEFAULT_UANG) { }

Gudang::Gudang(int kapasitas, int uang, int tenagaKerja) : kapasitasTotal(kapasitas), kapasitasTerpakai(0), uang(uang), tenagaKerja(tenagaKerja) { }

Gudang::~Gudang() {
    
}

void Gudang::simpanBarang(Barang *barang) {
    int kg = barang->getBerat();
    bool success = true;
    try {
        
        if(barang->getJenis() == "Makanan") {
            BarangMakanan *makanan = dynamic_cast<BarangMakanan *>(barang);
            if (makanan->getHariKedaluwarsa() <= 0) {
                throw BarangKedaluwarsaException();
            }
        }
        pakaiKapasitas(kg);
        pakaiUang(100);
        pakaiTenagaKerja();
        daftarBarang.push_back(barang);
        cout << "Barang [" << daftarBarang.size() - 1 << "] " << barang->getNama() << " berhasil disimpan" << endl;
    } catch (const BarangKedaluwarsaException& e) {
        cout << e.what() << ", buang dulu." << endl;
    } catch (const KapasitasPenuhException& e) {
        cout << e.what() << ", perluas gudang dulu." << endl;
    } catch (const UangTidakCukupException& e) {
        cout << e.what() << ", cari pemasukan dulu." << endl;
        kapasitasTerpakai -= kg;
    } catch (const TenagaKerjaTidakCukupException& e) {
        cout << e.what() << ", rekrut dulu." << endl;
        kapasitasTerpakai -= kg;
        tambahUang(100);
    }
    
    
}

void Gudang::tambahKapasitas(int kg) {
    kapasitasTotal += kg;
}

void Gudang::tambahTenagaKerja(int jumlah) {
    tenagaKerja += jumlah;
}

void Gudang::tambahUang(int jumlah) {
    uang += jumlah;
}

void Gudang::pakaiKapasitas(int kg) {
    if (kg > kapasitasTotal - kapasitasTerpakai) {
        throw KapasitasPenuhException();
    } else {
        kapasitasTerpakai += kg;
    }
}

void Gudang::pakaiUang(int jumlah) {
    if (uang < jumlah) {
        throw UangTidakCukupException();
    } else {
        uang -= jumlah;
    }
}

void Gudang::pakaiTenagaKerja() {
    if (tenagaKerja <= 0) {
        throw TenagaKerjaTidakCukupException();
    } else {
        tenagaKerja--;
    }
}

void Gudang::sebutBarang(int idx) {
    try {
        Barang* barang = daftarBarang.at(idx);
        cout << barang->getNama() << " - " << barang->getJenis() << " - " << barang->getBerat() << "kg" << endl;
    }
    catch (const std::out_of_range& e) {
        cout << e.what() << endl;
    }
}

void Gudang::statusGudang() const {
    cout << "Status gudang:" << endl;
    cout << "  Kapasitas total: " << kapasitasTotal << " kg" << endl;
    cout << "  Kapasitas terpakai: " << kapasitasTerpakai << " kg" << endl;
    cout << "  Uang: " << uang << endl;
    cout << "  Tenaga kerja: " << tenagaKerja << endl;
    cout << "  Barang:" << endl;
    for (int idx = 0; idx < daftarBarang.size(); idx++) {
        cout << "    [" << idx << "] " << daftarBarang[idx]->getNama() << " - " << daftarBarang[idx]->getJenis() << " - " << daftarBarang[idx]->getBerat() << "kg" << endl;
    }
}