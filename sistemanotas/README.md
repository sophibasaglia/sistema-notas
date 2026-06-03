# 📊 Sistema de Notas v4.1

> Trabalho final desenvolvido para a disciplina de **LOPAL (Lógica de Programação e Algoritmos)** no SENAI-SP.

O **Sistema de Notas** é uma aplicação de console desenvolvida em C++ que visa facilitar o gerenciamento escolar. O software permite cadastrar estudantes, inserir notas de múltiplas disciplinas, calcular médias automaticamente, classificar o status acadêmico de cada aluno e exportar/importar relatórios consolidados com carimbo de data e hora.

---

## 🚀 Funcionalidades

O sistema conta com um menu interativo e as seguintes operações:

* **Cadastro Customizado:** Registro de até 20 alunos e até 5 disciplinas por relatório.
* **Cálculo Automatizado:** Processamento de médias aritméticas individuais de forma dinâmica.
* **Classificação de Status:** Divisão automática dos alunos com base nos critérios de nota.
* **Persistência de Dados (I/O):** Salva o relatório gerado em um arquivo externo `relatorio.txt` contendo a data e a hora exata da geração.
* **Leitura de Histórico:** Opção de visualizar diretamente no console o último relatório salvo, sem necessidade de abrir o arquivo de texto manualmente.
* **Menu Informativo:** Tela "Sobre o sistema" com os dados da desenvolvedora e versão da aplicação.

---

## 📈 Regras de Negócio e Classificação

O sistema valida as notas de **0 a 10** e aplica a seguinte lógica para determinar a situação do aluno:

| Média Final | Status |
| :--- | :--- |
| $M\text{édia} > 7.0$ | 🟢 **Aprovado** |
| $5.0 \le M\text{édia} \le 7.0$ | 🟡 **Recuperação** |
| $M\text{édia} < 5.0$ | 🔴 **Reprovado** |

---

## 🛠️ Tecnologias Utilizadas

O projeto foi construído puramente em **C++**, utilizando as seguintes bibliotecas nativas:
* `<iostream>`: Entrada e saída de dados via console.
* `<string>`: Manipulação de cadeias de caracteres (nomes dos alunos).
* `<fstream>`: Manipulação e persistência de arquivos de texto (`ifstream` e `ofstream`).
* `<ctime>`: Captura do horário do sistema para o relatório.
* `<windows.h>`: Configuração do encoding do console para `UTF-8` (`65001`), garantindo a exibição correta de acentos.

---

## 💻 Como Executar o Projeto

### Pré-requisitos
Você precisará de um compilador C++ instalado em sua máquina (como o `GCC/G++` via MinGW no Windows) ou de uma IDE como VS Code, Code::Blocks ou Dev-C++.

### Passo a Passo

1. **Clone ou baixe o repositório** contendo o arquivo `.cpp`.
2. **Abra o terminal** na pasta onde o arquivo está salvo.
3. **Compile o código** com o seguinte comando no terminal:
   ```bash
   g++ -o main