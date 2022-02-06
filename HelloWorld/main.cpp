#include <iostream>

using namespace std;

int idade;
float taxaAdesao=150, mensalidade, total;
char sexo, plano;

int main() {

    cout << "Qual seu sexo? (M, F)" << endl;
    cin >> sexo;
    cout << "Quanto anos voce tem?" << endl;
    cin >> idade;
    cout << "Qual o plano desejado? (A, B, C)" << endl;
    cin >> plano;

    if(idade < 40 && idade > 0)
    {

    switch(plano){
        case 'A':
            mensalidade = 250;
        break;
        case 'B':
            mensalidade = 370;
        break;
        case 'C':
            mensalidade = 530;
        break;
                }

        if(sexo == 'M' && idade <= 18)
    {
        taxaAdesao = 0;

    }else if(sexo == 'F' && idade >= 18 && idade <= 25 && (plano == 'A' || plano == 'B'))
    {
        mensalidade = mensalidade-(mensalidade*0.10);
    }else if (idade > 35 && plano == 'C')
    {
        mensalidade = 600;
    }
    }else
    {
        cout << "Idade imcompativel com nossos planos." << endl;
    }

    cout << "Plano escolhido: " << plano << endl;
    cout << "Valor da taxa de Adesão: R$" << taxaAdesao << endl;
    cout << "Mensalidade: R$" << mensalidade << endl;
    cout << "Total a ser pago: R$" << mensalidade + taxaAdesao << endl;


return 0;
}
