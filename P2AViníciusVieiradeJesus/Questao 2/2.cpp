#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int a, b, tempA, tempB, restoAB;
    bool numValidos = false;

    do{
    cout << "Digite o valor de A:" << endl;
    cin >> a;

    cout << "Digite o valor de B:" << endl;
    cin >> b;

    if(a > 0 && b > 0)
    {
        numValidos = true;
    }else
    {
        system("cls");
        cout << "A e B devem ser positivos!" << endl;
    }
    }while(!numValidos);

    do{
        restoAB = a%b;

        a = b;
        b = restoAB;

    }while(restoAB != 0);

    cout << "M.D.C é: " << a;


    return 0;
}
