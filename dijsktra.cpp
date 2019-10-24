#include <bits/stdc++.h>
 
#define INF 0x7fffffff

using namespace std;

class tNo
{
public:
    int id;
    vector <pair <int, tNo*> > nb;
    int cost;
   
    void dijkstra ()
    {
        int i;
        if (this->nb.size () == 0) return;
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
            this->nb[ids[i]].second->dijkstra ();
    }
};
 
int main(){
    int vertices = 0, estradas = 0, i = 0, sum = 0, x = 0, y = 0, peso = 0, j = 0;
    scanf("%d %d", &vertices, &estradas);
    tNo nos[vertices];
    for(i = 0; i < vertices; i++)
    {
        nos[i].id = i;
        nos[i].cost = INF;
    }
    for (i = 0; i < estradas; i++)
    {
        scanf ("%d %d %d", &x, &y, &peso);
        nos[x].nb.push_back (make_pair (peso, &(nos[y])));
        nos[y].nb.push_back (make_pair (peso, &(nos[x])));
    }
    nos[0].cost = 0;
    nos[0].dijkstra();

    for (i = 0; i < vertices; i++)
    {
        printf (" <%d, %d>", nos[i].id, nos[i].cost);
    }
    printf ("\n");
}