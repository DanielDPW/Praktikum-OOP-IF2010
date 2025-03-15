#include "User.hpp"
#include "AdminUser.hpp"
#include "Authenticator.hpp"

using namespace std;

Authenticator::Authenticator() {
    this->userCount = 0;
    this->currentUser = nullptr;
    this->secretResource = "Ini adalah data rahasia!";
}

void Authenticator::registerUser(const string &username, const string &password, bool isAdmin) {
    if (userCount >= MAX_USERS) {
        cout << "Gagal: Kapasitas user penuh!" << endl;
    } else {
        for (int i = 0; i < userCount; i++) {
            if (users[i]->getUsername() == username) {
                cout << "Gagal: Username sudah digunakan!" << endl;
                return;
            }
        }

        if (isAdmin) {
            users[userCount++] = new AdminUser(username, password);
        } else {
            users[userCount++] = new User(username, password);
        }
        cout << "Sukses: User " <<username << " berhasil terdaftar!" << endl;
    }
}

void Authenticator::login(const string &username, const string &password) {
    for (int i = 0; i < userCount; i++) {
        if (users[i]->getUsername() == username && users[i]->checkPassword(password)) {
            currentUser = users[i];
            cout << "Sukses: Login berhasil! Selamat datang, " << username << "." << endl;
            return;
        }
    }
    cout << "Gagal: Username atau password salah!" << endl;
}

void Authenticator::logout() {
    if (currentUser == nullptr) {
        cout << "Gagal: Tidak ada user yang sedang login!" << endl;
    } else {
        cout << "Sukses: User " << currentUser->getUsername() << " telah logout." << endl;
        currentUser = nullptr;
    }
}

void Authenticator::accessResource() const {
    if (currentUser == nullptr) {
        cout << "Akses ditolak! Silakan login terlebih dahulu." << endl;
    } else {
        cout << "Resource: "<< secretResource << endl;
    }
}

void Authenticator::setResource(const string &newResource) {
    if (currentUser == nullptr) {
        cout << "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu." << endl;
    } else if (!currentUser->isAdmin()) {
        cout << "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." << endl;
    } else {
        this->secretResource = newResource;
        cout << "Sukses: Resource telah diperbarui oleh "<< currentUser->getUsername() << "." << endl;
    }
}

Authenticator::~Authenticator() {
    for (int i = 0; i < userCount; i++) {
        delete users[i];
    }
}