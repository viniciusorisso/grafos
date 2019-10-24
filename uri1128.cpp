#include <bits/stdc++.h>

using namespace std;

int verti = 0;
int conexo = 0;

class tNo{
public:
    int id;
    bool visitado = false;
    vector <tNo*> vizinhos;

    void conex(){
        if (this->visitado) return;
        this->visitado = true;
        for (int i = 0; i < this->vizinhos.size (); i++)
            this->vizinhos[i]->conex ();
        conexo++;   
    }
};

int main (){

    int intercecoes = 0, ruas = 0, i = 0, x = 0, y = 0, peso = 0, contador = 0, conex = 0;
    scanf("%d %d", &intercecoes, &ruas);
    while(!(intercecoes ==0 && ruas == 0)){
        tNo nos[intercecoes];
        for (int k = 0; k < intercecoes; k++) {nos[k].id = k; nos[k].visitado = false;}
        for (i = 0; i < ruas; i++)
        {
            scanf ("%d %d %d", &x, &y, &peso);
            if(peso == 1)
                nos[x-1].vizinhos.push_back (&(nos[y-1]));
            else{
                nos[x-1].vizinhos.push_back (&(nos[y-1]));
                nos[y-1].vizinhos.push_back (&(nos[x-1]));
            }
        }
        for(i = 0; i < intercecoes; i++){
            nos[i].conex();
            for(int k = 0; k < intercecoes; k++)
                nos[k].visitado = false;
            if(intercecoes == conexo)
                contador++;
            conexo = 0;
        }
        if(intercecoes == contador)
            printf("1\n");
        else{
            printf("0\n");
        }
        scanf("%d %d", &intercecoes, &ruas);
        conexo = 0;
        contador = 0;
    }
}