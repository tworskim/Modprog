#include <stdio.h>
#include <iostream>
#include "Dvector.h"
#include "Height.h"
#include <time.h>
//#include <stdlib.h>
#include <fstream>
#include <cstring>
using namespace std;





Height::~Height()
{
  std::cout << "Destructeur\n";
  for (int i = 0; i < nx; i++)
      delete[] hgt[i];
   delete[] hgt;
}

Height::Height()
  {
    std::cout << "Constructeur par défaut\n";
    nx = 0;
    ny = 0;
    Lx = 0;
    Ly = 0;
  }

Height::Height(int m, int n, double db)
  {
    std::cout << "Constructeur taille et zeros\n";
    nx = m;
    ny = n;
    hgt = new double*[nx];
    for (int i=0; i<nx; i ++)
      hgt[i] = new double[ny];
    for (int i=0; i < nx; i ++)
      for (int j=0; j < ny; j ++)
	hgt[i][j] = db;
  }

Height::Height(const Height & height)
{
  std::cout << "Constructeur par copie\n";
  nx = height.nx;
  ny = height.ny;
  Lx = height.Lx;
  Ly = height.Ly;
  if (nx == 0 || ny == 0)
    return;
  hgt = new double*[nx];
  for (int i = 0; i < nx; i ++)
    hgt[i] = new double[ny];
  for (int i = 0; i < nx; i ++)
    for (int j = 0; j<ny; j ++)
      hgt[i][j] = height.hgt[i][j];
}
//int main(){}
