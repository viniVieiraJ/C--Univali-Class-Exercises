#include <iostream>

using namespace std;

    const int MAXTEMP = 5;

    float menor;
    int i, vetor[MAXTEMP];
int main()
{

    for (i = 0; i < MAXTEMP; i++)
    {
        cout << "Insira a temperatura " << i + 1 << endl;
        cin >> vetor[i];
    }

    menor = vetor[0];

    for (i = 1; i < MAXTEMP; i++)
    {

        if(vetor[i] < menor)
        {
            menor = vetor[i];
        }
    }

    cout << "Vetor lido!" << endl;

    for (i = 0; i < MAXTEMP; i++)
    {

        cout << vetor[i] << endl;

    }
        cout << "\nMenor temperatura: " << menor << endl;

    return 0;
}
