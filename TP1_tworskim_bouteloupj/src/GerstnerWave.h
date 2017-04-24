#ifndef GERSTNERWAVE
#define GERSTNERWAVE

class GerstnerWave
{
  double amplitude;
  double phase;
  Dvector direction;
  double frequence;
  GerstnerWave();
  ~GerstnerWave();
  GerstnerWave(double a, double p, Dvector d, double f);
  GerstnerWave(const GerstnerWave & gw);
  double operator() (Dvector x, double time);
};

#endif
