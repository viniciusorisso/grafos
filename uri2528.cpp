#include<bits/stdc++.h> 

using namespace std; 
#define INF 0x7fffffff

int conexo = 0;

class tNo
{
public:
    int id;
    vector <pair <int, tNo*> > nb;
    int cost;
    bool visitado = false;
    void dijkstra (int E)
    {
        int i;
        if (this->nb.size () == 0) return;
        if(this->id == E) return;
        vector <int> ids;
        for (i = 0; i < this->nb.size (); i++)
        {
            if (this->nb[i].first + this->cost < this->nb[i].second->cost)
            {
                this->nb[i].second->cost = this->nb[i].first + this->cost;
                ids.push_back (i);
            }
        }
        for (i = 0; i < ids.size (); i++)
            this->nb[ids[i]].second->dijkstra (E);
    }
};


int main() { 
    int cidades, rotas;
    int C,R,E; 
    int peso = 1;

    while(1){


        if(scanf("%d%d", &cidades, &rotas) == EOF)
            break;

        tNo nos[cidades];

        for(int i = 0; i < cidades; i++)
        {
            nos[i].id = i;
            nos[i].cost = INF;
        }

        int a, b;
        for(int i = 0; i < rotas; i++){
            scanf("%d%d", &a, &b);
            a -= 1; b -= 1;
            nos[a].nb.push_back (make_pair (peso, &(nos[b])));
            nos[b].nb.push_back (make_pair (peso, &(nos[a])));
        }
        scanf("%d%d%d", &C,&R,&E);
        
        C -= 1; R -= 1; E -= 1;
        
        nos[C].cost = 0;
        nos[C].dijkstra(E);

        printf ("%d\n", nos[R].cost);
    }

    return 0; 
}