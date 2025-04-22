#include "Goalkeeper.hpp"

Goalkeeper::Goalkeeper() : Footballer(), cleanSheets(0), saves(0), totalShotsOnGoal(0) {
    this->playPosition = "goalkeeper";
}

Goalkeeper::~Goalkeeper() {}

Goalkeeper::Goalkeeper(const string& name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal) : Footballer(name, birthYear, "goalkeeper", "Indonesia", 180, 70), cleanSheets(cleanSheets), saves(saves), totalShotsOnGoal(totalShotsOnGoal) {}

void Goalkeeper::setCleanSheets(int cleanSheets) {
    this->cleanSheets = cleanSheets;
}

int Goalkeeper::getCleanSheets() const {
    return cleanSheets;
}

void Goalkeeper::setSaves(int saves) {
    this->saves = saves;
}

int Goalkeeper::getSaves() const {
    return saves;
}

void Goalkeeper::setTotalShotsOnGoal(int totalShotsOnGoal) {
    this->totalShotsOnGoal = totalShotsOnGoal;
}

int Goalkeeper::getTotalShotsOnGoal() const {
    return totalShotsOnGoal;
}

float Goalkeeper::savePercentage() {
    if (totalShotsOnGoal == 0) {
        return 0.0;
    } else {
        return static_cast<float>(saves) / totalShotsOnGoal * 100;
    }
}

int Goalkeeper::transferRate() {
    return (700000 * cleanSheets) + (50000 * saves);
}

void Goalkeeper::displayInfo() {
    this->Footballer::displayInfo();
    cout << "Clean Sheets: " << cleanSheets << endl;
    cout << "Saves: " << saves << endl;
    cout << fixed << setprecision(2) << "Save Percentage: " << savePercentage() << "%" << endl;
}
