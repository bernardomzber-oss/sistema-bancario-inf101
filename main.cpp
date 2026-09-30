#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    const int MAX_CONTAS = 5;

    
    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipoConta[MAX_CONTAS];
    double saldo[MAX_CONTAS];
    bool contaAtiva[MAX_CONTAS];

    int totalContas = 0;
    int opcao;

    do {
        cout << "\n********************************\n";
        cout << "**       BANCO BERNARDO       **\n";
        cout << "********************************\n";
        cout << "1 - Cadastrar conta\n";
        cout << "2 - Consultar conta\n";
        cout << "3 - Verificar saldo\n";
        cout << "4 - Alterar tipo da conta\n";
        cout << "5 - Ativar/Desativar conta\n";
        cout << "6 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            case 1: {
                if (totalContas >= MAX_CONTAS) {
                    cout << "Limite de 5 contas atingido.\n";
                    break;
                }

                int novoNumero;
                bool numeroJaExiste = false;

                cout << "\nNumero da conta: ";
                cin >> novoNumero;

                if (novoNumero <= 0) {
                    cout << "Erro: o numero da conta deve ser maior que zero.\n";
                    break;
                }

                
                for (int i = 0; i < totalContas; i++) {
                    if (numeroConta[i] == novoNumero) {
                        numeroJaExiste = true;
                    }
                }

                if (numeroJaExiste) {
                    cout << "Erro: ja existe uma conta com esse numero.\n";
                    break;
                }

                numeroConta[totalContas] = novoNumero;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Nome do titular: ";
                getline(cin, nomeCliente[totalContas]);

                cout << "CPF do titular: ";
                getline(cin, cpf[totalContas]);

                cout << "Tipo da conta (1 = Corrente, 2 = Poupanca): ";
                cin >> tipoConta[totalContas];

                if (tipoConta[totalContas] != 1 &&
                    tipoConta[totalContas] != 2) {

                    cout << "Erro: o tipo da conta deve ser 1 ou 2.\n";
                    break;
                }

                cout << "Saldo inicial: R$ ";
                cin >> saldo[totalContas];

                if (saldo[totalContas] < 0) {
                    cout << "Erro: o saldo inicial nao pode ser negativo.\n";
                    break;
                }

                contaAtiva[totalContas] = true;

                totalContas++;

                cout << "Conta cadastrada com sucesso!\n";

                break;
            }

            case 2: {
                int numeroBusca;
                int indice = -1;

                cout << "\nDigite o numero da conta: ";
                cin >> numeroBusca;

                for (int i = 0; i < totalContas; i++) {
                    if (numeroConta[i] == numeroBusca) {
                        indice = i;
                    }
                }

                if (indice == -1) {
                    cout << "Conta nao encontrada.\n";
                } else {
                    cout << "\n--- DADOS DA CONTA ---\n";

                    cout << "Numero: "
                         << numeroConta[indice] << "\n";

                    cout << "Titular: "
                         << nomeCliente[indice] << "\n";

                    cout << "CPF: "
                         << cpf[indice] << "\n";

                    cout << "Tipo: "
                         << (tipoConta[indice] == 1
                             ? "Corrente"
                             : "Poupanca")
                         << "\n";

                    cout << fixed << setprecision(2);

                    cout << "Saldo: R$ "
                         << saldo[indice] << "\n";

                    cout << "Situacao: "
                         << (contaAtiva[indice]
                             ? "Ativa"
                             : "Inativa")
                         << "\n";
                }

                break;
            }

            case 3: {
                int numeroBusca;
                int indice = -1;

                cout << "\nDigite o numero da conta: ";
                cin >> numeroBusca;

                for (int i = 0; i < totalContas; i++) {
                    if (numeroConta[i] == numeroBusca) {
                        indice = i;
                    }
                }

                if (indice == -1) {
                    cout << "Conta nao encontrada.\n";
                }
                else if (!contaAtiva[indice]) {
                    cout << "Operacao nao permitida: "
                            "a conta esta inativa.\n";
                }
                else {
                    cout << fixed << setprecision(2);

                    cout << "Saldo atual: R$ "
                         << saldo[indice] << "\n";
                }

                break;
            }

            case 4: {
                int numeroBusca;
                int indice = -1;
                int novoTipo;

                cout << "\nDigite o numero da conta: ";
                cin >> numeroBusca;

                for (int i = 0; i < totalContas; i++) {
                    if (numeroConta[i] == numeroBusca) {
                        indice = i;
                    }
                }

                if (indice == -1) {
                    cout << "Conta nao encontrada.\n";
                }
                else if (!contaAtiva[indice]) {
                    cout << "Operacao nao permitida: "
                            "a conta esta inativa.\n";
                }
                else {
                    cout << "Novo tipo "
                            "(1 = Corrente, 2 = Poupanca): ";

                    cin >> novoTipo;

                    if (novoTipo != 1 && novoTipo != 2) {
                        cout << "Erro: o tipo da conta "
                                "deve ser 1 ou 2.\n";
                    }
                    else {
                        tipoConta[indice] = novoTipo;

                        cout << "Tipo da conta alterado "
                                "com sucesso!\n";
                    }
                }

                break;
            }

            case 5: {
                int numeroBusca;
                int indice = -1;

                cout << "\nDigite o numero da conta: ";
                cin >> numeroBusca;

                for (int i = 0; i < totalContas; i++) {
                    if (numeroConta[i] == numeroBusca) {
                        indice = i;
                    }
                }

                if (indice == -1) {
                    cout << "Conta nao encontrada.\n";
                }
                else {
                    // Se estiver ativa, fica inativa.
                    // Se estiver inativa, fica ativa.
                    contaAtiva[indice] =
                        !contaAtiva[indice];

                    cout << "A conta agora esta "
                         << (contaAtiva[indice]
                             ? "ATIVA"
                             : "INATIVA")
                         << ".\n";
                }

                break;
            }

            case 6:
                cout << "Encerrando o sistema. Ate logo!\n";
                break;

            default:
                cout << "Opcao invalida. "
                        "Escolha uma opcao de 1 a 6.\n";
        }

    } while (opcao != 6);

    return 0;
}