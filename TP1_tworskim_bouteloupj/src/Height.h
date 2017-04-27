#ifndef HEIGHT
#define HEIGHT

class Height
{
 protected :
  int nx;
  int ny;
  double Lx;
  double Ly;
  double **hgt;
 public : 
  Height();
  Height(int m, int n, double db = 0);
  Height(const Height & hgt);
  ~Height();
};
#endif
