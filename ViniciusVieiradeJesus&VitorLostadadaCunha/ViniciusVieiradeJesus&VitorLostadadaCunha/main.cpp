#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>


using namespace std;
int main() {
    unsigned option = 0, value, number;
    int tables[2][20] = {{0}}, foods[20] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100} ;
    int EMPTY = 0, RESERVED = 1, BUSY = 2, EXPENSES = 0, STATE = 1, quantity, totalAccumulated = 0;
    bool end = false, reserve = false, found = false;
    string result;
    setlocale(LC_ALL, "portuguese");
    do {
        do {
            cout<< "\n*** Escolha uma opção *** "
                   "\n 1- controle de ocupação de mesas "
                   "\n 2- registrar despesas de uma mesa "
                   "\n 3- calcular valor de uma mesa e emitir nota fiscal"
                   "\n 4- Fechar o dia"
                    << endl;
            cin>>option;
        }while(option > 4);

        switch(option){
            case 1:

                do{
                    system("cls");
                    option = 0;
                    cout << "\n 1- reservar mesa"
                            "\n 2- alterar o status de uma mesa"
                            "\n 3- liberar mesa"
                            << endl;
                    cin>>option;

                }while(option > 3 );

                switch(option){
                    case 1:

                        for(int i = 0; !reserve; i++){
                            if(tables[STATE][i] == EMPTY){
                                if(i < 20){
                                reserve = true;
                                tables[STATE][i] = RESERVED;
                                system("cls");
                                cout << "Mesa numero " << i+1 << " Reservada com sucesso" << endl;
                                }else
                                {
                                system("cls");
                                cout << "Todas as mesas estão ocupadas!" << endl;
                                reserve = true;
                                }
                            }
                        }
                        reserve = false;
                        break;
                    case 2:
                        do{
                            system("cls");
                            cout << "Qual o numero da mesa que deseja alterar" << endl;
                            cin >> value;
                        }while(value > 20);

                        do{
                            option = 0;
                            system("cls");
                            cout << "Qual o estado que deseja colocar?"
                                    "\n 1 - Livre"
                                    "\n 2 - Reservada"
                                    "\n 3 - Ocupada"
                                    << endl;
                            cin >> option;
                        }while(option > 3);

                        tables[STATE][value-1] = option-1;

                        switch(option){
                            case 1:
                                result = "Livre";
                                break;
                            case 2:
                                result = "Reservada";
                                break;
                            case 3:
                                result = "Ocupada";
                                break;
                        }
                        system("cls");
                        cout << "Mesa numero: " << value << " atualizada para " << result << endl;
                        break;
                    case 3:
                        do{
                            system("cls");
                            value = 0;
                            cout << "Qual o numero da mesa que deseja liberar" << endl;
                            cin >> value;
                        }while(value > 20);

                        if(tables[STATE][value-1] == EMPTY && tables[EXPENSES][value-1] == 0){
                            system("cls");
                            cout << "Está mesa já está liberada" << endl;
                        }else{
                            tables[EXPENSES][value-1] = 0;
                            tables[STATE][value-1] = EMPTY;
                            system("cls");
                            cout << "Mesa " << value << " liberada" << endl;
                        }

                        break;
                }

                break;
            case 2:

                do{
                    system("cls");
                    cout << "Qual o numero da mesa" << endl;
                    cin >> value;
                }while(value > 20);

                if(tables[STATE][value-1] == BUSY) {


                    do {
                        system("cls");
                        cout << "Qual o produto?" << endl;
                        cin >> number;
                    } while (number > 20);

                    do {
                        system("cls");
                        cout << "Qual a quantidade" << endl;
                        cin >> quantity;
                    } while (quantity < 1);
                    system("cls");
                    cout << "Pedido realizado" << endl;

                    tables[EXPENSES][value - 1] += foods[number - 1] * quantity;
                }else{
                    system("cls");
                    cout << "Está mesa não está ocupada" << endl;
                }
                break;
            case 3:

                do {
                    system("cls");
                    cout << "Qual o numero da mesa" << endl;
                    cin >> value;
                } while (value > 20);

                if(tables[EXPENSES][value-1] > 0) {
                    system("cls");
                    cout << "O total a pagar da mesa " << value << " é de: R$" << tables[EXPENSES][value - 1]
                         << endl;
                    totalAccumulated += tables[EXPENSES][value - 1];
                }else{
                    system("cls");
                    cout << "Está mesa não tem nada a pagar" << endl;
                }
                break;
            case 4:
                system("cls");
                cout << "O total arrecadado hoje foi de R$" << totalAccumulated << endl;
                end = true;
                break;
        }
    }while(!end);
    return 0;
}
