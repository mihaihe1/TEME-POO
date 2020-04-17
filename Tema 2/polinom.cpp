#include "polinom.h"

Polinom::Polinom()//constructor default
{
    nr_monoame=1;
    m=new Monom;
}

Polinom::Polinom(const Polinom& c)//constructor de copiere
{
    nr_monoame=c.nr_monoame;
    m=new Monom[nr_monoame];
    for(int i=0;i<nr_monoame;++i)
        m[i]=c.m[i];
}

Polinom::Polinom(int x, Monom* p)//constructor ce initializeaza un polinom cu monoame existente
{
    nr_monoame=x;
    m=new Monom[x];
    for(int i=0;i<x;++i)
        m[i]=p[i];
}
ostream& operator<<(ostream& out, const Polinom& p)//supraincarcarea <<
{
    out<<p.m[0];
    for(int i=1;i<p.nr_monoame;++i)
        if(p.m[i].get_coef() > 0)
            out<<"+"<<p.m[i];
        else
            if(p.m[i].get_coef() < 0)
                out<<p.m[i];

    return out;
}

istream& operator>>(istream& in, Polinom& p)//supraincarcarea >>
{
    cout<<"Dati numarul de monoame: ";
    in>>p.nr_monoame;
    p.m=new Monom[p.nr_monoame];
    for(int i=0;i<p.nr_monoame;++i)
        in>>p.m[i];
    return in;
}
void Polinom::tip_polinom()//metoda virtual pt afisarea tipului de polinom
{
    cout<<"Polinom";
}
int Polinom::criteriul_eisenstein()//coeficientii trebuie sa fie primi intre ei, iar daca exista p prim
//a.i. p|coeficienti(fara ultimul) si p nu divide an si p*p divide a0
{
    if(nr_monoame == 1)
        return 1;
    int aux=abs(m[0].get_coef());
    for(int i=1;i < nr_monoame;++i){//calculez cmmmdc
        int aux2=abs(m[i].get_coef());
        while(aux != aux2){
            if(aux>aux2)
                aux-=aux2;
            else
                aux2-=aux;
        }
    }

    if(aux != 1){//coeficientii trebuie sa fie primi intre ei
        cout<<"Criteriul nu decide";
        return -1;
    }
    int min1=abs(m[0].get_coef());
    for(int i=1;i<nr_monoame;++i)
        if(abs(m[i].get_coef())<min1)
            min1=abs(m[i].get_coef());
    bool a[50];
    for(int i=2;i<=min1;++i)
        a[i]=1;

    for(int i=2;i<=sqrt(min1);++i)//a[i] = 1 ->i prim
        if(a[i])
            for(int j=i;j<=min1/i;++j)
                a[i*j]=0;
    int ok=0;
    for(int i=2;i<=min1;++i)
        if(a[i]){
           int cnt=0;
           for(int j=0;j<nr_monoame-1;++j){
                if(int(m[j].get_coef())%i!=0)
                    break;
                cnt++;
           }
           //verific daca exista p a.i. p|coeficientii(fara ultimul) si p*p | a0
           if(cnt == nr_monoame-1 && int(m[nr_monoame-1].get_coef())%i !=0 && int(m[0].get_coef())%(i*i)!=0){
                ok=1;
                break;
           }
        }
    return ok;
}
int Polinom::get_nrmon()//getter numar monoame
{
    return nr_monoame;
}
Monom* Polinom::get_monom()//getter monoame
{
    return m;
}
void Polinom::set_nrmon(int x)//setter nr monoame
{
    nr_monoame=x;
}
void Polinom::set_monom(Monom* p)//setter monoame
{
    m=new Monom[nr_monoame];
    for(int i=0;i<nr_monoame;++i)
        m[i]=p[i];
}
Polinom Polinom::operator=(Polinom c)//supraincarcarea =
{
    nr_monoame=c.nr_monoame;
    m=new Monom[nr_monoame];
    for(int i=0;i<nr_monoame;++i)
        m[i]=c.m[i];
    return *this;
}

Polinom::~Polinom()//destructor
{
    nr_monoame=0;
    delete []m;
}
