#include <stdio.h>
#include <iostream>
#include "Dvector.h"
#include "Cvector.h"
#include "Height.h"
#include <time.h>
#include <math.h>
#include <assert.h>
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

std::complex<double> hb (Dvector k){
  std::tr1::normal_distribution<> nd;
  std::tr1::mt19937 mt;
  double frequence = 3;
  double time = 2;
  std::complex<double> i(0,1);
  double a = 2 *((double) rand() - RAND_MAX)/((double) RAND_MAX);
  double b = 2 *((double) rand() - RAND_MAX)/((double) RAND_MAX);
  //std::cout << nd(mt);
  double ph =  Ph(k);
  std::complex<double> a1 = 1/(sqrt(2)) * (a * i  + b) * exp(i * frequence * time) * sqrt(ph);
   ph =  Ph(-k);
  std::complex<double> a2 = 1/(sqrt(2)) * (- a * i  + b) * exp(- i * frequence * time) * sqrt(ph);
  std::cout << a1 + a2;
  return(a1 + a2);
}


Cvector<std::complex<double> > fft (Cvector<std::complex<double> > x){
  std::complex<double>  i(0,1);
  int n = x.size();
  if (n <= 1){
    return x;
  }
  int np = n/2;
  Cvector<std::complex<double> > a(np,0);
  Cvector<std::complex<double> > b(np,0);
  for (int j = 0; j < np; j++){
    a(j) = x(2*j);
    b(j) = x(2*j+1);
  }
  a = fft(a);
  b = fft(b);
  std::complex<double> t(0,0);
  for (int j = 0; j < np; j++){
    t = b(j) * exp(- 6.28 * i * ((double) j)/((double) n));
    x(j) = a(j) + t;
    x(j + np) = a(j) - t;
  }
  std::cout << "RESULT : \n";
  x.display(std::cout);
  std::cout << "FINRESULT : \n";
  return (x);
}

int main(){
  Cvector<std::complex<double> > x(4,2);
  Cvector<std::complex<double> > y(4,2);
  std::complex<double>  i(0,1);
  x(1) = 5.;
  std::cout << "x : \n";
  x.display(std::cout);
  y  = fft(x);
  std::cout << "y : \n";
  y.display(std::cout);
}
