#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
vector<vi> g;
vector<bool> visitados;//Para controlar cuando un nodo
//esta o no esta visitado
//0 si no esta visitado
//1 si esta visitado
void dfs(int n){//iniciamos el DFS
	cout<<"ESTOY VISITANDO AL NODO "<<n<<endl;
	visitados[n]=1;
	for(int i=0;i<g[n].size();i++){//TRATA de visitar a todos los vecinos
		int v=g[n][i];//v me dice a que nodo QUIERO ir
		if(visitados[v]==0){//if(!visitados[v]) Si no esta visitado
			dfs(v);
		}
	}
}
int main(){
	int nodos,arcos,a,b;
	cin>>nodos>>arcos;
	g.assign(nodos,vi());
	visitados.assign(nodos,0);	//asignar los nodos como NO visitados
	for(int i=0;i<arcos;i++){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);//Manda el DFS desde el nodo 0
	return 0;
}
