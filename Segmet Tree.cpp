#include <iostream>
#include <vector>
using namespace std;
vector<int>v;
int T[1000];
void crear(int node,int l,int r){
	if(l==r) T[node]=v[l];
	else{
		int mi=(l+r)/2;
		crear(2*node,l,mi);
		crear(2*node+1,mi+1,r);
		T[node]=T[node*2]+T[node*2+1];
	}
}
void update(int pos,int val,int node,int l,int r){
	if(r<pos or l>pos) return;
	else{
		if(l==r) T[node]=val;
		else{
		int mid=(l+r)/2;
		update(pos,val,2*node,l,mid);
		update(pos,val,2*node+1,mid+1,r);
		T[node]=T[2*node]+T[2*node+1];
		}
	}
}
int consulta(int x,int y,int node,int l,int r){
	if(r<x or l>y) return 0;
	if(x<=l and r<=y){
		return T[node];
	}
	else{
		int mid=(l+r)/2;
		return consulta(x,y,2*node,l,mid)+
				consulta(x,y,2*node+1,mid+1,r);
	}
}
int main(){
	int n,x,pos,val,a,b,inst;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	crear(1,0,n-1);
	while(cin>>inst){
		if(inst==1){//update
			cin>>pos>>val;
			update(pos,val,1,0,n-1);
		}
		if(inst==2){//
			cin>>a>>b;
			cout<<consulta(a,b,1,0,n-1)<<endl;			
		}
	}
	return 0;
}