#ifndef WAVEMODEL
#define WAVEMODEL

class WaveModel
{
 protected :
  double direction;
  double alignement;
  double intensite;
  double longueuronde;
  double ajust;

 public :
  WaveModel();
  ~WaveModel();
  WaveModel(double d, double a, double i, double l, double aj);
  WaveModel(const WaveModel & wm);
};

#endif
