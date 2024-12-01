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
BingoCardsStack *initStack();
int generateNumbers(int column);
void push(BingoCardsStack *stack, BingoCard *NewCard);
BingoCard *generateBingoCard();
void readBingoCards(BingoCardsStack *stack);
void destroyStack(BingoCardsStack *stack);

int main()
{
  srand(time(NULL));
  int *BingoCardQuantity;
  int option = 0;

  BingoCardsStack *userStack = initStack();

  do
  {
    int choice = menu();

    switch (choice)
    {
    case (2):
      int quantity;
      cout << "Com quantas cartelas deseja Bingar? : ";
      cin >> quantity;

      while (quantity != 0)
      {
        push(userStack, generateBingoCard());
        quantity--;
      }
      break;

    case 3:
      readBingoCards(userStack);
      break;

    case 4:
      destroyStack(userStack);
      break;

    default:
      cout << "Nenhuma opção selecionada..." << endl;
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
  stack->top = NULL;
  return stack;
};

BingoCard *generateBingoCard()
{
  // TENTAR COLOCAR UMA ANIMACAO DE CARREGAMENTO USANDO FLUSH E SLEEP.
  // matrix[i][j] - melhorar gerar todas as colunas e depois as linhas, ja que as colunas tem o mesmo intervalo numerico
  BingoCard *newBingoCard = new BingoCard;
  for (int j = 0; j < 5; j++)
  {
    for (int i = 0; i < 5; i++)
    {
      CardNumber *cardItem = new CardNumber;
      string randomNumber = to_string(generateNumbers(j));
      cardItem->number = randomNumber;
      newBingoCard->cardItems[i][j] = cardItem;
    }
  }
  return newBingoCard;
};

int generateNumbers(int column)
{
  // 0 -> B, 1 -> I, 2 -> N, 3 -> G, 4 -> 0
  int randomNumber = 0;
  switch (column)
  {
  case 0:
    randomNumber = rand() % 15 + 1;
    break;

  case 1:
    randomNumber = rand() % 15 + 16;
    break;

  case 2:
    randomNumber = rand() % 15 + 31;
    break;

  case 3:
    randomNumber = rand() % 15 + 46;
    break;

  case 4:
    randomNumber = rand() % 15 + 60;
    break;
  }
  return randomNumber;
};

void push(BingoCardsStack *stack, BingoCard *newCard)
{
  NodeCard *newNodeCard = new NodeCard;
  if (newNodeCard == NULL)
  {
    exit(1);
  }

  newNodeCard->card = newCard;
  newNodeCard->nextCard = stack->top;
  stack->top = newNodeCard;
  stack->size++;
};

void destroyStack(BingoCardsStack *stack)
{
  while (stack->top != NULL)
  {
  }
};

void readBingoCards(BingoCardsStack *stack)
{
  if (stack->top == NULL)
  {
    cout << "Ainda não há cartelas registradas..." << endl;
  }

  NodeCard *topCard = stack->top;
  while (topCard != NULL)
  {
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        cout << "| " << topCard->card->cardItems[i][j]->number << " ";
      }
      cout << endl;
    }
    topCard = topCard->nextCard;
    cout << "\n";
  }
}

// VERIFICAR NÚMEROS REPETIDOS DURANTE GERAÇÃO DE RANDÔMICO