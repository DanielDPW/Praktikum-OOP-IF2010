#ifndef STRIKER_HPP
#define STRIKER_HPP

#include "Footballer.hpp"

class Striker : public Footballer
{
protected:
  int goalScore;
  int shotsOnTarget;
  // atribut tambahan goalScore (jumlah gol yang dicetak striker)
  // dan shotsOnTarget (jumlah tendangan tepat sasaran)
  // ...

public:
  Striker();
  // Default constructor
  // set atribut Footballer dengan nilai default,
  // set goalScore dan shotsOnTarget ke 0, dan playPosition ke "striker"
  // ...
  ~Striker();

  Striker(const string& name, int birthYear, int goalScore, int shotsOnTarget);
  // User-defined constructor
  // parameter: string name, int birthYear, int goalScore, int shotsOnTarget
  // set atribut dengan nilai parameter, playPosition tetap "striker"
  // nationality, height, dan weight gunakan nilai default superclass
  // ...

  void setGoalScore(int goalScore);

  int getGoalScore() const;
  // Getter dan Setter untuk goalScore
  // setGoalScore(...)
  // getGoalScore()

  void setShotsOnTarget(int shotsOnTarget);

  int getShotsOnTarget() const;
  // Getter dan Setter untuk shotsOnTarget
  // setShotsOnTarget(...)
  // getShotsOnTarget()

  float conversionRate();
  // Method tambahan: menghitung conversion rate dalam persen
  // conversionRate() = (goalScore / shotsOnTarget) * 100
  // return dalam bentuk float
  // Hint: Gunakan static_cast<float> untuk mengonversi int ke float
  // ...

  int transferRate();
  // Override transferRate:
  // rumus: 1.000.000 * goalScore + 10.000 * conversionRate()
  // hasil berupa int
  // ...

  void displayInfo();
  // Override displayInfo():
  // Cetak info Footballer + atribut tambahan striker (goalScore, conversionRate)
  // Format:
  // Goals: <goalScore>
  // Conversion Rate: <conversionRate>%

  // Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
  // Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
  // ...
};

#endif
