#include <iostream>
#include <set>
using namespace std;
set<long long> s;
int n,a,b;
void generar(long long x, int y)
{
    if (x>n or y>10) return;
    s.insert(x);
    generar(10*x+a,y+1);
    generar(10*x+b,y+1);
}
 
int main(){
    while(cin>>n)
    {
        for (a=0;a<=9;a++)
            for (b=a+1;b<=9;b++)
                generar(0,0);
        cout<<s.size()-1<<endl;
        s.clear();
    }
    return 0;
}
