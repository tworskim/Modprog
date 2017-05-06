#ifndef GERSTNERWAVEMODEL
#define GERSTNERWAVEMODEL

#include <list>
typedef std::list<GerstnerWave> GerstnerWaves;

class GerstnerWaveModel : public WaveModel{
 private :
  
  GerstnerWaves gws;
 public :
  virtual double operator() (Dvector d, double time);
  void add(GerstnerWave gw);
  GerstnerWaveModel();
  GerstnerWaveModel(double d, double a, double i, double l, double aj);
  ~GerstnerWaveModel();
};

#endif
