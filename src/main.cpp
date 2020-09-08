#include <bits/stdc++.h>
#include "../inc/discipline.hpp"
#include "../inc/graph.hpp"

using namespace std;

void tutorial();
void pause(float delay1);

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  const int N = 50;
  Graph g(N);
  g.assign_idx_to_disciplines();
  g.assign_idx_to_prerequisites();
  g.add(5, 0); g.add(9, 0); g.add(10, 5);
  g.add(13, 8); g.add(14, 8); g.add(15, 1);
  g.add(17, 11); g.add(18, 15); g.add(19, 1);
  g.add(20, 13); g.add(21, 16); g.add(22, 15);
  g.add(23, 18); g.add(24, 18); g.add(25, 21);
  g.add(26, 20); g.add(27, 19); g.add(28, 19);
  g.add(29, 23); g.add(30, 18); g.add(31, 24);
  g.add(32, 26); g.add(33, 25); g.add(34, 0);
  g.add(35, 30); g.add(36, 15); g.add(37, 26);
  g.add(38, 32); g.add(39, 35); g.add(40, 30);
  g.add(42, 22); g.add(44, 43);
  int option = -1;
  system("clear");
  cout << "\t\tHello, amigo de software! Vou te mostrar um menu de opções.\n\n\n";
  do {
    int input;
    cout << "Aqui está o menu de opções!\n\n\n";
    cout << "1 - Listar disciplinas do curso de Engenharia de Software\n";
    cout << "2 - Gerar o caminho de pré-requisitos para uma determinada matéria usando DFS\n";
    cout << "3 - Gerar o caminho de pré-requisitos para uma determinada matéria usando BFS\n";
    cout << "4 - Saber se uma matéria é alcançavel a partir de outra\n";
    cout << "5 - Mostrar o grau de conectividade de uma disciplina\n";
    cout << "6 - Mostrar o grafo\n";
    cout << "7 - Tutorial sobre DFS\n";
    cout << "0 - Sair\n";
    cout << "Digite a opção desejada: ";
    cin >> option;
    vector<bool> vis(N, false);
    system("clear");
    switch (option) {
      case 1: {
        Discipline d;
        d.show_disciplines();
        break;
      }
      case 2: {
        cout << "Índice, nome e código das disciplinas\n";
        cout << '\n';
        for (auto [k, v] : g.mdisciplines) {
          cout << k << ": " << v.first << " & " << v.second << '\n'; 
        }
        cout << "Por favor, digite o índice da disciplina que você quer saber os pré-requisitos! Lembrando que esse método usa a DFS: ";
        cin >> input;
        g.dfs(input, vis);
        reverse(g.prerequisites.begin(), g.prerequisites.end());
        system("clear");
        cout << "Esse é o caminho que você precisa percorrer para chegar em " << g.mdisciplines[input].first << ", em ordem!\n";
        bool first = true;
        if (g.prerequisites[0] == input) {
          cout << "Essa disciplina não possui pré-requisitos!\n";
        } else {
          for (int i = 0; i < (int) g.prerequisites.size(); i++) {
            if (g.mprerequisites[g.prerequisites[i]].first == "NULL") {
              continue;
            }
            if (!first) {
              cout << " -> ";
            }
            cout << "[" << g.mprerequisites[g.prerequisites[i]].first  << " & " << g.mprerequisites[g.prerequisites[i]].second << "]";
            first = false;
          }
          cout << " -> [" << g.mdisciplines[input].first << " & " << g.mdisciplines[input].second << "]\n";
          g.prerequisites.clear();
        }
        break;
      }
      case 3: {
        cout << "Índice, nome e código das disciplinas\n";
        cout << '\n';
        for (auto [k, v] : g.mdisciplines) {
          cout << k << ": " << v.first << " & " << v.second << '\n'; 
        }
        cout << "Por favor, digite o índice da disciplina que você quer saber os pré-requisitos! Lembrando que esse método usa a BFS: ";
        cin >> input;
        g.bfs(input, vis);
        reverse(g.prerequisites.begin(), g.prerequisites.end());
        system("clear");
        bool first = true;
        if (g.prerequisites[0] == input) {
          cout << "Essa disciplina não possui pré-requisitos!\n";
        } else {
          cout << "Esse é o caminho que você precisa percorrer para chegar em " << g.mdisciplines[input].first << ", em ordem!\n";
          for (int i = 0; i < (int) g.prerequisites.size(); i++) {
            if (g.mprerequisites[g.prerequisites[i]].first == "NULL") {
              continue;
            }
            if (!first) {
              cout << " -> ";
            }
            cout << "[" << g.mprerequisites[g.prerequisites[i]].first  << " & " << g.mprerequisites[g.prerequisites[i]].second << "]";
            first = false;
          }
          cout << " -> [" << g.mdisciplines[input].first << " & " << g.mdisciplines[input].second << "]\n";
          g.prerequisites.clear();
        }
        break;
      }
      case 4: {
        cout << "Índice, nome e código das disciplinas\n";
        cout << '\n';
        for (auto [k, v] : g.mdisciplines) {
          cout << k << ": " << v.first << " & " << v.second << '\n';
        }
        cout << "Por favor, digite o índice da disciplina que você quer alcançar: ";
        int end;
        cin >> end;
        cout << "Agora, por favor, digite o índice da discipline inicial, para saber se a partir dessa disciplina, você conseguirá alcançar a disciplina " << g.mdisciplines[end].first << ": ";
        int start;
        cin >> start;
        bool ok = g.is_reachable(end, start, vis);
        system("clear");
        if (ok) {
          cout << "A disciplina [" << g.mdisciplines[end].first << " & " << g.mdisciplines[end].second << "] é alcaçavel a partir da disciplina [" << g.mdisciplines[start].first << " & " << g.mdisciplines[start].second << "]\n";
        } else {
          cout << "A disciplina [" << g.mdisciplines[end].first << " & " << g.mdisciplines[end].second << "] não é alcaçavel a partir da disciplina [" << g.mdisciplines[start].first << " & " << g.mdisciplines[start].second << "]\n";
        }
        cout << "Para saber o caminho que você deve percorrer, basta usar a DFS ou a BFS\n";
        break;
      }
      case 5: {
        cout << "Índice, nome e código das disciplinas\n";
        cout << '\n';
        for (auto [k, v] : g.mdisciplines) {
          cout << k << ": " << v.first << " & " << v.second << '\n'; 
        }
        cout << "Por favor, digite o índice da disciplina para saber o grau de conectividade: ";
        cin >> input;
        auto gc = g.connectivity_level(input);
        system("clear");
        cout << "Este é o grau de conectividade da disciplina [" << g.mdisciplines[input].first << " & " << g.mdisciplines[input].second << "]\n";
        bool first = true;
        for (int i = 0; i < (int) gc.size(); i++) {
          if (!first) {
            cout << " ";
          }
          cout << gc[i];
          first = false;
        }
        cout << '\n';
        break;
      }
      case 6: {
        system("clear");
        cout << "Visualização do Grafo!\n";
        g.show();
        break;
      }
      case 7: {
        tutorial();
        break;
      }
      case 0: {
        cout << "Muito obrigado, volte sempre!" << endl;
        break;
      }
      default:
        cout << "Digite uma opção válida, por favor!\n";
        break;
    }
    cout << "\n\n\n";
  } while (option != 0);
  return 0;
}

void tutorial()
{
    char lixo;
    string bee = "\U0001F41D";

    system("clear");
    cout << "Seja Muito Bem Vindo ou Bem Vinda ao Tuturial DFs de Grafos\n"
         << endl;
    cout << "\nTecle ENTER para prosseguir";
    setbuf(stdin, NULL);
    scanf("%c", &lixo);
    system("clear");

    system("clear");
    printf("Vamos começar pela definição do nosso Método:\n\n");
    cout << "Na teoria dos grafos, busca em profundidade (ou busca em profundidade-primeiro," << endl;
    cout << "também conhecido em inglês por Depth-First Search - DFS) é um algoritmo usado para" << endl;
    cout << "realizar uma busca ou travessia numa árvore, estrutura de árvore ou grafo. Intuitivamente," << endl;
    cout << "o algoritmo começa num nó raiz (selecionando algum nó como sendo o raiz, no caso de um grafo)" << endl;
    cout << "e explora tanto quanto possível cada um dos seus ramos, antes de retroceder(backtracking)." << endl;

    cout << "\nTecle ENTER para prosseguir";
    setbuf(stdin, NULL);
    scanf("%c", &lixo);
    system("clear");

    cout << "Para facilitar o entedimento, o grafo e montado de forma semelhante a uma árvoré\n"
         << endl;
    cout << "Imagine o seguinte Grafo: 0-1 1-2 1-3 2-4 2-5 3-6 3-7" << endl;
    printf("           0          \n");
    printf("           |          \n");
    printf("           1          \n");
    printf("          / \\          \n");
    printf("        2     3       \n");
    printf("       / \\   / \\       \n");
    printf("      4   5  6   7 \n");

    cout << "Então vamos a demonstração da DFs!!" << endl;

    cout << "\nTecle ENTER para prosseguir";
    setbuf(stdin, NULL);
    scanf("%c", &lixo);
    system("clear");

    printf("           0          \n");
    printf("           |          \n");
    printf("           1          \n");
    printf("          / \\          \n");
    printf("        2     3       \n");
    printf("       / \\   / \\       \n");
    printf("      4   5  6   7 \n");

    cout << "\nDemonstração...\n"
         << endl;

    printf("           0          \n");
    pause(1);
    printf("           |          \n");
    pause(1);
    printf("           1          \n");
    pause(1);
    printf("          /           \n");
    pause(1);
    printf("        2            \n");
    pause(1);
    printf("       /           \n");
    pause(1);
    printf("      4    \n");

    cout << "Chegamos ao ponto mais profundo, hora de voltar um pouco (ponto 2)..." << endl;
    pause(3);

    system("clear");
    printf("           0          \n");
    printf("           |          \n");
    printf("           1          \n");
    printf("          /           \n");
    printf("        2            \n");
    printf("       /        \n");
    printf("      4  \n");

    system("clear");
    printf("           0          \n");
    printf("           |          \n");
    printf("           1          \n");
    printf("          /           \n");
    printf("        2*            \n");
    printf("       / \\        \n");
    cout << "      4";
    pause(1);
    printf("   5\n");

    cout << "Chegamos ao ponto mais profundo, hora de voltar um pouco (ponto 1)..." << endl;
    pause(3);

    system("clear");

    printf("Atualmente o nosso grafo: \n");
    printf("           0          \n");
    printf("           |          \n");
    printf("           1*          \n");
    printf("          /           \n");
    printf("        2            \n");
    printf("       / \\          \n");
    printf("      4   5 \n");

    cout << "Grafo a partir do ponto 1" << endl;
    pause(4);

    system("clear");

    printf("           1          \n");
    pause(1);
    printf("            \\          \n");
    pause(1);
    printf("              3       \n");
    pause(1);
    printf("              /        \n");
    pause(1);
    printf("             6    \n");

    cout << "Chegamos no ponto mais profundo novamente. Vamos ver como nosso grafo esta!" << endl;
    pause(5);

    system("clear");

    printf("           0          \n");
    printf("           |          \n");
    printf("           1          \n");
    printf("          / \\          \n");
    printf("        2    3*       \n");
    printf("       / \\   /       \n");
    printf("      4   5  6 \n");

    cout << "Vamos até o ponto mais profundo do nó 3" << endl;
    pause(5);

    system("clear");
    printf("               3       \n");
    printf("              / \\       \n");
    printf("             6   \\\n");
    pause(2);
    printf("                  7 \n");

    cout << "Chegamos ao nó mais profundo e encerramos toda a busca do nosso Grafo " << bee << endl
         << endl;
    cout << "E assim o grafo é completamente percorrido!" << '\n';
    printf("           0          \n");
    printf("           |          \n");
    printf("           1          \n");
    printf("          / \\          \n");
    printf("        2     3       \n");
    printf("       / \\   / \\       \n");
    printf("      4   5  6   7 \n");
}

void pause(float delay1) {

    if (delay1 < 0.001)
        return; // pode ser ajustado e/ou evita-se valores negativos.

    float inst1 = 0, inst2 = 0;

    inst1 = (float)clock() / (float)CLOCKS_PER_SEC;

    while (inst2 - inst1 < delay1) {
        inst2 = (float)clock() / (float)CLOCKS_PER_SEC;
    }

    return;
}