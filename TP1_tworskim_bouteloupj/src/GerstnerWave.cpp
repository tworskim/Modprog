#include <stdio.h>
#include <iostream>
#include "Dvector.h"
#include "Height.h"
#include "WaveModel.h"
#include "GerstnerWave.h"
#include <time.h>
#include <math.h>
#include <fstream>
#include <cstring>
using namespace std;

GerstnerWave::GerstnerWave()
{
  amplitude = 0;
  phase = 0;
  Dvector direction = Dvector(3,0);
  frequence = 0;
}
  
GerstnerWave::~GerstnerWave(){}

GerstnerWave::GerstnerWave(double a, double p, Dvector d, double f)
{
  amplitude = a;
  phase = p;
  Dvector direction = Dvector(d);
  frequence = f;
}

GerstnerWave::GerstnerWave(const GerstnerWave & gw){
  amplitude = gw.amplitude;
  phase = gw.phase;
  Dvector direction = Dvector(gw.direction);
  frequence = gw.frequence;
}

double GerstnerWave::operator() (Dvector d, doule time){
  return (amplitude * cos((direction(0) * d(0) + direction(1) * d(1)) - frequence * time + phase));
}
