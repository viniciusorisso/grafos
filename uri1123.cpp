#include <bits/stdc++.h>

using namespace std;

int MAXTAM = 0x7fffffff;

class tNo{
public:
    int id;
    bool visitado = false;
    int peso;
    vector <tNo*> vizinhos;

    void imprimir(){
        if (this->visitado) return;
        this->visitado = true;
        printf("%d,",this->id);
        for (int i = 0; i < this->vizinhos.size (); i++)
            this->vizinhos[i]->imprimir ();
    }

};


for(int i = 0; i < numeroCidades; i++) cidades[i].id = i;
        for(int i = 0; i < numeroEstradas; i++){
            int cidadeA = 0, cidadeB = 0, pedagio = 0;
            scanf("%d %d %d\n", &cidadeA, &cidadeB, &pedagio);
            cidades[cidadeA].vizinhos.push_back(&cidades[cidadeB]);
            cidades[cidadeB].vizinhos.push_back(&cidades[cidadeA]);
        }
int main(){
    int numeroCidades = -1, numeroEstradas = 0, numeroEstradasRotaServico = 0, cidadeConserto = 0;
    int j = 0, componentes = 0;
    scanf("%d %d %d %d\n", &numeroCidades, &numeroEstradas, &numeroEstradasRotaServico, &cidadeConserto);
    for(;!(numeroCidades==numeroEstradas == numeroEstradasRotaServico == cidadeConserto);){        
        tNo cidades[numeroCidades];
        vector <int> * menorCaminho;

        for(int i = 0; i < numeroCidades; i++) cidades[i].id = i;
        for(int i = 0; i < numeroEstradas; i++){
            int cidadeA = 0, cidadeB = 0, pedagio = 0;
            scanf("%d %d %d\n", &cidadeA, &cidadeB, &pedagio);
            cidades[cidadeA].vizinhos.push_back(&cidades[cidadeB]);
            cidades[cidadeB].vizinhos.push_back(&cidades[cidadeA]);
        }
        printf("Case #%d:\n",j + 1);
        for (int it = 0; it < numeroCidades; it++)
        {
            if (!cidades[it].visitado)
            {
                cidades[it].imprimir ();
                printf ("\n");
            }
        }
        
        printf("\n");
        j++;
        scanf("%d %d %d %d\n", &numeroCidades, &numeroEstradas, &numeroEstradasRotaServico, &cidadeConserto);
    }
       
}