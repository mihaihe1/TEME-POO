#ifndef POLINOM_H
#define POLINOM_H

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "monom.h"
using namespace std;

class Polinom
{
    int nr_monoame;
    Monom* m;
public:
    Polinom();
    Polinom(const Polinom&);
    Polinom(int, Monom*);
    ~Polinom();
    Polinom operator =(Polinom);
    virtual void tip_polinom();
    friend ostream& operator<<(ostream&, const Polinom&);
    friend istream& operator>>(istream&, Polinom&);
    int criteriul_eisenstein();
    int get_nrmon();
    void set_nrmon(int);
    void set_monom(Monom*);
    Monom* get_monom();
};

#endif // POLINOM_H
