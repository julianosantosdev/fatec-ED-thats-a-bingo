#include <iostream>
using namespace std;

void menu();

int main()
{
  struct BingoCard
  {
    //char bingo[5] = {'B', 'I', 'N', 'G', 'O'};
    //string freeSpace = "FREE";
    
  };
  int option;
  do
  {
    menu();
    cout << "Selecione uma opção: ";
    cin >> option;
  } while (option == 0);

  return 0;
}

void menu()
{
  cout << "|=========  MENU  =======|" << endl;
  cout << "| 1 - INICIAR JOGO       |" << endl;
  cout << "| 2 - OBTER CARTELA      |" << endl;
  cout << "| 3 - VER CARTELAS       |" << endl;
  cout << "| 4 - DELETAR CARTELA    |" << endl;
  cout << "| 0 - ENCERRAR BINGO     |" << endl;
  cout << "|========================|" << endl;
}

void generateBingoCard() {

}