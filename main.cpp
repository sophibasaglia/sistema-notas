#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(6501);

    // Entrada
    string nomes[20];
    int qtdalunos = 0;

    // Processamento
    cout << "-------------------------" << endl;
    cout << "| SISTEMA DE NOTAS v4.0 |" << endl;
    cout << "-------------------------" << endl;

    do
    {
        cout << "Quantidade de alunos (1 a 20)" << endl;
        cin >> qtdalunos;
    } while (qtdalunos < 1 || qtdalunos > 20);

    cin.ignore();

    for (int i = 0; i < qtdalunos; i++)
    {
        cout << "Nome do aluno " << i + 1 << ": ";
        getline(cin, nomes[i]);
    }

    // Saída
    cout << endl;
    cout << "Alunos cadastrados: " << endl;
    for (int i = 0; i < qtdalunos; i++)
    {
        cout << " " << i + 1 << ". " << nomes[i] << endl;
    }

    return 0;
}