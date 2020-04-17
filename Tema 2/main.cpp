#include <iostream>
#include <math.h>
#include "monom.h"
#include "polinom.h"
#include "polinom_ireductibil.h"
#include "polinom_reductibil.h"
using namespace std;
int main()
{
    /*Monom a;
    Monom b(3, 2);
    cout<<b;
    Monom c(b);
    cout<<c;
    return 0;*/

    Polinom t;
    cin>>t;
    //cout<<t;
    int tip_polinom=t.criteriul_eisenstein();
    if(tip_polinom == 1){
        Polinom *p;
        Polinom_ireductibil q(t.get_nrmon(),t.get_monom());
        Polinom_ireductibil t(q);
        t.afis();
        int verif = q.verif_criteriu();
        if(verif == 1){
       // q.afis();
        p=&q;
        p->tip_polinom();
        }
    }
    else
        if(tip_polinom == 0){
        Polinom *p;
        Polinom_reductibil q(t.get_nrmon(),t.get_monom());
        int verif = q.verif_criteriu();
        if(verif == 0){
        q.afis();
        q.afis_ca_produs();
        p=&q;
        p->tip_polinom();
        }
    }
    else
        cout<<"Criteriul nu decide";
}
