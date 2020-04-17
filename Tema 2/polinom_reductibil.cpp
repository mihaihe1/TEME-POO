#include "polinom_reductibil.h"

void Polinom_reductibil::afis()
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
void Polinom_reductibil::afis_ca_produs()//afisare ca produs cu schema lui Horner
{
    Monom* p=this->get_monom();
    int x = abs(p[0].get_coef());
    int v[20];
    for(int i=0;i<20;++i)
        v[i]=0;
    int m=0;
    for(int i=1;i<=x/2;++i)//caut divizorii termenului liber
        if(x%i==0){
            v[m]=i;
            m++;
            v[m]=-i;
            m++;
        }
    int ok=0;
    for(int i=0;i<m;++i){//schema lui Horner
        int x=v[i];
        int sum=0;
        for(int j=0;j<this->get_nrmon();++j){
            int grad=p[j].get_grad();
            int coef=p[j].get_coef();
            int pow = 1;
            int cnt = 0;
            while(cnt < grad){
                pow*=x;
                cnt++;
            }
            sum+=(pow*coef);
        }
        if(sum==0)//daca gasesc radacina afisez polinom
        {
            ok=1;
            cout<<x<<" e radacina\n";
            int maxgr=p[this->get_nrmon()-1].get_grad();
            int horner[maxgr+1];
            for(int i=0;i<=maxgr;++i)
                horner[i]=0;
            for(int i=0;i<this->get_nrmon();++i)
                horner[maxgr-p[i].get_grad()]=p[i].get_coef();
            int horner2[maxgr+1];
            horner2[0]=horner[0];
            for(int i=1;i<maxgr;++i)
                horner2[i]=horner2[i-1]*x+horner[i];
            cout<<"Polinomul scris ca produs: (X-"<<x<<")*(";
            for(int i=0;i<maxgr;++i)
                if(horner2[i]){
                    if(horner2[i]>0 && i!=0)
                        cout<<"+";
                    if(horner2[i]==1){
                        if(maxgr-i-1 > 1)
                            cout<<"X^"<<maxgr-i-1;
                        else
                            if(maxgr-i-1 == 1)
                                cout<<"X";
                        else
                            cout<<1;
                    }
                    else{
                        if(maxgr-i-1 > 1)
                            cout<<horner2[i]<<"X^"<<maxgr-i-1;
                        else
                            if(maxgr-i-1 == 1)
                                cout<<horner2[i]<<"X";
                            else
                                cout<<horner2[i];
                    }
                }
            cout<<")\n";
            break;
        }
    }
    if(ok==0)
        cout<<"Nu s-a gasit radacina printre divizorii termenului liber\n";
}
int Polinom_reductibil::verif_criteriu()
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

void Polinom_reductibil::tip_polinom()
{
    cout<<"Polinom reductibil\n";
}
Polinom_reductibil::~Polinom_reductibil()
{
    //dtor
}
