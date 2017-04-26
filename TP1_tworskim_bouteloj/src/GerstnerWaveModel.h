#ifndef GERSTNERWAVEMODEL
#define GERSTNERWAVEMODEL

#include <list>

class GerstnerWaveModel : public WaveModel{
 private :
  std::list<GerstnerWave>::const_iterator GerstnerWaves;
 public :
  GerstnerWaveModel();
  ~GerstnerWaveModel();
};

#endif
