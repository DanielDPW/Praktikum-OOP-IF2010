#include "Midfielder.hpp"

Midfielder::Midfielder() : Footballer(), assist(0), keyPasses(0) {
    this->playPosition = "midfielder";
}

Midfielder::~Midfielder() {}

Midfielder::Midfielder(const string& name, int birthYear, int assist, int keyPasses) : Footballer(name, birthYear, "midfielder", "Indonesia", 180, 70), assist(assist), keyPasses(keyPasses) {}

void Midfielder::setAssist(int assist) {
    this->assist = assist;
}

int Midfielder::getAssist() const {
    return assist;
}

void Midfielder::setKeyPasses(int keyPasses) {
    this->keyPasses = keyPasses;
}

int Midfielder::getKeyPasses() const {
    return keyPasses;
}

int Midfielder::playmakerRating() {
    return (assist * 3) + keyPasses;
}

int Midfielder::transferRate() {
    return (800000 * assist) + (30000 * keyPasses);
}

void Midfielder::displayInfo() {
    this->Footballer::displayInfo();
    cout << "Assists: " << assist << endl;
    cout << "Key Passes: " << keyPasses << endl;
    cout << "Playmaker Rating: " << playmakerRating() << endl;
}
