#ifndef HEIGHT
#define HEIGHT

class Height
{
  Height();
  int nx;
  int ny;
  double Lx;
  double Ly;
  double **hgt;
  Height(int m, int n, double db = 0);
  Height(const Height & hgt);
  ~Height();
};
#endif
