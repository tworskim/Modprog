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

double Height::getLx(){
  return(Lx);
}
double Height::getLy(){
  return(Ly);
}
int Height::getnx(){
  return(nx);
}
int Height::getny(){
  return(ny);
}

Height::Height(int m, int n, double lx, double ly, double db)
  {
    std::cout << "Constructeur taille et zeros\n";
    nx = m;
    ny = n;
    Lx= lx;
    Ly = ly;
    hgt = new double*[nx];
    for (int i=0; i<nx; i ++)
      hgt[i] = new double[ny];
    for (int i=0; i < nx; i ++)
      for (int j=0; j < ny; j ++)
	hgt[i][j] = db;
  }

void Height::display(){
  for (int i=0; i < nx; i ++){
    for (int j=0; j < ny; j ++){
	std::cout << hgt[i][j];
	std::cout << " ";
    }
    std::cout << "\n";
  }
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

double & Height::operator()(double x, double y){
  int x1 = (int) (x/Lx * nx);
  int y1 = (int) (y/Ly * ny);
  return hgt[x1][y1];
}

// int main(){
//   Height h = Height(10,10,5,5,12.2);
//   h.display();
//   std::cout << h(2,3);
//   h(2,3) = 4;
//   std::cout << h(2,3);
//   Height hp = Height(h);
//   std::cout << hp(2,3);
// }
