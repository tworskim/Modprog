#ifndef WAVEMODEL
#define WAVEMODEL

class WaveModel
{
 private : 
  double direction;
  double alignement;
  double intensite;
  double longueuronde;
  double ajust;

 public :
  double getdirection();
  double getalignement();
  double getintensite();
  double getlongueuronde();
  double getajust();
  WaveModel();
  ~WaveModel();
  WaveModel(double d, double a, double i, double l, double aj);
  WaveModel(const WaveModel & wm);
  virtual double operator()(Dvector d, double time){};
  
};

#endif
