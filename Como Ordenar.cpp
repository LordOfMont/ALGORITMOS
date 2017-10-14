#include <iostream>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
 
int main()
{
    //ofstream O("ro.txt");
    int aux,resultado=1;
    map<int,int>X;
    long long mod=1000000007;
    vector<long long>F(10010);
    F[0]=1;
    for(int i=1;i<10010;i++)
    {
        F[i]=(i*F[i-1])%mod;
     //O<<F[i]<<" ";
    }
    int n;
 //   O<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>aux;
        X[aux]++;
    }
    //cout<<X.size()<<endl;
    map<int,int>::iterator it=X.begin();
    for(;it!=X.end();it++)
    {
        if(it->second>1)
        resultado=(resultado*(F[it->second]))%mod;
    }
    cout<<resultado%mod<<endl;
    return 0;
}
