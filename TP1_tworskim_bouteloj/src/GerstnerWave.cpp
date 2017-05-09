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

double GerstnerWave::getamplitude(){
  return amplitude;
}
double GerstnerWave::getphase(){
   return phase;
}
Dvector GerstnerWave::getdirection(){
  return direction;
}
double GerstnerWave::getfrequence(){
  return frequence;
}

GerstnerWave::GerstnerWave()
{
  std::cout <<"Constructeur par défaut GW";
  amplitude = 0;
  phase = 0;
  Dvector direction = Dvector(2,0);
  frequence = 0;
}
  
GerstnerWave::~GerstnerWave(){
}

GerstnerWave::GerstnerWave(double a, double p, Dvector& d, double f)
{
  amplitude = a;
  phase = p;
  std::cout << "Const GW avec param";
  std::cout << d(0);
  std::cout << d(0);
  direction = Dvector(d);
  std::cout << direction(0);
  std::cout << direction(0);
  frequence = f;
  std::cout << "Fin Const GW avec param";
}

GerstnerWave::GerstnerWave(const GerstnerWave & gw){
  std::cout <<"Constructeur par copie GW";
  amplitude = gw.amplitude;
  phase = gw.phase;
  direction = Dvector(gw.direction);
  frequence = gw.frequence;
}

double GerstnerWave::operator() (Dvector x, double time){
  return (amplitude * cos((direction(0) * x(0) + direction(1) * x(1)) - frequence * time + phase));
}
