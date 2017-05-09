#ifndef CVECTOR
#define CVECTOR

/*!
 * \file Cvector.H
 * \brief Classe Cvector
 * \author Marcelin Tworski
 * \version 0.1
 */


 /*! \class Cvector
   * \brief classe representant un vectuer par un entier dim et un tableau comp
   *
   *  La classe gere la lecture d'une liste de morceaux
   */
template<typename T> class Cvector
{
 private :
  T *comp;
 public :
  int dim;

    /*!
     *  \brief Constructeur
     *
     *  Constructeur par défaut de la classe Cvector
     */
  Cvector();
  /*!
     *  \brief Constructeur avec un paramêtre de taille, initialisé à 0 .. 0
     *
     *  Constructeur de la classe Cvector
     *
     *  \param d : dimension du vecteur
     */
  Cvector(int d);
  /*!
     *  \brief Constructeur avec un paramêtre de taille, initialisé à la meme valeur pour toutes les composantes
     *
     *  Constructeur de la classe Cvector
     *
     *  \param d : dimension du vecteur db : valeur d'initialisation
     */
  Cvector(int d, T db);

  /*!
     *  \brief Constructeur par recopie
     *
     *  Constructeur de la classe Cvector
     *
     *  \param dv : Vecteur à recopier
     */
  Cvector(const Cvector<T> & dv);

  /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Cvector
     */
  ~Cvector();

  /*!
     *  \brief Affichage
     *
     *  Affichage d'un vecteur
     *
     *  \param str : flux de sortie
     */
  void display(std::ostream& str);
  /*!
     *  \brief Remplit aléatoirement
     *
     *  Rempli aléatoirement un vecteur avec des T entre 0 et 1
     */
  void fillRandomly();
  /*!
     *  \brief Taille
     *
     *  Donne la taille d'un vecteur
     */
  int size();
  /*!
     *  \brief opérateur ()
     *
     *  Donne la i-ème composante du vecteur
     *
     *\param i : composante désirée
     */
  T &operator () (int i) ;
  T operator () (int i) const;
 /*!
     *  \brief Addition
     *
     *  Addition vecteur v et T d :  v += d
     *
     *\param d : T à ajouter
     */
  Cvector<T> & operator+= (T d);
  /*!
     *  \brief Soustraction
     *
     *  Soustraction vecteur v et T d :  v += d
     *
     *\param d : T à soustraire
     */
  Cvector<T> & operator-= (T d);
    /*!
     *  \brief Soustraction
     *
     *  Soustraction vecteur v et T d :  v += d
     *
     *\param d : T à soustraire
     */
  Cvector<T> & operator*= (T d);
  Cvector<T> & operator/= (T d);

  Cvector<T> & operator= (Cvector<T> dvect);
  Cvector<T> & operator+= (Cvector<T> dvect);
  Cvector<T> & operator-= (Cvector<T> dvect);

  Cvector<T> operator - ();
  Cvector<T> operator - (Cvector<T> V);
  Cvector<T> operator + (Cvector<T> V);
  T operator * (Cvector<T> V);

  bool operator == (const Cvector<T> &V);



};
/*
template<typename T>
Cvector<T> operator+ (const T d, const Cvector<T> dvect);
template<typename T>
Cvector<T> operator+ (const Cvector<T> dvect, const T d);
template<typename T>
Cvector<T> operator- (const T d, const Cvector<T> dvect);
template<typename T>
Cvector<T> operator- (const Cvector<T> dvect, const T d);
template<typename T>
Cvector<T> operator* (const T d, const Cvector<T> dvect);
template<typename T>
Cvector<T> operator* (const Cvector<T> dvect, const T d);
template<typename T>
Cvector<T> operator/ (const Cvector<T> dvect,const T d);

T operator* (const Cvector<T> dvect, const Cvector<T> dvect2);
*/
#endif
