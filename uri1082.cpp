#include <bits/stdc++.h>

using namespace std;

class tNo{
public:
    char id;
    bool visitado = false;
    vector <tNo*> vizinhos;

    void imprimir(){
        if (this->visitado) return;
        this->visitado = true;
        printf("%c,",this->id);
        for (int i = 0; i < this->vizinhos.size (); i++)
            this->vizinhos[i]->imprimir ();
    }
};

int main()
{
    int numeroDeTestes = 0, i =0;
    scanf("%d\n", &numeroDeTestes);
    

    while(i < numeroDeTestes){
        
        int numeroDeVertices = 0, numeroDeArestas = 0, j = 0;
        int componentes = 0;
        scanf("%d ", &numeroDeVertices);
        scanf("%d\n", &numeroDeArestas);
        tNo nos[numeroDeVertices];
        for (int k = 0; k < numeroDeVertices; k++) {nos[k].id = k + 'a'; nos[k].visitado = false;}

        while (j < numeroDeArestas){
            char a, b;
            a = b = 0;
            while (a < 'a' || a > 'z') scanf ("%c", &a);
            while (b < 'a' || b > 'z') scanf ("%c", &b);
            nos[a - 'a'].vizinhos.push_back (&(nos[b - 'a']));
            nos[b - 'a'].vizinhos.push_back (&(nos[a - 'a']));
            j++;
        }
        printf("Case #%d:\n",i + 1);
        for (int it = 0; it < numeroDeVertices; it++)
        {
            if (!nos[it].visitado)
            {
                nos[it].imprimir ();
                printf ("\n");
                componentes++;
            }
        }
        printf("%d connected components\n", componentes);
        printf("\n");
        i++;
        j = 0;
    } 
    return 0;
}
