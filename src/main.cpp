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
  cout << "| 1 - OBTER CARTELA      |" << endl;
  cout << "| 2 - ...                |" << endl;
  cout << "| 3 - ...                |" << endl;
  cout << "| 4 - ...                |" << endl;
  cout << "| 0 - SAIR               |" << endl;
  cout << "|========================|" << endl;
}