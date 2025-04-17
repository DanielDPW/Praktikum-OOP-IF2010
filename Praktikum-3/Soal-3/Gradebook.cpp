#include "Gradebook.hpp"

void Gradebook::addOrUpdateStudent(const string& studentName, double grade) {
    studentGrades[studentName] = grade;
}

bool Gradebook::removeStudent(const string& studentName) {
    if (studentExists(studentName)) {
        studentGrades.erase(studentGrades.find(studentName));
        return true;
    }
    return false;
}

bool Gradebook::getGrade(const string &studentName, double &grade) const {
    if (studentExists(studentName)) {
        grade = studentGrades.at(studentName);
        return true;
    }
    return false;
}

bool Gradebook::studentExists(const string& studentName) const {
    return studentGrades.find(studentName) != studentGrades.end();
}

void Gradebook::printGrades() const {
    if (studentGrades.empty()) {
        cout << "Gradebook kosong" << endl;
        return;
    }

    int i = 1;
    for (auto iter = studentGrades.begin(); iter != studentGrades.end(); iter++) {
        cout << i << ". " << iter->first << ": " << iter->second << endl; 
        i++;
    }
}

bool compare(pair<string, double> a, pair<string, double> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

void Gradebook::printGradesRank() const {
    if (studentGrades.empty()) {
        cout << "Gradebook kosong" << endl;
        return;
    }
    vector<pair<string, double>> temp;
    for (auto iter = studentGrades.begin(); iter != studentGrades.end(); iter++) {
        temp.push_back(*iter);
    }
    sort(temp.begin(), temp.end(), compare);

    for (int i = 0; i < temp.size(); i++) {
        cout << i + 1 << ". " << temp[i].first << ": " << temp[i].second << endl;
    }
}

vector<string> Gradebook::getStudentsWithGradeAbove(double threshold) const {
    vector<string> temp;
    for (auto iter = studentGrades.begin(); iter != studentGrades.end(); iter++) {
        if (iter->second > threshold) {
            temp.push_back(iter->first);
        }
    }
    sort(temp.begin(), temp.end());
    return temp;
}

double Gradebook::getAverageGrade() const {
    if (studentGrades.empty()) {
        return 0;
    } else {
        double sum = 0;
        int count = 0;
        for (auto iter = studentGrades.begin(); iter != studentGrades.end(); iter++) {
            sum += iter->second;
            count++;
        }
        double res = sum / count;
        return res;
    }
}

size_t Gradebook::getNumberOfStudents() const {
    return studentGrades.size();
}