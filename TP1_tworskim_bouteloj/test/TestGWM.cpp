#include <stdio.h>
#include <iostream>
#include "../src/Dvector.h"
#include "../src/GerstnerWave.h"
#include "../src/WaveModel.h"
#include "../src/GerstnerWaveModel.h"
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <assert.h>
#include <math.h>
using namespace std;

int main()
{
  GerstnerWaveModel gwm = GerstnerWaveModel();
  Dvector d = Dvector(2,1);
  GerstnerWave gw = GerstnerWave(2.0, 3.3, d, 6.3);
  Dvector d2 = Dvector(2);
  d2 = 3*(d + 2);
  GerstnerWave gw2 = GerstnerWave(2.0, 3.3, d2, 6.3);
  gwm.add(gw);
  gwm.add(gw2);
  assert(gw(d2,5) + gw2(d2,5) == gwm(d2,5));

   GerstnerWaveModel gwm2(3.3, 2.2, 1.1, 6.66, 4.44);
   assert(gwm2.getintensite() == 1.1);
   assert(gwm2.getajust() == 4.44);
}
