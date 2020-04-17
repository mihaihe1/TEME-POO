#ifndef POLINOM_REDUCTIBIL_H
#define POLINOM_REDUCTIBIL_H
#include "polinom.h"
#include <iostream>
using namespace std;

class Polinom_reductibil:public Polinom
{
    public:
        Polinom_reductibil(int x, Monom* p):Polinom(x,p){
            this->set_nrmon(x);
            this->set_monom(p);
        }
        Polinom_reductibil(const Polinom_reductibil& pr):Polinom(pr){
            int x=this->get_nrmon();
            this->set_nrmon(x);
            Monom *p=this->get_monom();
            this->set_monom(p);
        }
        int get_red_nrmon(){return this->get_nrmon();}
        Monom* get_red_monom(){return this->get_monom();}
        void afis();
        void tip_polinom();
        void afis_ca_produs();
        int verif_criteriu();
        ~Polinom_reductibil();
};

#endif // POLINOM_REDUCTIBIL_H
