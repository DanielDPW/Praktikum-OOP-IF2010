#ifndef GOALKEEPER_HPP
#define GOALKEEPER_HPP

#include "Footballer.hpp"

class Goalkeeper : public Footballer
{
protected:
  int cleanSheets;
  int saves;
  int totalShotsOnGoal;
  // atribut tambahan cleanSheets (jumlah pertandingan tanpa kebobolan),
  // saves (jumlah penyelamatan), dan totalShotsOnGoal (jumlah total tendangan ke gawang)
  // ...

public:
  Goalkeeper();
  // Default constructor
  // set atribut Footballer dengan nilai default,
  // set cleanSheets, saves, totalShotsOnGoal ke 0, playPosition ke "goalkeeper"
  // ...

  ~Goalkeeper();

  Goalkeeper(const string& name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal);
  // User-defined constructor
  // parameter: string name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal
  // set atribut dengan nilai parameter, playPosition tetap "goalkeeper"
  // nationality, height, dan weight gunakan nilai default superclass
  // ...

  void setCleanSheets(int cleanSheets);

  int getCleanSheets() const;
  // Getter dan Setter untuk cleanSheets
  // setCleanSheets(...)
  // getCleanSheets()

  void setSaves(int saves);

  int getSaves() const;
  // Getter dan Setter untuk saves
  // setSaves(...)
  // getSaves()

  void setTotalShotsOnGoal(int totalShotsOnGoal);

  int getTotalShotsOnGoal() const;
  // Getter dan Setter untuk totalShotsOnGoal
  // setTotalShotsOnGoal(...)
  // getTotalShotsOnGoal()

  float savePercentage();
  // Method tambahan: savePercentage
  // rumus: (saves / totalShotsOnGoal) * 100
  // return dalam bentuk float
  // ...

  int transferRate();
  // Override transferRate:
  // rumus: (700.000 * cleanSheets) + (50.000 * saves)
  // hasil berupa int
  // ...

  void displayInfo();
  // Override displayInfo():
  // Cetak info Footballer + atribut tambahan goalkeeper (cleanSheets, saves, savePercentage)
  // Format:
  // Clean Sheets: <cleanSheets>
  // Saves: <saves>
  // Save Percentage: <savePercentage>%

  // Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
  // Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
  // ...
};

#endif
