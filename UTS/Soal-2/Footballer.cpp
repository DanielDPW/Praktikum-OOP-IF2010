#include "Footballer.hpp"

Footballer::Footballer() : name("noname"), birthYear(2000), playPosition("none"), nationality("Indonesia"), height(180), weight(70) {}

Footballer::Footballer(const string& name, int birthYear, const string& playPosition, const string& nationality, int height, int weight) : name(name), birthYear(birthYear), playPosition(playPosition), nationality(nationality), height(height), weight(weight) {}

Footballer::Footballer(const Footballer &other) {
    if (this != &other) {
        this->name = other.name;
        this->birthYear = other.birthYear;
        this->playPosition = other.playPosition;
        this->nationality = other.nationality;
        this->height = other.height;
        this->weight = other.weight;
    }
}

Footballer::~Footballer() {}

Footballer &Footballer::operator=(const Footballer &other) {
    if (this != &other) {
        this->name = other.name;
        this->birthYear = other.birthYear;
        this->playPosition = other.playPosition;
        this->nationality = other.nationality;
        this->height = other.height;
        this->weight = other.weight;
    }
    return *this;
}

void Footballer::setName(const string &name) {
    this->name = name;
}

string Footballer::getName() const {
    return name;
}

void Footballer::setPlayPosition(const string &playPosition) {
    this->playPosition = playPosition;
}

string Footballer::getPlayPosition() const {
    return playPosition;
}

void Footballer::setNationality(const string &nationality) {
    this->nationality = nationality;
}

string Footballer::getNationality() const {
    return nationality;
}

void Footballer::setHeight(int height) {
    this->height = height;
}

int Footballer::getHeight() const {
    return height;
}

void Footballer::setWeight(int weight) {
    this->weight = weight;
}

int Footballer::getWeight() const {
    return weight;
}

int Footballer::getAge() const {
    return CURRENT_YEAR - birthYear;
}

float Footballer::getBMI() const {
    return weight / (0.01 * height * 0.01 * height);
}

string Footballer::getCategory() const {
    float bmi = getBMI();
    if (bmi < 18.5) {
        return "Underweight";
    } else if (bmi < 25) {
        return "Normal";
    } else if (bmi < 30) {
        return "Overweight";
    } else {
        return "Obese";
    }
}

void Footballer::displayInfo()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Position: " << playPosition << endl;
    cout << "Nationality: " << nationality << endl;
    cout << fixed << setprecision(2) << "BMI: " << getBMI() << " (" << getCategory() << ")" << endl;
    cout << "Transfer Rate: " << transferRate() << endl;
}
