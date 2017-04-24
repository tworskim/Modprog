#include <stdio.h>
#include <iostream>
#include "Dvector.h"
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
using namespace std;



void Dvector::display(std::ostream& str)
{
  if (dim == 0)
    return;
  for (int i = 0; i < dim; i++)
    str << comp[i] << "\n";
}

Dvector::~Dvector()
{
  std::cout << "Destructeur\n";
  delete [] comp;
}

Dvector::Dvector()
  {
    std::cout << "Constructeur par défaut\n";
    dim=0;
  }

Dvector::Dvector(int d)
  {
    std::cout << "Constructeur taille et zeros\n";
    dim=d;
    comp = new double[dim];
    for (int i=0; i<dim; i ++)
      comp[i] = 0;
  }

Dvector::Dvector(int d, double db)
  {
    std::cout << "Constructeur taille et contenu\n";
    dim=d;
    comp = new double[dim];
    for (int i=0; i<dim; i ++)
      comp[i] = db;
  }

Dvector::Dvector(const Dvector & dv)
{
  std::cout << "Constructeur par copie\n";
  dim = dv.dim;
  if (dim == 0)
    return;
  comp = new double[dim];
  for (int i = 0; i < dim; i++)
    comp[i] = dv.comp[i];
}

Dvector::Dvector(std::string str)
{
  std::cout << "Constructeur lecture fichier\n";
  ifstream fichier("text.txt");
  std::string ligne;
  int dimt = 0;
  //double d = 0; 
  while(getline(fichier, ligne)){
    dimt += 1;
  }
  dim = dimt;
  if (dim == 0)
    return;
  comp = new double[dim];
  fichier.open("text.txt", ios::in);
  std::string::size_type sz;
  for(int i = 0; i < dim; i ++){
    getline(fichier, ligne);
    //comp[i] = stod(ligne, &sz);
    printf("%f\n", comp[i]);
  }
  fichier.close();
}

void Dvector::fillRandomly()
{
  for (int i = 0; i < dim; i++)
    comp[i] = (double) rand()/(double) RAND_MAX;
}

int Dvector::size()
{
  return dim;
}


double& Dvector::operator() (int i)
{
  if (i < 0 || i>= dim)
    {
      cerr << "Erreur Indice Tableau";
    }
  double& compi = comp[i];
  return (compi);
}

Dvector& Dvector::operator+= (double d)
{
  for (int i = 0; i < dim; i++)
    comp[i] = d + comp[i];
  return *this;
}

Dvector operator+ (const double d, const Dvector dvect)
{
  Dvector R(dvect);
  R += d;
  return (R);
}

Dvector operator+ (const Dvector dvect, const double d)
{
  Dvector R(dvect);
  R += d;
  return (R);
}

Dvector & Dvector::operator+= (const Dvector dvect){
  for (int i = 0; i < dim; i++)
    comp[i] = dvect.comp[i] + comp[i];
  return *this;
}

Dvector operator+ (const Dvector dvect, const Dvector dvect2){
  Dvector R(dvect);
  R += dvect2;
  return (R);
}

Dvector& Dvector::operator-= (double d)
{
  for (int i = 0; i < dim; i++)
    comp[i] = comp[i] - d;
  return *this;
}

Dvector operator- (const Dvector dvect)
{
  Dvector R(dvect);
  for (int i = 0; i < dvect.dim; i++)
    R.comp[i] = - R.comp[i];
  return R;
}

Dvector operator- (const double d, const Dvector dvect)
{
  Dvector R(dvect);
  R -= d;
  return (R);
}

Dvector operator- (const Dvector dvect, const double d)
{
  Dvector R(dvect);
  for (int i = 0; i < dvect.dim; i++)
    R.comp[i] = - R.comp[i];
  R+=d;
  return R;
}

Dvector & Dvector::operator-= (const Dvector dvect){
  for (int i = 0; i < dim; i++)
    comp[i] = dvect.comp[i] - comp[i];
  return *this;
}

Dvector operator- (const Dvector dvect, const Dvector dvect2){
  Dvector R(dvect);
  R -= dvect2;
  return (R);
}

Dvector& Dvector::operator*= (double d)
{
  for (int i = 0; i < dim; i++)
    comp[i] = d * comp[i];
  return *this;
}

Dvector operator* (const double d, const Dvector dvect)
{
  Dvector R = Dvector(dvect);
  R *= d;
  return (R);
}

Dvector operator* (const Dvector dvect, const double d)
{
  Dvector R(dvect);
  R *= d;
  return (R);
}

Dvector& Dvector::operator/= (double d)
{
  if (d == 0.){
  std:cerr << "Division par zero";
  }
  else{
    for (int i = 0; i < dim; i++)
      comp[i] = comp[i]/d;
  }
  return *this;
}

Dvector operator/ (const Dvector dvect, const double d)
{
  Dvector R(dvect);
  R /= d;
  return (R);
}


Dvector & Dvector::operator= (Dvector dvect){
  std::cout << "Affectation";
  dim = dvect.dim;
  //comp = new double[dim];
  memcpy(comp, dvect.comp, dim * sizeof(double));
  return (*this);
}


// TEST
int main()
{
  // Dvector dv = Dvector(4);
  // dv.fillRandomly();
  // dv.display(std::cout);
  // Dvector dv2 = Dvector(dv);
  // std::cout << "||||||||||";
  // dv2 = dv*2;
  // dv2.display(std::cout);
  // dv2 = dv2/2;
  // dv2.display(std::cout);
  // int n = dv.size();
  // printf("%i", n);
  Dvector dv2 = Dvector("text.txt");
  dv2.display(std::cout);
}
