#include <iostream>
#include <vector>
using namespace std;
vector<int>C(1000010,-1);
void generar_criba()
{
    for(int i=2;i*i<1000010;i++)
    {
        if(C[i]==-1)
        {
            for(int j=i;j<1000010;j+=i)
            {
                if(C[j]==-1)
                    C[j]=i;
            }
        }
    }
}
int main()
{
    int a,b,k,kprima,m,d;
    generar_criba();
 //   for(int i=0;i<100;i++)
   // {
     //   cout<<C[i]<<" ";
   // }
    //cout<<endl;
    while(cin>>a>>b>>k)
    {
        kprima=0;
        if(a%b==0)
        {
            d=a/b;
            //cout<<a<<endl;
            while(d>1)
            {
                kprima++;
                d=d/C[d];
            }
            if(k<=kprima)
                cout<<"SI"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
