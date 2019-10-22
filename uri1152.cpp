#include <bits/stdc++.h>

using namespace std;


class arb{
public:
    int idCidadeA;
    int peso;
    bool status = false;
    int referencia;

    arb(int id, int peso){
        this->idCidadeA = id;
        this->peso = peso;
    }
};

class tNo{
public:
    int id;
    bool visitado = false;
    int peso;
    vector <tNo*> pesos;
    vector <tNo*> vizinhos;
};

int main(){

    int vertices = 0, estradas = 0, i = 0;
    scanf("%d %d\n", &vertices, &estradas);
    printf("%d %d\n", vertices, estradas);
    tNo juncoes[vertices];
    for(int j = 0; j < vertices; j++){
            juncoes[j].id = j;
        }
    for(;i < estradas;){
        int x = 0, y, peso;
        scanf("%d %d ", &x, &y);
        if(x == y == 0){
            break;
        }
        scanf("%d\n", &peso);
        tNo a, b;
        a.id = x;
        a.peso = peso;
        b.id = y;
        b.peso = peso;      
        juncoes[x].vizinhos.push_back(&juncoes[y]);
        juncoes[y].vizinhos.push_back(&juncoes[x]);
        juncoes[x].pesos.push_back(&a);
        juncoes[y].pesos.push_back(&b);
    }
}