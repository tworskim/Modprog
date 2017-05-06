#include <stdio.h>
#include <iostream>
#include "Dvector.h"
#include "Height.h"
#include "GerstnerWave.h"
#include <time.h>
#include <math.h>
#include <fstream>
#include <cstring>
#include "WaveModel.h"
#include "GerstnerWaveModel.h"
#include <list>
using namespace std;

GerstnerWaveModel::GerstnerWaveModel() : WaveModel(){}
GerstnerWaveModel::GerstnerWaveModel(double d, double a, double i, double l, double aj) : WaveModel(d, a, i, l, aj){}
GerstnerWaveModel::~GerstnerWaveModel(){}
double  GerstnerWaveModel::operator() (Dvector d, double time){
  double ret = 0;
  for(GerstnerWaves::iterator it = gws.begin(); it != gws.end(); it++){
    ret += (*it)(d, time);
  }
  return ret;
}

void GerstnerWaveModel::add(GerstnerWave gw){
  GerstnerWaves::iterator it = gws.begin();
  gws.insert(it,gw);
}

//int main(){}
