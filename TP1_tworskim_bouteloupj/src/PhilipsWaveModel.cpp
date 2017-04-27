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

double PhilipsWaveModel::Ph(Dvector k, double A, double L, Dvector w)
{
  normek2 = pow(k(0), 2) + pow(k(1), 2);
  return(A * exp((-1/(normek2*L*L))/normek2);
}

double PhilipsWaveModel::hbarre (Dvector k, double time, Dvector w){
  
}
