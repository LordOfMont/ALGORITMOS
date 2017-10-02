#include <iostream>
#include <vector>
using namespace std;
vector<int> p,rank;
void init(int n){
	p.assign(n,-1);
	rank.assign(n,0);
	for(int i=0;i<n;i++){
		p[i]=i;//mi raiz soy io
	}
}
int find(int x){//encontramos la raiz de x
	if(p[x]==x) return x;
	else return p[x]=find(p[x]);
}
void unir(int a,int b){
	int pa=find(a);
	int pb=find(b);
	if(pa!=pb){
		if(rank[pa]<rank[pb]){
			p[pa]=pb;
		}
		else p[pb]=pa;
		if(rank[pa]==rank[pb]) rank[pa]++;
	}
}
int main(){
	int n,a,b;
	cin>>n;
	init(n);
	int inst;
	while(cin>>inst){
		if(inst==1){
			cin>>a>>b;
			unir(a,b);
		}
		if(inst==2){
			cin>>a>>b;
			if(find(a)==find(b))
				cout<<"Estan en el mismo conjunto"<<endl;
			else
				cout<<"No estan en el mismo conjunto"<<endl;
		}
	}
	return 0;
}