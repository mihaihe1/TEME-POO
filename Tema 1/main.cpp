#include <iostream>

using namespace std;
class Vector{
    int n;//numarul de elemente al vectorului
    int p[50];//declararea vectorului
public:
    friend class Vectori_de_vectori;//declararea prieteniei clasei Vector cu clasa Vectori_de_vectori
    Vector(int x, int dim);
    Vector(int dim,int v[]);
    Vector(Vector &c);
    Vector();
    ~Vector();
    friend ostream & operator << (ostream &out, const Vector &c);
    friend istream & operator >> (istream &in, Vector &c);
    Vector operator + (Vector &a){//supraincarcarea operatorului + pentru adunarea a 2 vectori
        Vector b;
        b.n=n;
        for(int i=0;i<n;++i)
            if(i<n && i<a.n)
                b.p[i]=p[i]+a.p[i];
            else if(i<n)
                b.p[i]=p[i];
            else
                b.p[i]=a.p[i];
        return b;
    }
};
Vector::Vector(int x, int dim){//initializarea vectorului de dimensiune dim cu elementul x
        n=dim;
        for(int i=0;i<n;++i)
            p[i]=x;
    }
Vector::Vector(int dim,int v[]){//costructor de initializare(initializarea unui vector cu un vector)
        n=dim;
        for(int i=0;i<n;++i)
            p[i]=v[i];
    }
Vector::Vector(Vector &c){//constructor de copiere
        n=c.n;
        for(int i=0;i<n;++i)
            p[i]=c.p[i];
    }
Vector::Vector(){}//constructor default
Vector::~Vector(){//destructor
        n=0;
    }
ostream & operator << (ostream &out,const Vector &c){//supraincarcarea operatorului <<
    for(int i=0;i<c.n;++i)
        out<<c.p[i]<<" ";
    out<<"\n";
    return out;
}
istream & operator >> (istream &in, Vector &c){//supraincarcarea operatorului >>
    cout << "Dati numarul de elemente \n";
    in >> c.n;
    cout << "Cititi "<<c.n<<" elemente\n";
    for(int i=0;i<c.n;++i)
        in >> c.p[i];
    return in;
}
class Vectori_de_vectori{
    int dim;
    Vector *v;
public:
    Vectori_de_vectori();
    Vectori_de_vectori(int x, int n);
    Vectori_de_vectori(int n,int t_dim,int t[]);
    Vectori_de_vectori(Vectori_de_vectori &c);
    ~Vectori_de_vectori();
    void CitireVdv();
    void CreareMat();
    void afisvdv();
    Vectori_de_vectori operator + (Vectori_de_vectori &c){//supraincarcarea operatorului + pt adunarea a 2 obiecte de tip Vectori_de_vectori
        Vectori_de_vectori b(0,max(dim,c.dim));
        for(int i=0;i<b.dim;++i){
            b.v[i].n=max(v[i].n,c.v[i].n);
            for(int j=0;j<b.v[i].n;++j)
                if(i<v[i].n && i<c.v[i].n)
                    b.v[i].p[j]=v[i].p[j]+c.v[i].p[j];
                else if(i<v[i].n)
                    b.v[i].p[j]=v[i].p[j];
                else
                    b.v[i].p[j]=c.v[i].p[j];
        }
        b.CreareMat();
        return b;
    }
};
Vectori_de_vectori::Vectori_de_vectori(){}//constructor default
Vectori_de_vectori::Vectori_de_vectori(int x, int n){//constructor pt initializarea unui obiect de dimensiune n cu n vectori plini cu x
    dim=n;
    v=new Vector[dim];
    for(int i=0;i<n;++i){
        v[i].n=dim;
        for(int j=0;j<n;++j)
            v[i].p[j]=x;
    }
}
Vectori_de_vectori::Vectori_de_vectori(int n,int t_dim,int t[]){//constructor de initializare a unui obiect de dimensiune n cu n vectori t
    dim=n;
    v=new Vector[dim];
    for(int i=0;i<n;++i){
        v[i].n=t_dim;
        for(int j=0;j<t_dim;++j)
            v[i].p[j]=t[j];
    }
}
Vectori_de_vectori::Vectori_de_vectori(Vectori_de_vectori &c){
    dim = c.dim;
    v=new Vector[dim];
    for(int i=0;i<dim;++i){
        v[i].n=c.v[i].n;
        for(int j=0;j<v[i].n;++j)
            v[i].p[j]=c.v[i].p[j];
    }
}
Vectori_de_vectori::~Vectori_de_vectori(){//destructor
    dim=0;
}
void Vectori_de_vectori::CitireVdv(){//metoda publica pentru citirea unui obiect de tip Vectori_de_vectori
    cout<<"Dati nr de componente \n";
    cin>>dim;
    v=new Vector[dim];
    for(int i=0;i<dim;++i){
        cin>>v[i];
    }
}
void Vectori_de_vectori::CreareMat(){//metoda publica pentru crearea unei matrice din obiectul dat
    int nr_linii=dim;
    int nr_coloane=0;
    for(int i=0;i<dim;++i)
        if(v[i].n>nr_coloane)
            nr_coloane=v[i].n;
    int a[nr_linii][nr_coloane];
    for(int i=0;i<nr_linii;++i)
        for(int j=0;j<nr_coloane;++j)
            if(j<v[i].n)
                a[i][j]=v[i].p[j];
            else
                a[i][j]=0;
    for(int i=0;i<nr_linii;++i){
        for(int j=0;j<nr_coloane;++j)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}
void Vectori_de_vectori::afisvdv(){//metoda publica pt afisarea unui obiect de tip Vectori_de_vectori
        for(int i=0;i<dim;++i)
            cout<<v[i];
        cout<<"\n";
    }
int main()
{
    //Vector s;  //declarare vector
    //cin >> s;    //citire vector
    //cout << s;   //afisare vector

    //Vectori_de_vectori d(10,4);
    //d.CreareMat();   //metoda de creare a unei matrice

    //int v[3]={1,2,3};
    //Vectori_de_vectori a(3,3,v);
    //a.afisvdv();

    //Vectori_de_vectori a(3,4);
    //Vectori_de_vectori b(a);
    //b.afisvdv();

    //Vectori_de_vectori a;
    //a.CitireVdv();
    //a.CreareMat();

    /*Vectori_de_vectori a;
    a.CitireVdv();
    Vectori_de_vectori b;
    b.CitireVdv();
    Vectori_de_vectori c;
    c=a+b;*/

    return 0;
}
