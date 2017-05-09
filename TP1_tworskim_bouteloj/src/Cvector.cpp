#include <stdio.h>
#include <iostream>
#include "Cvector.h"
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <complex>
using namespace std;


template <typename T>
void Cvector<T>::display(std::ostream& str)
{
  if (dim == 0)
    return;
  for (int i = 0; i < dim; i++)
    str << comp[i] << "\n";
}
template <typename T>
int Cvector<T>::size(){
	return this->dim;
}
template <typename T>
Cvector<T>::~Cvector()
{
  std::cout << "Destructeur\n";
  delete [] comp;
}
template <typename T>
Cvector<T>::Cvector()
  {
    std::cout << "Constructeur par défaut\n";
    dim=2;
    comp = new T[dim];
    for (int i=0; i<dim; i ++)
      comp[i] = 0;
  }
template <typename T>
Cvector<T>::Cvector(int d)
  {
    std::cout << "Constructeur taille et zeros\n";
    dim=d;
    comp = new T[dim];
    for (int i=0; i<dim; i ++)
      comp[i] = 0;
  }
template <typename T>
Cvector<T>::Cvector(int d, T db)
  {
    std::cout << "Constructeur taille et contenu\n";
    dim=d;
    comp = new T[dim];
    for (int i=0; i<dim; i ++)
      comp[i] = db;
  }
template <typename T>
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

template <typename T>
void Cvector<T>::fillRandomly()
{
  for (int i = 0; i < dim; i++)
    comp[i] = (T) rand()/(T) RAND_MAX;
}

template <typename T>
T& Cvector<T>::operator() (int i)
{
  if (i < 0 || i>= dim)
    {
      cerr << "Erreur Indice Tableau";
    }
  T& compi = comp[i];
  return (compi);
}
template <typename T>
T Cvector<T>::operator () (int i) const {
	if (i>dim){std::cerr<<"erreur accesseur const";}
	return comp[i];
}
template <typename T>
Cvector<T>& Cvector<T>::operator+= (T d)
{
  for (int i = 0; i < dim; i++)
    comp[i] = d + comp[i];
  return *this;
}
template <typename T>
Cvector<T> operator+ (const T d, const Cvector<T> dvect)
{
  Cvector<T> R(dvect);
  R += d;
  return (R);
}
template <typename T>
Cvector<T> operator+ (const Cvector<T> dvect, const T d)
{
  Cvector<T> R(dvect);
  R += d;
  return (R);
}
template <typename T>
Cvector<T> & Cvector<T>::operator+= (const Cvector<T> dvect){
  for (int i = 0; i < dim; i++)
    comp[i] = dvect.comp[i] + comp[i];
  return *this;
}


template <typename T>
Cvector<T>& Cvector<T>::operator-= (T d)
{
  for (int i = 0; i < dim; i++)
    comp[i] = comp[i] - d;
  return *this;
}
template <typename T>
Cvector<T> Cvector<T>::operator -() {
	Cvector<T> result(*this);
	for (int i = 0; i < dim; i++) {
		result(i) = -result(i);
	}
	return result;
}
template <typename T>
Cvector<T> Cvector<T>::operator - (Cvector<T> V){
	if (V.size()!=dim){cerr<<"erreur addition";}
	Cvector<T> result(V);
		for (int i = 0; i < V.size(); i++) {
			result(i) =  comp[i]-result(i);
		}
		return result;
}
template <typename T>
Cvector<T> Cvector<T>::operator + (Cvector<T> V){
	if (V.size()!=dim){cerr<<"erreur addition";}
	Cvector<T> result(V);
	for (int i = 0; i < V.size(); i++) {
		result(i) = result(i) + comp[i];
	}
	return result;
}

template <typename T>
Cvector<T> operator- (const Cvector<T> dvect, const T d)
{
  Cvector<T> R(dvect);
  R-=d;
  return R;
}

template <typename T>
Cvector<T> & Cvector<T>::operator-= (const Cvector<T> dvect){
  for (int i = 0; i < dim; i++)
    comp[i] = dvect.comp[i] - comp[i];
  return *this;
}

template <typename T>
Cvector<T> operator- (const Cvector<T> dvect, const Cvector<T> dvect2){
  Cvector<T> R(dvect);
  R -= dvect2;
  return (R);
}

template <typename T>
Cvector<T>& Cvector<T>::operator*= (T d)
{
  for (int i = 0; i < dim; i++)
    comp[i] = d * comp[i];
  return *this;
}

template <typename T>
Cvector<T> operator* (const T d, const Cvector<T> dvect)
{
  Cvector<T> R = Cvector<T>(dvect);
  R *= d;
  return (R);
}

template <typename T>
Cvector<T> operator* (const Cvector<T> dvect, const T d)
{
  Cvector<T> R(dvect);
  R *= d;
  return (R);
}

template <typename T>
T Cvector<T>::operator* (const Cvector<T> V)
{
	T ret = 0;
  for (int i = 0; i < dim; i++)
    ret += comp[i] * V(i);
  return ret;
}

template <typename T>
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

template <typename T>
Cvector<T> operator/ (const Cvector<T> dvect, const T d)
{
  Cvector<T> R(dvect);
  R /= d;
  return (R);
}

template <typename T>
Cvector<T> & Cvector<T>::operator= (Cvector<T> dvect){
  std::cout << "Affectation";
  dim = dvect.dim;
  //comp = new T[dim];
  memcpy(comp, dvect.comp, dim * sizeof(T));
  return (*this);
}


template <typename T>
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

template class Cvector<std::complex<double> >;
/*
int main(){
  Cvector<std::complex<double> > h = Cvector<std::complex<double> >(1, std::complex<double>(2,2));
  h *= std::complex<double>(0,1);
  h.display(std::cout);
  return(0);
}
*/
