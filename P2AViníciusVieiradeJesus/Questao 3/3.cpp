#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    cout << fixed;
    cout.precision(2);

    bool finalizar = false, dadosvalidos = false, novoCadastroValido = false;
    int numCarteiraMotorista, numCarteiraMotoristaMaiorInfrator = 0, qtdMultas, qtdMultasMaiorInfrator = 0;
    float valorMulta, valorTotalDividas, valorArrecadadoDETRAN;
    char novoCadastro;
    string valorTotaldasDividasMotoristas;

    do
    {
        valorMulta, valorTotalDividas = 0;
        do{
        cout << "Informe o numero da sua carteira de motorista:" << endl;
        cin >> numCarteiraMotorista;
        system("cls");

        cout << "Informe a quantidade de multas:" << endl;
        cin >> qtdMultas;
                system("cls");

        if(qtdMultas > 0 && numCarteiraMotorista > 0)
        {
            dadosvalidos = true;
        }else
        {
            system("cls");
            cout << "Numero de carteira de motorista ou multas invalido, tente novamente!" << endl;

        }
        }while(!dadosvalidos);

        for(int i = 1; i <= qtdMultas; i++)
        {
            do{
            system("cls");
            cout << "Informe o valor da multa " << i << endl;
            cin >> valorMulta;


            if(valorMulta > 0)
            {
                valorTotalDividas += valorMulta;

            }else
            {
                system("cls");
                cout << "Valor da multa invalido, tente novamente!" << endl;
            }
            }while(valorMulta <= 0);
        }

        system("cls");
        valorTotaldasDividasMotoristas += "Num Carteira: " + to_string(numCarteiraMotorista) + " / valor total da divida: " + to_string(valorTotalDividas) + "\n";

        valorArrecadadoDETRAN += valorTotalDividas;

        if(qtdMultas > qtdMultasMaiorInfrator)
        {
            qtdMultasMaiorInfrator = qtdMultas;
            numCarteiraMotoristaMaiorInfrator = numCarteiraMotorista;
        }

        cout << "Valor total da dívida de cada motorista: \n" << valorTotaldasDividasMotoristas << "\n\n Total de recursos arrecadados pelo DETRAN:" << valorArrecadadoDETRAN << "\n\n Num Carteira maior infrator: " << numCarteiraMotoristaMaiorInfrator << "\n Quantidade de multas do maior infrator: " << qtdMultasMaiorInfrator << endl;


        do{
        cout << "\n\n Realizar novo cadastro? (S)im/(N)ão" << endl;
        cin >> novoCadastro;

        if(novoCadastro == 'S')
        {
            system("cls");
            break;
        }else if(novoCadastro == 'N')
        {
            finalizar = true;
            break;
        }else
        {
            system("cls");
            cout<< "Valor invalido tente novamente!" << endl;
        }
        }while(true);
    }while(!finalizar);

    return 0;
}
