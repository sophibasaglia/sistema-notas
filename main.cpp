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
    float notas[20][5];
    float media[20];
    int qtdmaterias;

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

    do
    {
        cout << endl;
        cout << "Quantidade de disciplinas (1 a 5)" << endl;
        cin >> qtdmaterias;
    } while (qtdmaterias < 1 || qtdmaterias > 5);

    for (int i = 0; i < qtdmaterias; i++)
    {
        cout << "Notas de " << nomes[i] << " :" << endl;
        float soma = 0;
        
        for (int j = 0; j < qtdmaterias; j++)
        {
            do 
            {
                cout << "Disciplina " << j + 1 << " (1 a 5): ";
                cin >> notas[i][j];
            } while (notas[i][j] < 0 || notas[i][j] > 10);
            soma += notas[i][j];
        }
        
        media[i] = soma / qtdmaterias;
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