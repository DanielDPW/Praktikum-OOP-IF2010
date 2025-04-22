#include "Striker.hpp"

Striker::Striker() : Footballer(), goalScore(0), shotsOnTarget(0) {
    this->playPosition = "striker";
}

Striker::~Striker() {}

Striker::Striker(const string& name, int birthYear, int goalScore, int shotsOnTarget) : Footballer(name, birthYear, "striker", "Indonesia", 180, 70), goalScore(goalScore), shotsOnTarget(shotsOnTarget) {}

void Striker::setGoalScore(int goalScore) {
    this->goalScore = goalScore;
}

int Striker::getGoalScore() const {
    return goalScore;
}

void Striker::setShotsOnTarget(int shotsOnTarget) {
    this->shotsOnTarget = shotsOnTarget;
}

int Striker::getShotsOnTarget() const {
    return shotsOnTarget;
}

float Striker::conversionRate() {
    if (shotsOnTarget == 0) {
        return 0.0;
    } else {
        return static_cast<float>(goalScore) / shotsOnTarget * 100;
    }
}

int Striker::transferRate() {
    return static_cast<int>((1000000 * goalScore) + (10000 * conversionRate()));
}

void Striker::displayInfo() {
    this->Footballer::displayInfo();
    cout << "Goals: " << goalScore << endl;
    cout << fixed << setprecision(2) << "Conversion Rate: " << conversionRate() << "%" << endl;
}
