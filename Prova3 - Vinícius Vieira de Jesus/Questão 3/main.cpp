#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
    string binary;
    int value, signalBinary, multiplus = 0;

    do
    {
        cout << "Insira a notacao binaria" << endl;
        cin >> binary;
    }while(binary.size()%8 != 0);

    if(binary[0] == '1')
    {
        signalBinary = -1;
        value += (pow(2,binary.length()-1)*signalBinary);
    }else
    {
        signalBinary = 1;
    }

    for(int i = binary.length()-1; i > 0; i--)
    {
        if(binary[i] == '1')
        {
            value += pow(2,multiplus);
        }
        multiplus++;
    }

    cout << "Valor: " << value << "(" << binary << ")" << endl;

}

