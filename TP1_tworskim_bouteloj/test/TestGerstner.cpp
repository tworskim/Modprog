#include <stdio.h>
#include <iostream>
#include "../src/Dvector.h"
#include "../src/GerstnerWave.h"
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <assert.h>
#include <math.h>
using namespace std;

int main()
{
  Dvector d = Dvector(2,1);
  GerstnerWave gw = GerstnerWave(2.0, 3.3, d, 6.3);
  assert(gw.getamplitude() == 2.0);
  assert(gw.getphase() == 3.3);
  Dvector db =  Dvector(gw.getdirection());
  db.display(std::cout);
   assert(gw.getdirection()(1) == 1);
  GerstnerWave gw2 = GerstnerWave(gw);
  assert(gw2.getdirection()(1) == 1);
  std::cout << "OK2";
  assert(gw2.getamplitude() == 2);
  std::cout << "OK3";
  Dvector x = Dvector(2);
  x(0) = 2;
  x(1) = 2.5;
  double y = 2.0 * cos(4.5 + 3.3);
  std::cout << "y= ";
  std::cout << y;
  assert(gw(x, 0) == y);
  std::cout << "OK4";
}
