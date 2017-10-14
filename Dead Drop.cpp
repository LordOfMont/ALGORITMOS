#include <iostream>
#include <vector>
using namespace std;
int main()
{
    unsigned long long mod=1000000007;
    vector<unsigned long long>X(1010,0);
    X[0]=1;
    X[1]=1;
    X[2]=3;
    X[3]=5;
    int aux=0;
    for(int i=4;i<1010;i++)
    {
        if(i%2==0)
            X[i]=((X[i-1]*2)+1)%mod;
        else
            X[i]=((X[i-1]*2)-1)%mod;
    }
    unsigned long long cp;
    cin>>cp;
    unsigned long long num;
    while(cp--)
    {
        cin>>num;
        cout<<X[num]<<endl;
    }
    return 0;
}
