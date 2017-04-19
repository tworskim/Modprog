#ifndef HEIGHT
#define HEIGHT

class Height
{
  Height();
  int nx;
  int ny;
  double Lx;
  double Ly;
  double **comp;
  Dvector(int nx, int ny, double db = 0);
  Dvector(const Height & hgt);
  Dvector(std::string str);
}
#endif
