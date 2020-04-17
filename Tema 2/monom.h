#ifndef MONOM_H
#define MONOM_H
#include <iostream>
using namespace std;

class Monom
{
    int grad;
    float coef;
    public:
        Monom();
        Monom(float, int);
        Monom(const Monom&);
        int get_grad();
        float get_coef();
        Monom operator =(Monom);
        friend ostream& operator <<(ostream&, const Monom&);
        friend istream& operator >>(istream&, Monom&);
        ~Monom();
};

#endif // MONOM_H
