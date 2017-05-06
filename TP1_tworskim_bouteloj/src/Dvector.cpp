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

int Dvector::size(){
	return this->dim;
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

Dvector::Dvector(std::string str) {
	std::ifstream input(str.c_str());
	this->dim = 0;
	if (!input.is_open()) {
		return;
	}
	input.seekg(0);
	double temp;
	while (!input.eof()) {
	  std::cout << input;
	  std::cout << "\n";
	  input >> temp;
	  this->dim++;
	}
	input.seekg(0);
	comp = new double[this->dim];

	for (int i = 0; i < this->dim; i++) {
	  std::cout << input;
	  //input>>comp[i];
	}

}

void Dvector::fillRandomly()
{
  for (int i = 0; i < dim; i++)
    comp[i] = (double) rand()/(double) RAND_MAX;
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

double Dvector::operator () (int i) const {
	if (i>dim){std::cerr<<"ereur accesseur const";}
	return comp[i];
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



Dvector& Dvector::operator-= (double d)
{
  for (int i = 0; i < dim; i++)
    comp[i] = comp[i] - d;
  return *this;
}

Dvector Dvector::operator -() {
	Dvector result(*this);
	for (int i = 0; i < dim; i++) {
		result(i) = -result(i);
	}
	return result;
}
Dvector Dvector::operator - (Dvector V){
	if (V.size()!=dim){cerr<<"erreur addition";}
	Dvector result(V);
		for (int i = 0; i < V.size(); i++) {
			result(i) =  comp[i]-result(i);
		}
		return result;
}
Dvector Dvector::operator + (Dvector V){
	if (V.size()!=dim){cerr<<"erreur addition";}
	Dvector result(V);
	for (int i = 0; i < V.size(); i++) {
		result(i) = result(i) + comp[i];
	}
	return result;
}


Dvector operator- (const Dvector dvect, const double d)
{
  Dvector R(dvect);
  R-=d;
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


double Dvector::operator* (const Dvector V)
{
	float ret=0;
  for (int i = 0; i < dim; i++)
    ret += comp[i] * V(i);
  return ret;
}

Dvector& Dvector::operator/= (double d)
{
  if (d == 0.){
  std::cerr << "Division par zero";
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



std::ostream& operator <<(std::ostream & Out, const Dvector & V) {
	for (int i = 0; i < V.dim; i++) {
		Out << V(i) << "\n";
	}
	return Out;
}
std::istream& operator >> (std::istream & In,const Dvector & V){
	for (int i = 0; i < V.dim; i++) {
		In >> V(i);
	}
	return In;
}

bool Dvector::operator == (const Dvector &V){
	if(V.dim!=dim){
		return false;
	}
	for (int i=0; i<dim;i++){
		if(V(i)!=comp[i]){
			return false;
		}
	}
	return true;

}


// TEST
/*
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
*/
