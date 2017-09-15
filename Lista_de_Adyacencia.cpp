#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;//SE USA PARA EN LUGAR DE COLOCAR
//vector<int> se colocara vi en todo el codigo
vector<vi> g;//Declaramos nuestro vector de vectores, que en este caso
//representa el grafo
int main(){
	int nodos,arcos,a,b;
	//Suponemos que los arcos estan numerados 0 a nodos-1
	cin>>nodos>>arcos;//Numero de nodos, numero de arcos
	g.assign(nodos,vi());//Asigna o (crea) nodos-casillas y les coloca
	//un vector vacio que se representa con vi() 
	for(int i=0;i<arcos;i++){//leemos los arcos
		cin>>a>>b;//leemos cada arco que consiste en una pareja
		//que nos dice que existe:
		g[a].push_back(b);//conexion de A a B
		g[b].push_back(a);//conexion de B a A
	}
	//Para imprimir el grafo
	for(int i=0;i<g.size();i++){
		cout<<"NODO "<<i<<endl;
		for(int j=0;j<g[i].size();j++)
		{
			cout<<g[i][j]<<" ";
		}		
		cout<<endl;
	}
	return 0;
}
