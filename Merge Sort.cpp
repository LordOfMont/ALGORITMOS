#include <iostream>
#include <vector>
using namespace std;
vector<int>A,L,R;
void sort(int l,int r){//indices izquierdo y derecho
	//cout<<"ORDENARE DE "<<l<<" A "<<r<<endl;
	if(l<r){
		
		int med=(l+r)/2;
		sort(l,med);//ordenar parte izquierda
		sort(med+1,r);//ordenar parte derecha
		//cout<<"ACABE MIS HIJOS "<<l<<" "<<r<<endl;
		//MERGE
		L.clear();
		R.clear();
		//Copias en L y R de los pedazos
		for(int i=l;i<=med;i++)
			L.push_back(A[i]);
		for(int i=med+1;i<=r;i++)
			R.push_back(A[i]);
		/*cout<<"L=";
		for(int i=0;i<L.size();i++)
			cout<<L[i]<<" ";
		cout<<endl;
		/*cout<<"R=";
		for(int i=0;i<R.size();i++)
			cout<<R[i]<<" ";
		cout<<endl;*/
		int i,j=0,k=0;//j para L, k para R
		for(i=l;i<=r;i++){
			//COLOCAMOS en la posicion correcta
			if(L[j]<R[k]){
				A[i]=L[j];
				//cout<<"Colocare en A["<<i<<"]="<<L[j]<<endl;
				j++;
			}
			else{
				A[i]=R[k];
				//cout<<"Colocare en A["<<i<<"]="<<A[i]<<endl;
				k++;
			}
			if(j==L.size()){/*cout<<"L llego al final"<<endl;*/ break;}
			if(k==R.size()){/*cout<<"R llego al final"<<endl;*/ break;}
		}
		i++;
		//Lo sobrante
		while(j<L.size()){
			A[i]=L[j];
			//cout<<"Colocare en A["<<i<<"]="<<A[i]<<endl;
			i++;
			j++;
		}
		while(k<R.size()){
			A[i]=R[k];
			//cout<<"Colocare en A["<<i<<"]="<<A[i]<<endl;
			i++;
			k++;
		}
		/*cout<<"ORDENE DE "<<l<<" A "<<r<<endl;
		for(int i=0;i<A.size();i++)
			cout<<A[i]<<" ";
		cout<<endl;*/	
	}
	return;
}
int main(){
	//cout<<"Massi"<<endl;
	int selec,j,n,x;
	//Leer el vector
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		A.push_back(x);
	}
	sort(0,A.size()-1);
	for(int i=0;i<A.size();i++)
		cout<<A[i]<<" ";
	cout<<endl;
	return 0;
}