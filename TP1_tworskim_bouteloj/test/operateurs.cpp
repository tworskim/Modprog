#include <stdio.h>
#include <iostream>
#include "../src/Dvector.h"
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <assert.h>
using namespace std;

int main()
{
  Dvector dv = Dvector(4,5);
  dv += 2;
  assert(dv(1) == 7);
  dv *= 0.5;
  assert(dv(0) == 3.5);
  dv -= 2;
  assert(dv(3) == 1.5);
  dv /= 3;
  assert(dv(2) == 0.5);
  Dvector dv2 = Dvector(4,5);
  dv = dv2;
  assert(dv(1) == 5);
  dv += dv2;
  assert(dv(0) == 10);
  dv = dv2 - 2 + dv/2 - 4 * 3 + (4./5.) * dv2;
  std::cout << dv(3);
  assert(dv(3) == 0);  
}
