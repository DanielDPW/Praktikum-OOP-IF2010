#include <iostream>
#include <math.h>
using namespace std;

template<class K, class V>
class KeyValue {
private:
    K keys[10];
    V values[10];
    int idx = 0;

public:
    void set(K key, V value) {
        for (int i = 0; i < idx; i++) {
            if (keys[i] == key) {
                values[i] = value;
                return;
            }
        }
        if (idx < 10) {
            keys[idx] = key;
            values[idx] = value;
            idx++;
        } else {
            cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
        }
    }

    void display(K key) {
        for (int i = 0; i < idx; i++) {
            if (keys[i] == key) {
                cout << values[i] << endl;
                return;
            }
        }
        cout << "Key tidak ditemukan!" << endl;
    }
};

template<class V>
class KeyValue<double, V> {
private:
    double keys[10];
    V values[10];
    int idx = 0;

public:
    void set(double key, V value) {
        for (int i = 0; i < idx; i++) {
            if (fabs(keys[i] - key) < 0.01) {
                values[i] = value;
                return;
            }
        }
        if (idx < 10) {
            keys[idx] = key;
            values[idx] = value;
            idx++;
        } else {
            cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
        }
    }

    void display(double key) {
        for (int i = 0; i < idx; i++) {
            if (fabs(keys[i] - key) < 0.01) {
                cout << values[i] << endl;
                return;
            }
        }
        cout << "Key tidak ditemukan!" << endl;
    }
};