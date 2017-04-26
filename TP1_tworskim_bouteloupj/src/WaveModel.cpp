#include <stdio.h>
#include <iostream>
#include "Dvector.h"
#include "Height.h"
#include "WaveModel.h"
#include <time.h>
#include <fstream>
#include <cstring>
using namespace std;


WaveModel::WaveModel(){
  direction = 0;
  alignement = 0;
  intensite = 0;
  longueuronde = 0;
  ajust = 0;
}
WaveModel::WaveModel(double d, double a, double i, double l, double aj){
  direction = d;
  alignement = a;
  intensite = i;
  longueuronde = l;
  ajust = aj;
}
WaveModel::WaveModel(const WaveModel & wm){
  direction = wm.direction;
  alignement = wm.alignement;
  intensite = wm.intensite;
  longueuronde = wm.longueuronde;
  ajust = wm.ajust;
}

WaveModel::~WaveModel(){}

//int main(){}
