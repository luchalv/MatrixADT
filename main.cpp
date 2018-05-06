#include "MatrixADT.cpp"

int main()
{
  int a = 3, b = 3;
  Matrix m1(a, b);
  for (int i = 0; i < a; i++) 
  {
    for (int j = 0; j < b; j++) 
    {
      m1.set_value(i,j,2);
    }
  }
  
  Matrix m2(b, a);
  for (int i = 0; i < b; i++) 
  {
    for (int j = 0; j < a; j++) 
    {
      m2.set_value(i,j,3);
    }
  }
  
  Matrix m = m1 + m2;
  m.set_value(0,1,3);
  m.print();
  cout << '\n';
  m.inverse();
  m.print();
  
  return 0;
}
