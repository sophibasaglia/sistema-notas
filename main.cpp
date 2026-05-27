#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    // Entrada
    string nomes[20];
    int qtdalunos = 0;
    float notas[20][5];
    float media[20];
    int qtdmaterias;
    int opcaoinicial;

    // Processamento

    // Leitura de alunos (commit 1)
    cout << "-------------------------" << endl;
    cout << "| SISTEMA DE NOTAS v4.0 |" << endl;
    cout << "-------------------------" << endl;
    cout << "1 - Novo relatório" << endl;
    cout << "2 - Ver relatório salvo" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcaoinicial;

    // leitura de arquivo (commit 5) ///// == comparação ///// = atribuição
    if (opcaoinicial == 2)
    {
        ifstream leitura("relatorio.txt");
        if (leitura.is_open())
        {
            string linha;
            cout << "\n";
            while (getline(leitura, linha))
            {
                cout << linha << endl;
            }

            leitura.close();
        }

        else
        {
            cout << "Nenhum relatório encontrado! " << endl;
        }

        return 0;
    }

    // notas e médias (commit 2)
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

    // classificação e relatório (commit 3)

    cout << "-------------" << endl;
    cout << "| RELATÓRIO |" << endl;
    cout << "-------------" << endl;
    int aprovados = 0, recuperacao = 0, reprovados = 0;

    for (int i = 0; i < qtdalunos; i++)
    {
        cout << nomes[i] << " - Média: " << media[i] << " - ";

        if (media[i] > 7)
        {
            cout << "Aprovado!" << endl;
            aprovados++;
        }

        else if (media[i] >= 5)
        {
            cout << "Recuperação!" << endl;
            recuperacao++;
        }

        else
        {
            cout << "Reprovado!" << endl;
            reprovados++;
        }
    }

    cout << "RESUMO: " << endl;
    cout << "Aprovados: " << aprovados << endl;
    cout << "Recuperação: " << recuperacao << endl;
    cout << "Reprovados: " << reprovados << endl;

    // salvar em arquivo (commit 4)

    ofstream arquivo("relatorio.txt");

    if (arquivo.is_open())
    {
        arquivo << "-----------------" << endl;
        arquivo << "|   RELATÓRIO   |" << endl;
        arquivo << "-----------------" << endl;

        for (int i = 0; i < qtdalunos; i++)
        {
            arquivo << nomes[i] << " - Média: " << media[i] << " - ";
            if (media[i] >= 7)
            {
                arquivo << "Aprovado!" << endl;
            }

            else if (media[i] >= 5)
            {
                arquivo << "Recuperação! " << endl;
            }

            else
            {
                arquivo << "Reprovado! " << endl;
            }
        }
        arquivo << "\nRESUMO: " << aprovados << " aprovados, " << recuperacao << " recuperação, " << reprovados << " reprovados." << endl;

        arquivo.close();
        cout << "\nRelatório salvo com sucesso!" << endl;
    }

    else
    {
        cout << "Erro ao criar arquivo" << endl;
    }

    return 0;
}