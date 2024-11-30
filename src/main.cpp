#include <iostream>
using namespace std;

void menu();
BingoCardsStack *startStack();

struct CardNumber
  {
    string number;
    bool verify;
  };

  struct BingoCard
  {
    CardNumber cardItems[5][5];
  };

  struct NodeCard
  {
    BingoCard *card;
    NodeCard *nextCard;
  };

  struct BingoCardsStack
  {
    NodeCard *top;
    int size;
  };

int main()
{
  int *BingoCardQuantity;
  int option;

  

  // for (int i = 0)

  do
  {
    menu();
    cout << "Selecione uma opção: ";
    cin >> option;
  } while (option == 0);

  return 0;
};

void menu()
{
  cout << "|=========  MENU  =======|" << endl;
  cout << "| 1 - INICIAR JOGO       |" << endl;
  cout << "| 2 - OBTER CARTELA      |" << endl;
  cout << "| 3 - VER CARTELAS       |" << endl;
  cout << "| 4 - DELETAR CARTELA    |" << endl;
  cout << "| 0 - ENCERRAR BINGO     |" << endl;
  cout << "|========================|" << endl;
};

BingoCardsStack *startStack()
{
  BingoCardsStack stack = new BingoCardsStack;
  stack->size = 0;
  return stack;
};

void generateBingoCard()
{
}