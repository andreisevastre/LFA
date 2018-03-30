
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int stari[100], stare_init, n, m, p, finale[100], tranz, j, st[100], teste;  // p - cate stari finale am
char sir[100];   // finale - vector cu starile finale
char alfabet[100];


struct nod
{
    int stare;
    nod *urm;
};

nod *mat[105][200], *a, *b;


void parcurgere(int x, int p)
{
    if (sir[p]!='\0')
       {
           if (mat[x][sir[p]]!=NULL)
            {
                nod *c=mat[x][sir[p]];

                while(c->urm)
                {
                    parcurgere(c->stare, p+1);
                    c=c->urm;

                    if ( c==NULL )
                        return;
                }
                parcurgere(c->stare, p+1);
            }
       }
    else st[++j]=x;
}


int main()
{
    freopen("fisier.in", "r", stdin);

    //freopen("fisier.out", "w", stdout);

    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>stari[i];
    }

    cin>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>alfabet[i];
    }

    cin>>stare_init;
    cin>>p;

    for(int i=1; i<=p; i++)
    {
        cin>>finale[i];
    }

    int x, z;
    char y;

    cin>>tranz;

    for(int i=1; i<=tranz; i++)
    {
        cin>>x>>y>>z;
        if(mat[x][y]==NULL)
        {
            mat[x][y]=new nod;
            mat[x][y]->stare=z;
            mat[x][y]->urm=NULL;
        }

        else
        {
            a=new nod;
            a->stare=z;
            a->urm=mat[x][y];
            mat[x][y]=a;
        }
    }

    cin>>teste;

    for(int i=1; i<=teste; i++)
    {
        cin>>sir;
        j=0;

        parcurgere(stare_init, 0);

        int sem=0;

        for(int i=1; i<=j; i++)
            for(int k=1; k<=p; k++)
                if(st[i]==finale[k])
                {
                    sem=1;
                }

        if (sem==1) cout<<"da";  //afiseaza da cand cuvantul e acceptat de automat. "nu" in caz contrar
                else cout<<"nu";

        cout<<endl;
    }

return 0;
}
