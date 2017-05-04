#ifndef DVECTOR
#define DVECTOR

class Dvector
{
public :
  int dim;
  double *comp;

  Dvector();
  Dvector(int d);
  Dvector(int d, double db);
  Dvector(const Dvector & dv);
  Dvector(std::string str);
  ~Dvector();

  void display(std::ostream& str);
  void fillRandomly();
  int size();

  double &operator () (int i) ;
  double operator () (int i) const;

  Dvector & operator+= (double d);
  Dvector & operator-= (double d);
  Dvector & operator*= (double d);
  Dvector & operator/= (double d);

  Dvector & operator= (Dvector dvect);
  Dvector & operator+= (Dvector dvect);
  Dvector & operator-= (Dvector dvect);

  Dvector operator - ();
  Dvector operator - (Dvector V);
  Dvector operator + (Dvector V);
  double operator * (Dvector V);

  bool operator == (const Dvector &V);



};
Dvector operator+ (const double d, const Dvector dvect);
Dvector operator+ (const Dvector dvect, const double d);
Dvector operator- (const double d, const Dvector dvect);
Dvector operator- (const Dvector dvect, const double d);
Dvector operator* (const double d, const Dvector dvect);
Dvector operator* (const Dvector dvect, const double d);
Dvector operator/ (const Dvector dvect,const double d);

double operator* (const Dvector dvect, const Dvector dvect2);


std::ostream& operator << (std::ostream & Out,const Dvector & V);
std::istream& operator >> (std::istream & In,const Dvector & V);
#endif
