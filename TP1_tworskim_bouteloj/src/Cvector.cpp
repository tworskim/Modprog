#include <stdio.h>
#include <iostream>
#include "Cvector.h"
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
using namespace std;


template <class T>
void Cvector<T>::display(std::ostream& str)
{
  if (dim == 0)
    return;
  for (int i = 0; i < dim; i++)
    str << comp[i] << "\n";
}
template <class T>
int Cvector<T>::size(){
	return this->dim;
}
template <class T>
Cvector<T>::~Cvector()
{
  std::cout << "Destructeur\n";
  delete [] comp;
}
template <class T>
Cvector<T>::Cvector()
  {
    std::cout << "Constructeur par défaut\n";
    dim=2;
    comp = new T[dim];
    for (int i=0; i<dim; i ++)
      comp[i] = 0;
  }
template <class T>
Cvector<T>::Cvector(int d)
  {
    std::cout << "Constructeur taille et zeros\n";
    dim=d;
    comp = new T[dim];
    for (int i=0; i<dim; i ++)
      comp[i] = 0;
  }
template <class T>
Cvector<T>::Cvector(int d, T db)
  {
    std::cout << "Constructeur taille et contenu\n";
    dim=d;
    comp = new T[dim];
    for (int i=0; i<dim; i ++)
      comp[i] = db;
  }
template <class T>
Cvector<T>::Cvector(const Cvector<T> & dv)
{
  std::cout << "Constructeur par copie\n";
  dim = dv.dim;
  if (dim == 0)
    return;
  comp = new T[dim];
  for (int i = 0; i < dim; i++){
    comp[i] = dv.comp[i];
    std::cout << "\n";
    std::cout <<dv.comp[i];
    std::cout << "\n";  
  }
  
}
template <class T>
Cvector<T>::Cvector(std::string str) {
	std::ifstream input(str.c_str());
	this->dim = 0;
	if (!input.is_open()) {
		return;
	}
	input.seekg(0);
	T temp;
	while (!input.eof()) {
	  input >> temp;
	  this->dim++;
	}
	input.seekg(0);
	comp = new T[this->dim];

	for (int i = 0; i < this->dim; i++) {
	  input>>comp[i];
	}

}
template <class T>
void Cvector<T>::fillRandomly()
{
  for (int i = 0; i < dim; i++)
    comp[i] = (T) rand()/(T) RAND_MAX;
}

template <class T>
T& Cvector<T>::operator() (int i)
{
  if (i < 0 || i>= dim)
    {
      cerr << "Erreur Indice Tableau";
    }
  T& compi = comp[i];
  return (compi);
}
template <class T>
T Cvector<T>::operator () (int i) const {
	if (i>dim){std::cerr<<"erreur accesseur const";}
	return comp[i];
}

Cvector<T>& Cvector<T>::operator+= (T d)
{
  for (int i = 0; i < dim; i++)
    comp[i] = d + comp[i];
  return *this;
}
template <class T>
Cvector<T> operator+ (const T d, const Cvector<T> dvect)
{
  Cvector<T> R(dvect);
  R += d;
  return (R);
}
template <class T>
Cvector<T> operator+ (const Cvector<T> dvect, const T d)
{
  Cvector<T> R(dvect);
  R += d;
  return (R);
}
template <class T>
Cvector<T> & Cvector<T>::operator+= (const Cvector<T> dvect){
  for (int i = 0; i < dim; i++)
    comp[i] = dvect.comp[i] + comp[i];
  return *this;
}


template <class T>
Cvector<T>& Cvector<T>::operator-= (T d)
{
  for (int i = 0; i < dim; i++)
    comp[i] = comp[i] - d;
  return *this;
}
template <class T>
Cvector<T> Cvector<T>::operator -() {
	Cvector<T> result(*this);
	for (int i = 0; i < dim; i++) {
		result(i) = -result(i);
	}
	return result;
}
template <class T>
Cvector<T> Cvector<T>::operator - (Cvector<T> V){
	if (V.size()!=dim){cerr<<"erreur addition";}
	Cvector<T> result(V);
		for (int i = 0; i < V.size(); i++) {
			result(i) =  comp[i]-result(i);
		}
		return result;
}
template <class T>
Cvector<T> Cvector<T>::operator + (Cvector<T> V){
	if (V.size()!=dim){cerr<<"erreur addition";}
	Cvector<T> result(V);
	for (int i = 0; i < V.size(); i++) {
		result(i) = result(i) + comp[i];
	}
	return result;
}

template <class T>
Cvector<T> operator- (const Cvector<T> dvect, const T d)
{
  Cvector<T> R(dvect);
  R-=d;
  return R;
}

template <class T>
Cvector<T> & Cvector<T>::operator-= (const Cvector<T> dvect){
  for (int i = 0; i < dim; i++)
    comp[i] = dvect.comp[i] - comp[i];
  return *this;
}

template <class T>
Cvector<T> operator- (const Cvector<T> dvect, const Cvector<T> dvect2){
  Cvector<T> R(dvect);
  R -= dvect2;
  return (R);
}

Cvector<T>& Cvector<T>::operator*= (T d)
{
  for (int i = 0; i < dim; i++)
    comp[i] = d * comp[i];
  return *this;
}

template <class T>
Cvector<T> operator* (const T d, const Cvector<T> dvect)
{
  Cvector<T> R = Cvector<T>(dvect);
  R *= d;
  return (R);
}

template <class T>
Cvector<T> operator* (const Cvector<T> dvect, const T d)
{
  Cvector<T> R(dvect);
  R *= d;
  return (R);
}

template <class T>
T Cvector<T>::operator* (const Cvector<T> V)
{
	float ret=0;
  for (int i = 0; i < dim; i++)
    ret += comp[i] * V(i);
  return ret;
}

template <class T>
Cvector<T>& Cvector<T>::operator/= (T d)
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

template <class T>
Cvector<T> operator/ (const Cvector<T> dvect, const T d)
{
  Cvector<T> R(dvect);
  R /= d;
  return (R);
}

template <class T>
Cvector<T> & Cvector<T>::operator= (Cvector<T> dvect){
  std::cout << "Affectation";
  dim = dvect.dim;
  //comp = new T[dim];
  memcpy(comp, dvect.comp, dim * sizeof(T));
  return (*this);
}



std::ostream& operator <<(std::ostream & Out, const Cvector<T> & V) {
	for (int i = 0; i < V.dim; i++) {
		Out << V(i) << "\n";
	}
	return Out;
}
std::istream& operator >> (std::istream & In,const Cvector<T> & V){
	for (int i = 0; i < V.dim; i++) {
		In >> V(i);
	}
	return In;
}

template <class T>
bool Cvector<T>::operator == (const Cvector<T> &V){
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
