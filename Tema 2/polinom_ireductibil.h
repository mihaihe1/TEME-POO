#ifndef POLINOM_IREDUCTIBIL_H
#define POLINOM_IREDUCTIBIL_H
#include "polinom.h"
#include <iostream>
using namespace std;

class Polinom_ireductibil:public Polinom{
    public:
        Polinom_ireductibil(int x, Monom* p):Polinom(x,p){
            this->set_nrmon(x);
            this->set_monom(p);
        }
       Polinom_ireductibil(const Polinom_ireductibil& pi):Polinom(pi){
            int x=this->get_nrmon();
            this->set_nrmon(x);
            Monom *p=this->get_monom();
            this->set_monom(p);
        }
        int verif_criteriu();
        void afis();
        void tip_polinom();
        ~Polinom_ireductibil();
};

#endif // POLINOM_IREDUCTIBIL_H
