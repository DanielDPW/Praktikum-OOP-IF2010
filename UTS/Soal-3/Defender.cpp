#include "Defender.hpp"

Defender::Defender() : Footballer(), tackleSuccess(0), interceptions(0) {
    this->playPosition = "defender";
}

Defender::~Defender() {}

Defender::Defender(const string& name, int birthYear, int tackleSuccess, int interceptions) : Footballer(name, birthYear, "defender", "Indonesia", 180, 70), tackleSuccess(tackleSuccess), interceptions(interceptions) {}

void Defender::setTackleSuccess(int tackleSuccess) {
    this->tackleSuccess = tackleSuccess;
}

int Defender::getTackleSuccess() const {
    return tackleSuccess;
}

void Defender::setInterceptions(int interceptions) {
    this->interceptions = interceptions;
}

int Defender::getInterceptions() const {
    return interceptions;
}

int Defender::defensiveRating() const {
    return (tackleSuccess * 2) + interceptions;
}

int Defender::transferRate() {
    return (600000 * tackleSuccess) + (400000 * interceptions);
}

void Defender::displayInfo() {
    this->Footballer::displayInfo();
    cout << "Tackle Success: " << tackleSuccess << endl;
    cout << "Interceptions: " << interceptions << endl;
    cout << "Defensive Rating: " << defensiveRating() << endl;
}
