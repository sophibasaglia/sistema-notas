#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    // Entrada
    string nomes[20];
    int qtdalunos = 0;
    float notas[20][5];
    float media[20];
    int qtdmaterias = 0;
    int opcaoinicial;

    // Inicializando contadores globais com zero
    int aprovados = 0, recuperacao = 0, reprovados = 0;

    // LOOP DO MENU: O programa continuará rodando até digitar 5
    do
    {
        // Menu Interativo
        cout << "\n-----------------------------------" << endl;
        cout << "|      SISTEMA DE NOTAS v4.2      |" << endl;
        cout << "-----------------------------------" << endl;
        cout << "|1 - Novo relatório               |" << endl;
        cout << "|2 - Ver relatório salvo          |" << endl;
        cout << "|3 - Sobre o sistema              |" << endl;
        cout << "|4 - Relatório de reprovados      |" << endl;
        cout << "|5 - Sair do sistema              |" << endl; // Nova opção para encerrar com segurança
        cout << "-----------------------------------" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcaoinicial;

        switch (opcaoinicial)
        {
        case 1:
            {
                // Zerando os contadores para caso um novo relatório seja feito na mesma execução
                aprovados = 0;
                recuperacao = 0;
                reprovados = 0;

                do
                {
                    cout << "Quantidade de alunos (1 a 20): ";
                    cin >> qtdalunos;
                } while (qtdalunos < 1 || qtdalunos > 20);

                cin.ignore(); // Limpa o buffer do teclado

                for (int i = 0; i < qtdalunos; i++)
                {
                    do
                    {
                        cout << "Nome do aluno " << i + 1 << ": ";
                        getline(cin, nomes[i]);
                    } while (nomes[i] == "");
                }

                do
                {
                    cout << endl;
                    cout << "Quantidade de disciplinas (1 a 5): ";
                    cin >> qtdmaterias;
                } while (qtdmaterias < 1 || qtdmaterias > 5);

                for (int i = 0; i < qtdalunos; i++)
                {
                    media[i] = 0;
                    cout << "\nNotas de " << nomes[i] << " :" << endl;
                    float soma = 0;

                    for (int j = 0; j < qtdmaterias; j++)
                    {
                        do
                        {
                            cout << "Notas da disciplina " << j + 1 << " (1 a 10): ";
                            cin >> notas[i][j];
                        } while (notas[i][j] < 0 || notas[i][j] > 10);
                        soma += notas[i][j];
                    }

                    media[i] = soma / qtdmaterias;
                }

                cout << endl;
                cout << "Alunos cadastrados: " << endl;
                for (int i = 0; i < qtdalunos; i++)
                {
                    cout << " " << i + 1 << ". " << nomes[i] << endl;
                }

                cout << "\n-------------" << endl;
                cout << "| RELATÓRIO |" << endl;
                cout << "-------------" << endl;

                int indiceMenor = 0;
                int indiceMaior = 0;

                for (int i = 0; i < qtdalunos; i++)
                {
                    cout << nomes[i] << " - Média: " << media[i] << " - ";

                    if (media[i] >= 7)
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

                    if (media[i] > media[indiceMaior])
                    {
                        indiceMaior = i;
                    }
                    if (media[i] < media[indiceMenor])
                    {
                        indiceMenor = i;
                    }
                }

                cout << "\nRESUMO: " << endl;
                cout << "Aprovados: " << aprovados << endl;
                cout << "Recuperação: " << recuperacao << endl;
                cout << "Reprovados: " << reprovados << endl;
                cout << endl;
                cout << "Maior media: " << nomes[indiceMaior] << " (" << media[indiceMaior] << ")" << endl;
                cout << "Menor media: " << nomes[indiceMenor] << " (" << media[indiceMenor] << ")" << endl;

                // Bloco de salvar arquivo
                {
                    ofstream arquivo("relatorio.txt");

                    if (arquivo.is_open())
                    {
                        time_t agora = time(0);
                        char *dataHora = ctime(&agora);
                        arquivo << "Data do relatorio: " << dataHora << endl;

                        arquivo << "-----------------" << endl;
                        arquivo << "|   RELATÓRIO   |" << endl;
                        arquivo << "-----------------" << endl;

                        for (int i = 0; i < qtdalunos; i++)
                        {
                            arquivo << nomes[i] << " - Média: " << media[i] << " - ";
                            if (media[i] >= 7) { arquivo << "Aprovado!" << endl; }
                            else if (media[i] >= 5) { arquivo << "Recuperação! " << endl; }
                            else { arquivo << "Reprovado! " << endl; }
                        }
                        arquivo << "\nRESUMO: " << aprovados << " aprovados, " << recuperacao << " recuperação, " << reprovados << " reprovados." << endl;

                        arquivo.close();
                        cout << "\nRelatório salvo com sucesso em 'relatorio.txt'!" << endl;
                    }
                }
            }
            break;

        case 2:
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
            }
            break;

        case 3:
            cout << "-------------------------------" << endl;
            cout << "        SOBRE O SISTEMA        " << endl;
            cout << "-------------------------------" << endl;
            cout << "|Sistema de notas v4.2        |" << endl;
            cout << "|Desenvolvido por: Sophia     |" << endl;
            cout << "|Turma: LOPAL 2026 - SENAI-SP |" << endl;
            break;

        case 4:
            {
                // PROTEÇÃO: Só gera se houver algum aluno cadastrado na memória nesta sessão
                if (qtdalunos == 0)
                {
                    cout << "\n[ERRO] Nenhum aluno foi cadastrado ainda! Use a opção 1 primeiro." << endl;
                }
                else
                {
                    ofstream arqreprovados("reprovados.txt");

                    if (arqreprovados.is_open())
                    {
                        time_t agora = time(0);
                        char *dataHora = ctime(&agora);
                        arqreprovados << "Data do relatorio de reprovados: " << dataHora << endl;
                        arqreprovados << "-------------------------------" << endl;
                        arqreprovados << "|     ALUNOS REPROVADOS       |" << endl;
                        arqreprovados << "-------------------------------" << endl;

                        int totalReprovados = 0;
                        for (int i = 0; i < qtdalunos; i++)
                        {
                            if (media[i] < 5)
                            {
                                arqreprovados << nomes[i] << " - Média: " << media[i] << " - Reprovado!" << endl;
                                totalReprovados++;
                            }
                        }

                        if (totalReprovados == 0)
                        {
                            arqreprovados << "Nenhum aluno foi reprovado nesta turma." << endl;
                        }
                        else
                        {
                            arqreprovados << "\nTotal de alunos reprovados: " << totalReprovados << endl;
                        }

                        arqreprovados.close();
                        cout << "\nRelatório de reprovados criado com sucesso em 'reprovados.txt'!" << endl;
                    }
                    else
                    {
                        cout << "Erro ao criar arquivo" << endl;
                    }
                }
            }
            break;

        case 5:
            cout << "\nSaindo do sistema... Até logo!" << endl;
            break;

        default:
            cout << "Opção Inválida!" << endl;
            break;
        }

    } while (opcaoinicial != 5); // O menu repete até que a opção seja 5

    return 0;
}