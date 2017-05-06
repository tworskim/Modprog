#ifndef HEIGHT
#define HEIGHT

class Height
{
 private :
  int nx;
  int ny;
  double Lx;
  double Ly;
  double **hgt;
 public :
  Height();
  Height(int m, int n, double lx, double ly, double db = 0);
  Height(const Height & hgt);
  double & operator() (double x, double y);
  ~Height();
  double getLx();
  double getLy();
  int getnx();
  int getny();
  void display();
};
#endif
