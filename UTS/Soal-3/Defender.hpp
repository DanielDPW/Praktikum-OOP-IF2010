#ifndef DEFENDER_HPP
#define DEFENDER_HPP

#include "Footballer.hpp"

class Defender : public Footballer
{
protected:
  int tackleSuccess;
  int interceptions;
  // atribut tambahan tackleSuccess (jumlah tackle sukses)
  // dan interceptions (jumlah intercept)
  // ...

public:
  Defender();
  // Default constructor
  // set atribut Footballer dengan nilai default,
  // set tackleSuccess dan interceptions ke 0, dan playPosition ke "defender"
  // ...

  ~Defender();
  
  Defender(const string& name, int birthYear, int tackleSuccess, int interceptions);
  // User-defined constructor
  // parameter: string name, int birthYear, int tackleSuccess, int interceptions
  // set atribut dengan nilai parameter, playPosition tetap "defender"
  // nationality, height, dan weight gunakan nilai default superclass
  // ...

  void setTackleSuccess(int tackleSuccess);

  int getTackleSuccess() const;
  // Getter dan Setter untuk tackleSuccess
  // setTackleSuccess(...)
  // getTackleSuccess()

  void setInterceptions(int interceptions);

  int getInterceptions() const;
  // Getter dan Setter untuk interceptions
  // setInterceptions(...)
  // getInterceptions()

  int defensiveRating() const;
  // Method tambahan: defensiveRating
  // rumus: (tackleSuccess * 2) + interceptions
  // return dalam bentuk int
  // ...

  int transferRate();
  // Override transferRate:
  // rumus: (600.000 * tackleSuccess) + (400.000 * interceptions)
  // hasil berupa int
  // ...

  void displayInfo();
  // Override displayInfo():
  // Cetak info Footballer + atribut tambahan defender (tackleSuccess, interceptions, defensiveRating)
  // Format:
  // Tackle Success: <tackleSuccess>
  // Interceptions: <interceptions>
  // Defensive Rating: <defensiveRating>
  // ...
};

#endif
