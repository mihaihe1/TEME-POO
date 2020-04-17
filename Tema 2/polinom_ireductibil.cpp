#include "polinom_ireductibil.h"

void Polinom_ireductibil::afis()//afis polinom ired
{
    Monom* p=this->get_monom();
    cout<<p[0];
    for(int i=1;i<this->get_nrmon();++i)
        if(p[i].get_coef() > 0)
            cout<<"+"<<p[i];
        else
            if(p[i].get_coef() < 0)
                cout<<p[i];
    cout<<"\n";
}
void Polinom_ireductibil::tip_polinom()//afis tip polinom ired
{
    cout<<"Polinom ireductibil";
}
int Polinom_ireductibil::verif_criteriu()//verific din nou criteriul
{
    Monom* p = this->get_monom();
    for(int i=0;i<this->get_nrmon();++i)
        try{
            if(p[i].get_coef() != int(p[i].get_coef()))
                throw p[i].get_coef();
        }
        catch(float x){
            cout << "Coeficientii polinomului nu sunt intregi\n";
            return -1;
        }

    if(this->get_nrmon() == 1)
        return 1;
    int aux=abs(p[0].get_coef());
    for(int i=1;i < this->get_nrmon();++i){
        int aux2=abs(p[i].get_coef());
        while(aux != aux2){
            if(aux>aux2)
                aux-=aux2;
            else
                aux2-=aux;
        }
    }

    if(aux != 1){
        cout<<"Criteriul nu decide";
        return -1;
    }
    int min1=abs(p[0].get_coef());
    for(int i=1;i<this->get_nrmon();++i)
        if(abs(p[i].get_coef())<min1)
            min1=abs(p[i].get_coef());
    bool a[50];
    for(int i=2;i<=min1;++i)
        a[i]=1;

    for(int i=2;i<=sqrt(min1);++i)
        if(a[i])
            for(int j=i;j<=min1/i;++j)
                a[i*j]=0;
    int ok=0;
    for(int i=2;i<=min1;++i)
        if(a[i]){
           int cnt=0;
           for(int j=0;j<this->get_nrmon()-1;++j){
                if(int(p[j].get_coef())%i!=0)
                    break;
                cnt++;
           }
           if(cnt == this->get_nrmon()-1 && int(p[this->get_nrmon()-1].get_coef())%i !=0 && int(p[0].get_coef())%(i*i)!=0){
                ok=1;
                break;
           }
        }
    return ok;
}
Polinom_ireductibil::~Polinom_ireductibil()
{

}
