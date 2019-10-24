#include<bits/stdc++.h> 

using namespace std; 
#define INF 0x7fffffff

int conexo = 0;

class tNo{
public:
    int id;
    bool visitado = false;
    bool opa = false;
    vector <tNo*> vizinhos;

    void conex(int id){
        if(!this->visitado && this->id == id){
            this->visitado = true;
            for (int i = 0; i < this->vizinhos.size (); i++)
                this->vizinhos[i]->conex (id);   
        }
        else if(this->visitado && this->id == id){
            conexo++;
        }
        else{
            if (this->visitado) return;
            this->visitado = true;
            for (int i = 0; i < this->vizinhos.size (); i++)
                this->vizinhos[i]->conex (id);  
        }

            
    }
};

int main(){

    int casos = 0, x = 0, y = 0, peso = 0, contador = 0, conex = 0;
    scanf("%d", &casos);
    for(int i = 0; i < casos; i++)
    {
        int nDoc = 0, dep = 0;
        scanf("%d %d", &nDoc, &dep);
        
            tNo nos[nDoc];
            for(int j = 0; j < nDoc; j++) nos[j].id = j;
            for(int j = 0; j < dep; j++){
                int a, b;
                scanf("%d %d", &a, &b);
                nos[a-1].vizinhos.push_back (&(nos[b-1]));
            }
            for(int j = 0; j < nDoc; j++){
                conexo = 0;
                nos[j].conex(j);
                for(int k = 0; k < nDoc; k++)
                    nos[k].visitado = false;
                if(conexo > 0){
                    printf("SIM\n");
                    break;
                }
            }
            if(conexo == 0)
                printf("NAO\n");
        
    }
  
}