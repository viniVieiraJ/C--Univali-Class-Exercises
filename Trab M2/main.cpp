#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    cout << fixed;
    cout.precision(2);

    int opc;
    bool caixaaberto = false, finaliza = false, comprando = true, verifmoeda, pago;
    float brlcaixa, usdcaixa, eurcaixa, eqvusd, eqveur, subtotalcompra, subtotalcompranamoeda, valorpago, troco;
    char moedapag, maisproduto = 'S';

    do{
    do
    {
        cout << "Selecione uma opção:\n\n 1 - abrir o caixa\n 2 - novo cliente \n 3 - fechar o caixa\n" << endl;
        cin >> opc;

        if(opc < 1 || opc > 3)
        {
            system("cls");
            cout << "ERRO: opção inválida!" << endl;
        }

    }while(opc < 1 || opc > 3);
    system("cls");

    if(!caixaaberto && opc != 1)
    {
        system("cls");
        cout << "ERRO: Caixa fechado!" << endl;
    }else{
    switch(opc)
    {
    case 1:
        if(!caixaaberto){
        do{
        caixaaberto = true;
        cout << "Informe o valor contido no caixa em BRL:\n" << endl;
        cin >> brlcaixa;
        if(brlcaixa <= 0)
        {
            system("cls");
            cout << "ERRO: O valor do caixa não pode ser menor ou igual a 0(zero)\n" << endl;
        }
        }while(brlcaixa <= 0);
        system("cls");

        do // define equivalencia do dolar e euro
        {
            cout << "Informe quantos reais é 1(um) dólar atualmente (ex: 3.75):\n";
            cin >>  eqvusd;
            system("cls");

            cout << "Informe quantos reais é 1(um) euro atualmente (ex: 3.75):\n";
            cin >>  eqveur;

            if(eqveur <= 0 || eqvusd <= 0)
            {
                system("cls");
                cout << "Erro: Nenhum valor pode ser menor que 0(zero)\n" << endl;
            }
        }while(eqveur <= 0 || eqvusd <= 0);

        system("cls");

        cout << "Caixa aberto!\n\nValor em caixa:\nR$ " << brlcaixa << "\nUSD " << brlcaixa/eqvusd << "\nEUR " << brlcaixa/eqveur << "\n" << endl;
        break;
        }else {cout << "O caixa já está aberto!" << endl; break;}

    case 2:
        subtotalcompra = 0;
        subtotalcompranamoeda = 0;
        do // verifica moeda selecionada
        {
        verifmoeda = false;
        cout << "Com qual moeda será feito o pagamento? Digite R para Real, D para Dólar e E para Euro" << endl;
        cin >> moedapag;
        system("cls");

        if(moedapag != 'R' && moedapag != 'D' && moedapag != 'E')
        {
            cout << "Erro: Apenas três moedas são aceitas, digite: R, D ou E!\n" << endl;
        }else
        {
            verifmoeda = true;
        }
        }while(!verifmoeda);

        float precoproduto, qtdproduto;
        do
        {
            comprando = true;

            cout << "Quanto custa o produto em reais? Ex: 15.24" << endl;
            cin >> precoproduto;

            cout << "\nQuantos desse produto você comprou?\n" << endl;
            cin >> qtdproduto;

            if(qtdproduto > 0 && precoproduto > 0)
            {
                subtotalcompra += precoproduto * qtdproduto;
                system("cls");
                do{
                cout << "Subtotal: " << subtotalcompra << "\nGostaria de adicionar mais um produto? S/N" << endl;
                cin >> maisproduto;
                switch(maisproduto)
                {
                case 'N':
                    comprando = false;
                    system("cls");
                    break;
                case 'S':
                    system("cls");
                    break;

                default:
                    system("cls");
                    cout << "Erro: Insira S ou N!" << endl;
                break;
                }
                }while(maisproduto != 'N' && maisproduto != 'S');
            }else
            {
                system("cls");
                cout << "Erro: O preço/quantidade do produto não pode ser 0(zero) ou negativo!" << endl;
            }

        }while(comprando);
        do
        {
            pago = false;
            cout << "Total da compra:\nBRL: " << subtotalcompra << endl;
            switch(moedapag)
            {
            case 'R':
                subtotalcompranamoeda = subtotalcompra;
                break;
            case 'D':
                subtotalcompranamoeda = subtotalcompra/eqvusd;
                cout << "USD: "<< subtotalcompranamoeda << endl;
                break;
            case 'E':
                subtotalcompranamoeda = subtotalcompra/eqveur;
                cout << "EUR: " << subtotalcompranamoeda << endl;
                break;
            }

            cout << "Informe o valor oferecido pelo cliente para pagar:" << endl;
            cin >> valorpago;

            if(valorpago < subtotalcompranamoeda)
            {
                system("cls");
                cout << "Erro: você não deu dinheiro suficiente para pagar a conta, tente novamente!" << endl;
            }else
            {
                switch(moedapag)
                {
                case 'R':
                    troco = valorpago - subtotalcompra;
                    break;
                case 'D':
                    troco = valorpago*eqvusd - subtotalcompra;
                    break;
                case 'E':
                    troco = valorpago*eqveur - subtotalcompra;
                    break;
                }
                system("cls");
                cout << "Troco: BRL " << troco << endl;
                brlcaixa += subtotalcompra;
                pago = true;
            }
        }while(!pago);

        break;

    case 3:
        cout << "Caixa fechado!\n\nValor em caixa:\nR$ " << brlcaixa << "\nUSD " << brlcaixa/eqvusd << "\nEUR " << brlcaixa/eqveur << "\n" << endl;
        finaliza = true;
        break;
    }
        }
    }while(!finaliza);
    return 0;
}
