#include <iostream>
using namespace std;
char letra=65;
int tamano;
int kArray[10][10];

void RecursivaParentesis(int i, int j)
{
    if(i==j)
    {
        cout<<letra<<" ";
        letra++;
    }
    else
    {
        cout<<"(";
        RecursivaParentesis(i, kArray[i][j]);
        RecursivaParentesis(kArray[i][j] + 1, j);
        cout<<")";
    }
}
int main(){
    int numMat;
    cout<<"Numero de matrices: "<<endl;
    cin>>numMat;
    tamano=numMat+1;
    int temp[numMat+1];
    
    cout<<"Ingresar arreglo de dimensiones"<<endl;
    for(int i = 0; i <= numMat; i++){
        cin>>temp[i];
    }
    
    int pond[tamano][tamano];
    
    for(int tam = 1; tam < numMat; tam++){
        for(int i = 1; i<numMat-tam + 1; i++){
            int j = i+ tam;
            int tempoPond;
            int k = i;
            int minPond = pond[i][k] + pond[k+1][j] + temp[i-1]*temp[k]*temp[j];
            int cant = i;
            for(; k<j; k++)
            {
                tempoPond = pond[i][k] + pond[k+1][j] + temp[i-1]*temp[k]*temp[j];
                if(tempoPond<minPond)
                {
                    minPond = tempoPond;
                    cant = k;
                }
            }
            
            pond[i][j] = minPond;
            kArray[i][j] = cant;
        }
    }
    RecursivaParentesis(1, numMat);
    cout<<endl;
    return 0;
}

