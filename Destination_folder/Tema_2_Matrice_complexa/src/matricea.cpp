#include "matricea.h"
#include <iostream>
using namespace std;

/*matrice::matrice(int Size)  /// intitializeaza o matrice de Size x Size cu 0 peste tot
{
    row=Size;
    col=Size;
    m=new Complex[row*col];
    for(int i=0; i<row*col; i++)
    {
        m[i].set_real(0);
        m[i].set_imaginary(0);
    }
}
    matrice(int re,int im,int ROW, int COL)   /// atribuie element fiecarui element din matrice
    {
        row=ROW;
        col=COL;
        m=new Complex[row*col];
        for(int i=0; i<row*col; i++)
        {
            m[i].set_real(re);
            m[i].set_imaginary(im);
        }
    }
matrice::matrice(const matrice& mat)  /// copiere
{
    row=mat.row;
    col=mat.col;
    m=new Complex[row*col];
    for(int i=0; i<row*col; i++)
    {
        m[i]=mat.m[i];
    }
}
matrice::matrice()  /// initializare
{
    row=0;
    col=0;
    m=new Complex[row*col];
}

/*istream& operator>>(istream&s,matrice& mat) /// operatorul de citire pentru numere reale
{
    for(int i=0;i<mat.row*mat.col;i++)
    {
        s>>mat.m[i];
    }
    return s;
}
*/



