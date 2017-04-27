#ifndef PHILIPSWAVEMODEL
#define PHILIPSWAVEMODEL
using namespace std::literals;

class PhilipsWaveModel : public WaveModel{
  double Ph (Dvector k, double A, double L, Dvector w);
  double hbarre (Dvector k, double time, Dvector w);
};


#endif
