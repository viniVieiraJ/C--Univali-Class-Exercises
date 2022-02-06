#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    const int MAX = 3;
    int MatEsparsa[MAX][MAX], MatCondensada[MAX*MAX][3];
    int i, j, cont;

    for(i=0;i<MAX;i++)
    {
    for(j=0;j<MAX;j++)
    {
        cout << "Informe o valor da posicao da matriz" << endl;
        cin >> MatEsparsa[i][j];
    }
    }

    cont = 0;

    for(i=0;i<MAX;i++)
    {
    for(j=0;j<MAX;j++)
    {
        if(MatEsparsa[i][j] != 0)
        {
            cont++;
            MatCondensada[cont][1] = MatEsparsa[i][j];
            MatCondensada[cont][2] = i;
            MatCondensada[cont][3] = j;
        }
    }
    }

    if(cont < 1)
    {
        cout << "Matriz não possui elemento não nulo" << endl;
    }else
    {
        for(i=0;i<cont;i++)
        {
            cout << MatCondensada[i][1] << MatCondensada[i][2] << MatCondensada[i][3] << endl;
        }
    }


    return 0;
}
