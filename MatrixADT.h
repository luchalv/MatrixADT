#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int MAX = 10000;

class Matrix {
    int dimx, dimy;
    int rows_;
    double** board;
    double inf = numeric_limits<double>::infinity();
    
    friend Matrix operator*(Matrix m1, Matrix m2);
    friend Matrix operator+(Matrix m1, Matrix m2);
public:
    Matrix(int dimx, int dimy);
    ~Matrix();
    Matrix(const Matrix &rhs);
    
    double get_value(int posx, int posy);
    double set_value(int posx, int posy, double value);
    
    void resize(int newdimx, int newdimy);
    void print();
    
    int get_dimx();
    int get_dimy();
    
    bool is_inrange(int posx, int posy);
    bool is_dequal(Matrix m);
    
    void inverse();
};

Matrix multiply(Matrix m1, Matrix m2);

Matrix sum(Matrix m1, Matrix m2);
