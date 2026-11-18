// Conversor de bases - ARQUITETURA E ORGANIZACAO DE COMPUTADORES - LAURA GOMES THEODORO
//
//           /\_/\
//          ( o.o )
//           > ^ <3
//

#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <cctype>
using namespace std;

//ETAPA 1: Menu
int main(){
    int BO, BD;
    int baseOrigem, baseDestino;
    bool origemValida, destinoValido;

    //Permite fazer mais de uma conversao
    do {
        do {
            cout << "\n";
            cout << "    /\\_/\\\\\n";
            cout << "   ( o.o )\n";
            cout << "    > ^ <3\n";
            cout << "\n";
            cout << "CONVERSOR DE BASES\n";
            cout << "1. Binario\n";
            cout << "2. Decimal\n";
            cout << "3. Octal\n";
            cout << "4. Hexadecimal\n";
            cout << "5. Vigesimal\n";
            cout << "6. Duodecimal\n";
            cout << "0. Sair\n";
            cout << "Selecione a base de origem:\n";

            //Verifica se foi digitado um numero
            if (!(cin >> BO)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                BO = -1;
            }

            origemValida = true;

            switch (BO) {
            case 1:
                cout << "Binario\n";
                baseOrigem = 2;
                break;
            case 2:
                cout << "Decimal\n";
                baseOrigem = 10;
                break;
            case 3:
                cout << "Octal\n";
                baseOrigem = 8;
                break;
            case 4:
                cout << "Hexadecimal\n";
                baseOrigem = 16;
                break;
            case 5:
                cout << "Vigesimal\n";
                baseOrigem = 20;
                break;
            case 6:
                cout << "Duodecimal\n";
                baseOrigem = 12;
                break;
            case 0:
                cout << "Encerrando o programa...\n";
                return 0;
            default:
                cout << "Oops! Opcao invalida. Tente novamente.\n";
                origemValida = false;
                break;
            }

        } while (!origemValida);

        //Base de destino
        do {
            cout << "\nAgora, selecione a base de destino:\n";
            cout << "1. Binario\n";
            cout << "2. Decimal\n";
            cout << "3. Octal\n";
            cout << "4. Hexadecimal\n";
            cout << "5. Vigesimal\n";
            cout << "6. Duodecimal\n";
            cout << "0. Sair\n";

            if (!(cin >> BD)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                BD = -1;
            }

            destinoValido = true;

            switch (BD) {
            case 1:
                cout << "Binario\n";
                baseDestino = 2;
                break;
            case 2:
                cout << "Decimal\n";
                baseDestino = 10;
                break;
            case 3:
                cout << "Octal\n";
                baseDestino = 8;
                break;
            case 4:
                cout << "Hexadecimal\n";
                baseDestino = 16;
                break;
            case 5:
                cout << "Vigesimal\n";
                baseDestino = 20;
                break;
            case 6:
                cout << "Duodecimal\n";
                baseDestino = 12;
                break;
            case 0:
                cout << "Encerrando o programa...\n";
                return 0;
            default:
                cout << "Oops! Opcao invalida. Tente novamente.\n";
                destinoValido = false;
                break;
            }

            //Evita escolher a mesma base
            if (destinoValido && BO == BD) {
                cout << "A base de destino nao pode ser igual a base de origem.\n";
                destinoValido = false;
            }

        } while (!destinoValido);

        //ETAPA 2: Algoritmos

        string numero;
        bool numeroValido = false;
        unsigned long long decimal = 0;

        //Todos para decimal
        do {
            cout << "\nDigite o numero que deseja converter:\n";
            cin >> numero;

            numeroValido = true;
            decimal = 0;

            //Limita a quantidade de caracteres
            if (numero.length() > 64) {
                cout << "Numero muito longo! Limite de 64 caracteres.\n";
                numeroValido = false;
            }

            //Verifica cada caractere digitado
            if (numeroValido) {
                for (int i = 0; i < (int)numero.length(); i++) {

                    char caractere = toupper((unsigned char)numero[i]);
                    int valor;

                    //Numeros de 0 a 9
                    if (caractere >= '0' && caractere <= '9') {
                        valor = caractere - '0';
                    }
                    //Letras de A ate J
                    else if (caractere >= 'A' && caractere <= 'J') {
                        valor = caractere - 'A' + 10;
                    }
                    else {
                        cout << "Caractere invalido!\n";
                        numeroValido = false;
                        break;
                    }

                    //Verifica se o digito pertence a base
                    if (valor >= baseOrigem) {
                        cout << "Esse digito nao pertence a base escolhida!\n";
                        numeroValido = false;
                        break;
                    }

                    //Evita ultrapassar o limite do numero
                    if (decimal > (ULLONG_MAX - valor) / baseOrigem) {
                        cout << "Numero muito grande para converter!\n";
                        numeroValido = false;
                        break;
                    }

                    //Conversao para decimal
                    decimal = decimal * baseOrigem + valor;
                }
            }

            if (!numeroValido) {
                cout << "Tente novamente.\n";
            }

        } while (!numeroValido);

        cout << "\nValor em decimal: " << decimal << "\n";

        //ETAPA 3: Conversao do decimal para a base de destino

        //String vazia para armazenar os restos
        string resultado = "";

        //Copia do decimal pra continuar dividindo
        unsigned long long quociente = decimal;

        //Simbolos utilizados nas bases
        string simbolos = "0123456789ABCDEFGHIJ";

        //Se o numero for zero, o resultado e zero
        if (quociente == 0) {
            resultado = "0";
        }

        //Lacos de repeticao
        while (quociente > 0) {

            //Guardamos o resto da divisao
            int resto = quociente % baseDestino;

            //Transformamos o resto no simbolo correspondente
            //O simbolo vem ANTES do resultado para inverter a ordem
            resultado = simbolos[resto] + resultado;

            //Dividimos pela base de destino
            quociente = quociente / baseDestino;
        }

        cout << "\nResultado da conversao: " << resultado << "\n";

        cout << "\n----------------------------------\n";
        cout << "Nova conversao!\n";

    } while (true);

    return 0;
}
