#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int main()
{
    int altura,inicio,fin,up,down;
    cin>>altura>>inicio>>fin>>up>>down;
    inicio--;
    fin--;
    vector<int>E(altura,-1);
    queue<int>L;
    L.push(inicio);
    E[inicio]=0;
    int aux;
    while(!L.empty())
    {
        aux=L.front();
        L.pop();
        if(E[aux+up]==-1 and (aux+up)<=altura)
        {
            L.push(aux+up);
            E[aux+up]=E[aux]+1;
           // cout<<"PUSE A "<<aux+up<<endl;
        }
        if(E[aux-down]==-1 and (aux-down)>=0)
        {
            L.push(aux-down);
            E[aux-down]=E[aux]+1;
            //cout<<"PUSE A "<<aux-down<<endl;
        }
 
    }
    if(E[fin]==-1)
        cout<<"usar las escaleras"<<endl;
    else
        cout<<E[fin]<<endl;
    return 0;
}
