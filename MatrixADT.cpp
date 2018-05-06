#include "MatrixADT.h"

Matrix::Matrix(int dimx, int dimy) 
{
    this->dimx = dimx;
    this->dimy = dimy;
    
    board = new double*[dimx];
    for (int i = 0; i < dimx; ++i) 
    {
        board[i] = new double[dimy];
    }
}   

Matrix::~Matrix()
{
    for (int x=0; x<dimx; x++)
    {
        delete[] board[x];
    }
    delete[] board;
}

Matrix::Matrix(const Matrix &rhs)
{
    dimx = rhs.dimx;
    dimy = rhs.dimy;
    board = new double*[dimx];
    for (int x=0; x<dimx; x++)
    {
        board[x] = new double[dimx];
        *(board[x]) = *(rhs.board[x]);
    }
}

double Matrix::get_value(int posx, int posy) 
{
    if (&board[posx][posy] == nullptr)
        return 0;
    if (board[posx][posy] == inf)
        return inf;
    return board[posx][posy];
}

double Matrix::set_value(int posx, int posy, double value) 
{
    if (value == 0)
    {
        &board[posx][posy] == nullptr;
        return 0;
    }
    if (value < ((-1)*MAX) || MAX < value) 
    {
        board[posx][posy] = inf;
        return inf;
    }
        
    board[posx][posy] = value;
    return value;
}

void Matrix::resize(int newdimx, int newdimy) 
{
    double** newmatrix = new double*[newdimx];
    for (int i = 0; i < newdimx; ++i) 
    {
        newmatrix[i] = new double[newdimy];
    }
    ///////////////////////////////////////
    for (int i = 0; i < dimx; i++) 
    {
        for (int j = 0; j < dimy; j++) 
        {
            newmatrix[i][j] = board[i][j];
        }
    }
    ///////////////////////////////////////
    for (int i = 0; i < dimx; i++)
        delete[] board[i];

    delete[] board;
    
    board = newmatrix;
    
    this->dimx = newdimx;
    this->dimy = newdimy;
}

void Matrix::print() 
{
    for (int i = 0; i < dimx; i++) 
    {
        for (int j = 0; j < dimy; j++) 
        {
            cout << board[i][j] << ' ';
        }
        cout << "\n";
    }
}

int Matrix::get_dimx()
{
    return dimx;
}

int Matrix::get_dimy()
{
    return dimy;
}

bool Matrix::is_inrange(int posx, int posy) 
{
    return (posx >= 0 && posx < dimx) && (posy >= 0 && posy < dimy);
}

bool Matrix::is_dequal(Matrix m) 
{
    return (this->dimx == m.get_dimy()) && (this->dimy == m.get_dimx());    
}

void Matrix::inverse() 
{
    double** invmatrix = new double*[dimx];
    for (int i = 0; i < dimx; ++i) 
    {
        invmatrix[i] = new double[dimy];
    }
    ///////////////////////////////////////
    for (int i = 0; i < dimx; i++) 
    {
        for (int j = 0; j < dimy; j++) 
        {
            invmatrix[i][j] = board[j][i];
        }
    }
    ///////////////////////////////////////
    for (int i = 0; i < dimx; i++)
        delete[] board[i];

    delete[] board;
    
    board = invmatrix;
}

Matrix multiply(Matrix m1, Matrix m2) 
{
    double board_r[m1.get_dimx()][m1.get_dimx()];
    /////////////////////////////////////////////
    int size = 0;
    if (m1.get_dimx() <= m1.get_dimy()) 
    {
        size = m1.get_dimx();
    }
    else
    {
        size = m1.get_dimy();
    }
    Matrix result(size, size);
    /////////////////////////////////////////////
    if (m1.is_dequal(m2))
    {
        for(int i = 0; i < m1.get_dimx(); ++i)
        {
            for(int j = 0; j < m2.get_dimy(); ++j)
            {
                for (int k = 0; k < m1.get_dimy(); ++k)
                {
                    board_r[i][j] = m1.get_value(i, k) * m2.get_value(k, j);
                }
            }
        }
    /////////////////////////////////////////////
        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j < size; ++j)
            {
                result.set_value(i, j, board_r[i][j]);
            }
        }
        return result;
    }
    return result;
}

Matrix sum(Matrix m1, Matrix m2) 
{
    double board_r[m1.get_dimx()][m1.get_dimx()];
    /////////////////////////////////////////////
    int size = 0;
    if (m1.get_dimx() <= m1.get_dimy()) 
    {
        size = m1.get_dimx();
    }
    else
    {
        size = m1.get_dimy();
    }
    Matrix result(size, size);
    ////////////////////////////////////////////////
    if (m1.is_dequal(m2)){
        for (int i = 0; i < m1.get_dimx(); i++)
        {
            for (int j = 0; j < m1.get_dimy(); j++)
            {
                board_r[i][j] = m1.get_value(i, j) + m2.get_value(i, j);
            }
        }
        ///////////////////////////////////////////
        for(int i = 0; i < m1.get_dimx(); ++i)
        {
            for(int j = 0; j < m1.get_dimy(); ++j)
            {
                result.set_value(i, j, board_r[i][j]);
            }
        }
        return result;
    }
    return result;
}

Matrix operator*(Matrix m1, Matrix m2) 
{
    return multiply(m1, m2);    
}

Matrix operator+(Matrix m1, Matrix m2) 
{
    return sum(m1, m2);    
}
