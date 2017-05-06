
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
  Dvector d = Dvector(8);
  assert(d.size() == 8);
  for (int i = 0; i < 8; i++){
    assert(d(i) == 0);
  }      
  std::cout << "constructeur taille OK \n";
  Dvector dv = Dvector(4,5);
  for (int i = 0; i < 4; i++){
    assert(dv(i) == 5);
  }
  std::cout << "constructeur taille et valeur OK\n";
  Dvector dv2 = Dvector(dv);
  for (int i = 0; i < 4; i++){
    assert(dv2(i) == 5);
  }
  std::cout << "constructeur recopie OK\n";


  Dvector dv3 = Dvector("text");
  std::cout << dv3.size();
  dv3.display(std::cout);
  assert(dv3(0) == 2);
  assert(dv3(1) == 5.3);
  assert(dv3(2) == 6.7);
  assert(dv3(3) == 1.1);
  assert(dv3.size() == 4);

  std::cout << "constructeur par lecture fichier OK\n";
}


