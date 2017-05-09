#include <stdio.h>
#include <iostream>
#include "Dvector.h"
#include "Height.h"
#include <time.h>
#include <math.h>
#include <fstream>
#include <cstring>
#include "WaveModel.h"
#include <list>
#include <complex>
#include <tr1/random>

using namespace std;


double Ph(Dvector k){
  double A = 3;
  double L = 2;
  std::complex<double> i(0,1);
  return(A * exp(-1/(sqrt(pow(k(0),2) + pow(k(1),2))*L)));
  
}

double hb (Dvector k){
  std::tr1::normal_distribution<> nd;
  std::tr1::mt19937 mt;
  double frequence = 3;
  double time = 2;
  std::complex<double> i(0,1);
  double a = 2 *((double) rand() - RAND_MAX)/((double) RAND_MAX);
  double b = 2 *((double) rand() - RAND_MAX)/((double) RAND_MAX);
  //std::cout << d;
  Dvector k(2,2);
  double ph =  Ph(k);
  std::complex<double> a1 = 1/(sqrt(2)) * (a * i  + b) * exp(i * frequence * time) * sqrt(ph);
   ph =  Ph(-k);
  std::complex<double> a2 = 1/(sqrt(2)) * (- a * i  + b) * exp(- i * frequence * time) * sqrt(ph);
  std::cout << a1 + a2;
  return 0;
}
int main(){
  return 0;
}
