#include<bits/stdc++.h> 

using namespace std; 
#define INF 0x7fffffff

int conexo = 0;

class tNo
{
public:
    int id;
    vector <pair <int, tNo*>> vz;
    int cost;
    bool visitado = false;
    int dijkstra ()
    {
        int i, sum = 0;
        if (this->vz.size () == 0) return 0;
        vector <int> ids;
        for (i = 0; i < this->vz.size (); i++)
        {
            if (this->vz[i].first + this->cost < this->vz[i].second->cost)
            {
                this->vz[i].second->cost = this->vz[i].first + this->cost;
                ids.push_back (i);
            }
        }
        for (i = 0; i < ids.size (); i++)
            sum += this->vz[ids[i]].second->dijkstra ();
        
        return sum += this->cost;
    }
};


int main() { 
    int vertices, arestas, casos, start, custo = 0;
    int peso = 1, x = -1; 
    pair <int, tNo*> no;  
    scanf("%d",&casos);
    for(int it = 0; it < casos; it++){
        scanf("%d", &start);
        scanf("%d %d", &vertices, &arestas);
        tNo nos[vertices];
        for(int j = 0; j < vertices; j++) {nos[j].id = j;nos[j].cost = INF;}
        for(int j = 0; j < arestas; j++){
            int a, b;
            scanf("%d %d", &a, &b);
            nos[a].vz.push_back (make_pair(1, &nos[b]));
            nos[b].vz.push_back (make_pair(1, &nos[a]));
        }
        nos[start].cost = 0;
        custo = nos[start].dijkstra();
        
        printf("\nCusto: %d", custo);
        custo = 0;
    }

    return 0; 
}