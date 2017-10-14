#include <iostream>
#include <queue>
using namespace std;
int AF[4]={-1,0,1,0};
int AC[4]={0,1,0,-1};
int MATRIX[110][110];
int belu;
int massi;
int main()
{
    queue<int>F;
    queue<int>C;
    int  cp,fini,cini,ffin,cfin;
    int filas,columnas;
    char aux;
    cin>>cp;
    while(cp--)
    {
        cin>>filas>>columnas;
        for(int i=0;i<filas;i++)
            for(int j=0;j<columnas;j++)
            {
                cin>>aux;
                if(aux=='*')
                    MATRIX[i][j]=-1;
                else
                    MATRIX[i][j]=0;
                if(aux=='$')
                {
                    fini=i;
                    cini=j;
                }
                if(aux=='#')
                {
                    ffin=i;
                    cfin=j;
                }
            }
        F.push(fini);
        C.push(cini);
        int ff,cc;
        while(!F.empty() and !C.empty())
        {
            ff=F.front();
            cc=C.front();
            F.pop();
            C.pop();
            for(int i=0;i<4;i++)
            {
              //  if(MATRIX[ff][cc]==0)
                //{
                if((ff+AF[i]>=0) and (ff+AF[i]<filas) and (cc+AC[i]>=0) and (cc+AC[i]<columnas) and  MATRIX[ff+AF[i]][cc+AC[i]]==0)
                {
                    F.push(ff+AF[i]);
                    C.push(cc+AC[i]);
                    MATRIX[ff+AF[i]][cc+AC[i]]=MATRIX[ff][cc]+1;
                }
            }
        }
      /* for(int i=0;i<filas;i++)
        {
            for(int j=0;j<columnas;j++)
            {
                cout<<MATRIX[i][j]<<" ";
            }
            cout<<endl;
        }*/
        if(MATRIX[ffin][cfin]==0)
            cout<<"-1"<<endl;
        else
            cout<<MATRIX[ffin][cfin]<<endl;
    }
 
    return 0;
}
