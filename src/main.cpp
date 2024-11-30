#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

struct CardNumber
{
  string number;
  bool verify = false;
};

struct BingoCard
{
  CardNumber *cardItems[5][5];
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

int menu();
// BingoCardsStack *initStack();
int generateNumbers(int column);
void push(BingoCardsStack *stack, BingoCard *NewCard);
BingoCard *generateBingoCard(int quantity);

int main()
{
  srand(time(NULL));
  int *BingoCardQuantity;
  int option = 0;
  do
  {
    int option = menu();
    int choice = 2;

    switch (choice)
    {
    case (2):
      int quantity;
      cout << "Com quantas cartelas deseja Bingar? : ";
      cin >> quantity;

      generateBingoCard(quantity);

      break;

    default:
      break;
    }

  } while (option == 0);

  return 0;
};

int menu()
{
  int option;

  cout << "|=========  MENU  =======|" << endl;
  cout << "| 1 - INICIAR JOGO       |" << endl;
  cout << "| 2 - OBTER CARTELA      |" << endl;
  cout << "| 3 - VER CARTELAS       |" << endl;
  cout << "| 4 - DELETAR CARTELA    |" << endl;
  cout << "| 0 - ENCERRAR BINGO     |" << endl;
  cout << "|========================|" << endl;

  cout << "Selecione uma opção: ";
  cin >> option;
  return option;
};

BingoCardsStack *initStack()
{
  BingoCardsStack *stack = new BingoCardsStack;
  stack->size = 0;
  stack->top = nullptr;
  return stack;
};

BingoCard *generateBingoCard(int quantity)
{
  // TENTAR COLOCAR UMA ANIMACAO DE CARREGAMENTO USANDO FLUSH E SLEEP.
  int generated = 0;

  // matrix[i][j] - melhorar gerar todas as colunas e depois as linhas, ja que as colunas tem o mesmo intervalo numerico
  while (quantity > generated)
  {
    BingoCard *newBingoCard = new BingoCard;
    for (int j = 0; j < 5; j++)
    {
      for (int i = 0; i < 5; i++)
      {
        CardNumber *cardItem;
        string randomNumber = to_string(generateNumbers(j));
        cardItem->number = randomNumber;
        newBingoCard->cardItems[i][j] = cardItem;
      }
    }
  }
  generated++;
  return newBingoCard;
};

int generateNumbers(int column)
/*
  0 -> B
  1 -> I
  2 -> N
  3 -> G
  4 -> 0
*/
{
  int randomNumber;
  switch (column)
  {
  case 0:
    return randomNumber = rand() % 15 + 1;
    break;

  case 1:
    return randomNumber = rand() % 30 + 16;
    break;

  case 2:
    return randomNumber = rand() % 45 + 31;
    break;

  case 3:
    return randomNumber = rand() % 46 + 60;
    break;

  case 4:
    return randomNumber = rand() % 61 + 75;
    break;

  default:
    break;
  }
}

void push(BingoCardsStack *stack, BingoCard *NewCard)
{
  NodeCard *nodeCard = new NodeCard;
  nodeCard->card = NewCard;
  nodeCard->nextCard = stack->top;
  stack->size++;
}

// VERIFICAR NÚMEROS REPETIDOS DURANTE GERAÇÃO DE RANDÔMICO