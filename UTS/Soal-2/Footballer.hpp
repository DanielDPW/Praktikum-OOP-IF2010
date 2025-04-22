#ifndef FOOTBALLER_HPP
#define FOOTBALLER_HPP

#include <iostream>
#include <iomanip>

using namespace std;

#define CURRENT_YEAR 2025

class Footballer
{
protected:
  string name;
  string playPosition;
  int birthYear;

  string nationality;
  int height;
  int weight;

public:
  Footballer();
  // Default cosntructor set nilai attribut sebagai berikut:
  // name = "noname"; birthYear = 2000; playPosition = "none";
  // nationality = "Indonesia"; height = 180, weight = 70
  // ...

  Footballer(const string& name, int birthYear, const string& playPosition, const string& nationality, int height, int weight);
  // User-defined constructor:
  // set nilai atribut berdasarkan nilai parameter masukan
  // dengan urutan: name, birthYear, playPosition, nationality, height, weight
  // ...

  Footballer(const Footballer &other);
  // Copy constructor
  // ...

  ~Footballer();
  // Destructor
  // ...

  Footballer &operator=(const Footballer &other);
  // Operator assignment
  // ...

  void setName(const string &name);

  string getName() const;
  // Getter dan setter name
  // setName(...)
  // getName()

  void setPlayPosition(const string &playPosition);

  string getPlayPosition() const;
  // Getter dan setter playPosition
  // setPlayPosition(...)
  // getPlayPosition()

  void setNationality(const string &nationality);

  string getNationality() const;
  // Getter dan setter nationality
  // setNationality(...)
  // getNationality()

  void setHeight(int height);

  int getHeight() const;

  void setWeight(int weight);

  int getWeight() const;
  // Getter dan setter height and weight
  // setHeight(...)
  // getHeight()
  // setWeight(...)
  // getWeight()

  int getAge() const;
  // gunakan CURRENT_YEAR untuk menghitung umur
  // getAge()

  float getBMI() const;
  // gunakan height and weight untuk menghitung BMI
  // BMI = weight(kg) / (height(m))²
  // getBMI()

  string getCategory() const;
  // gunakan BMI untuk mendapat category
  // BMI < 18.5         -> Underweight
  // 18.5 ≤ BMI < 25.0  -> Normal
  // 25.0 ≤ BMI < 30.0  -> Overweight
  // BMI ≥ 30.0         -> Obese
  // getCategory() -> string

  virtual void displayInfo();
  // Mencetak informasi footballer dengan format sebagai berikut:
  // Name: {name}
  // Age: {hasil pemanggilan getAge()}
  // Position: {playPosition}
  // Nationality: {nationality}
  // BMI: {<BMI> (<getCategory()>)}, BMI 2 angka di belakang koma, HINT: "cout << fixed << setprecision(2);"
  // Transfer Rate: {hasil pemanggilan transferRate()}
  // displayInfo()

  virtual int transferRate() = 0;
  // Melakukan kalkulasi nilai transfer sesuai umur, playPosition, dan getCategory()
  // transferRate() akan diimplementasikan oleh kelas anak Footballer
  // yang ada di soal berikutnya. Gunakan tipe data integer.
  // ... transferRate()
};

#endif