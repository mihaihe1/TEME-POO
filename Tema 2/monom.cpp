#include "monom.h"

Monom::Monom()//constructor default
{
    grad=0;
    coef=0;
}

Monom::Monom(float x, int y)//constructor - x coeficient, y grad
{
    this->coef=x;
    this->grad=y;
}

Monom::Monom(const Monom& c)//constructor de copiere
{
    this->coef=c.coef;
    this->grad=c.grad;
}

int Monom::get_grad()//getter grad
{
    return grad;
}

float Monom::get_coef()//getter coeficient
{
    return coef;
}

ostream& operator<<(ostream& out, const Monom& m)//supraincarcarea <<
{
    out<<m.coef<<"*X^"<<m.grad;
    return out;
}

istream& operator>>(istream& in, Monom& m)//supraincarcarea >>
{
    cout<<"Cititi coefientul: ";
    in>>m.coef;
    cout<<"Cititi gradul: ";
    in>>m.grad;
    return in;
}

Monom Monom::operator =(Monom c)//supraincarcare =
{
    grad=c.grad;
    coef=c.coef;
    return *this;
}

Monom::~Monom()//destructor
{
    grad=0;
    coef=0;
}
