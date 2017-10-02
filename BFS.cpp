#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
vector<vi> g;
vi padres;
vi dist;
queue<int> q;
vector<bool> visitado
	visitados[n]=1;//es;
void bfs(int n){stoy visitando el nodo n
	int u,v;
	q.push(n);//ponemos a la cola al primer nodo
	dist[n]=0;//para empezar la distancia es 0
	while(!q.empty()){//mientras la cola no este vacia
		u=q.front();//u tiene el nodo actual, al cual estoy visitando
		q.pop();//saca al nodo de la cola
		for(int i=0;i<g[u].size();i++){
			v=g[u][i];
			if(!visitados[v]){//si no esta visitado el nodo v
				q.push(v);//ponemos el nodo v a la cola
				padres[v]=u;//el padre de v es u
				dist[v]=dist[u]+1;//la distancia de v es la distancia 
				//de su padre u + 1
				visitados[v]=1;//marco como vistado al nodo v
			}
		}
	}
}
int main(){
	int nodos,arcos,a,b;
	cin>>nodos>>arcos;
	g.assign(nodos,vi());
	dist.assign(nodos,-1);//Iniciamos el vector de distancias
	padres.assign(nodos,-1);//Iniciamos el vector de padres
	visitados.assign(nodos,0);
	for(int i=0;i<arcos;i++){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	bfs(0);
	for(int i=0;i<nodos;i++){
		cout<<padres[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<nodos;i++){
		cout<<dist[i]<<" ";
	}
	cout<<endl;
	
	cout<<"BIENVENIDO A FORUM";
	return 0;
}