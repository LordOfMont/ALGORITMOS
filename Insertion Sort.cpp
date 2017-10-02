#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int>A;
	int selec,j,n,x;
	//Leer el vector
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		A.push_back(x);
	}
	//Insertion Sort
	for(int i=1;i<A.size();i++){
		selec=A[i];//escogo al que quiero colocar en lugar correcto
		j=i-1;//para que j comince una posicion antes del que quiero colocar
		//en lugar correcto
		while(j>=0 and A[j]>=selec){
			//primer caso que llegue al final, segundo caso que encuentre
			//un valor menor al que quiero poner en cuyo caso ya encontrare
			//la posicion donde lo quiero introducir
			A[j+1]=A[j];//si no pasa ninguna de las anteriores condiciones
			//se van recorriendo los valores hacia la derecha
			j--;
		}
		A[j+1]=selec;//j+1 es la posicion donde debe esar el valor 
		//que seleccione
	}
	for(int i=0;i<A.size();i++)
		cout<<A[i]<<" ";
	cout<<endl;
	return 0;
}