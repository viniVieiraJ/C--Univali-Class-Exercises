#include <iostream>

using namespace std;
int main() {
    int Sv;
    int vi[10];
    int viIndexCount = 0;

    do{
    cout << "Insira o tamanho dos vetores." << endl;
    cin >> Sv;
    }while(Sv > 10 || Sv < 1);

    int vx[Sv], vy[Sv];

    cout << "Insira os valores de vx:" << endl;
    for(int i = 0; i < Sv; i++)
    {
        cin >> vx[i];
    }

    cout << "Insira os valores de vy:" << endl;
    for(int i = 0; i < Sv; i++)
    {
        cin >> vy[i];
    }

    for (int x : vx)
    {
        for (int y : vy)
        {
        if(x == y)
        {
            vi[viIndexCount++] = x;
        }
        }
    }

    cout << "VX   VY   VI" << endl;
    for (int i; i < Sv; i++)
    {
        if(i<viIndexCount){
        cout << vx[i] << " - " << vy[i] << " - "  << vi[i] << endl;
        }else
        {
        cout << vx[i] << " - " << vy[i] << " - XX"  << endl;
        }
    }
}
