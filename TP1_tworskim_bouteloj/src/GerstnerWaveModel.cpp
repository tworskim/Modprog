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

using namespace std;

GerstnerWaveModel::GerstnerWaveModel(){}
GerstnerWaveModel::~GerstnerWaveModel(){}
GerstnerWaveModel::operator() (Dvector d, double time){
  double ret = 0;
  for(const_iterator = GerstnerWaves.begin(), const_iterator != GerstnerWaves.end(), const_iterator++){
    ret += *const_iterator(d, time);
  }
  return ret;
}
int main(){};
}
