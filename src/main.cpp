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
  NodeCard *nextNodeCard;
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
bool verifyRepeated(BingoCard *bingoCard, string generatedNumber, int cardLine, int cardColumn);
void readBingoCards(BingoCardsStack *stack);
void deleteBingoCard(BingoCard *bingoCard);
void destroyStack(BingoCardsStack *stack);
void pop(BingoCardsStack *stack);

int main()
{
  srand(time(NULL));
  int *BingoCardQuantity;
  int option;

  BingoCardsStack *userStack = initStack();

  do
  {
    int choice = menu();

    switch (choice)
    {
    case (2):
      option = choice;
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
      option = choice;
      readBingoCards(userStack);
      break;

    case 4:
      option = choice;
      destroyStack(userStack);
      break;

    case 0:
      option = choice;
      cout << "Encerrando o Bingo..." << endl;
      cout << "Até mais!" << endl;
      break;

    default:
      cout << "Nenhuma opção selecionada..." << endl;
      break;
    }
  } while (option != 0);

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
  // matrix[i][j] - melhor gerar todas as colunas e depois as linhas, ja que cada coluna tem o intervalo numerico diferente, deixando mais fácil a verificação de repetidos ao invés de percorrer toda a cartela.
  BingoCard *newBingoCard = new BingoCard;
  for (int j = 0; j < 5; j++)
  {
    for (int i = 0; i < 5; i++)
    {
      CardNumber *cardItem = new CardNumber;
      string randomNumber;

      do
      {
        randomNumber = to_string(generateNumbers(j));
      } while (verifyRepeated(newBingoCard, randomNumber, i, j));

      cardItem->number = randomNumber;
      newBingoCard->cardItems[i][j] = cardItem;
    }
  }

  newBingoCard->cardItems[2][2]->number = "FREE";
  newBingoCard->cardItems[2][2]->verify = true;

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
  newNodeCard->nextNodeCard = stack->top;
  stack->top = newNodeCard;
  stack->size++;
};

void pop(BingoCardsStack *stack)
{
  NodeCard *topBingoNodeCard = stack->top;
  NodeCard *nextNodeBingoCard = stack->top->nextNodeCard;
  stack->top = nextNodeBingoCard;

  deleteBingoCard(topBingoNodeCard->card);
  stack->size--;
  delete topBingoNodeCard;
}

void destroyStack(BingoCardsStack *stack)
{
  while (stack->top != NULL)
  {
    pop(stack);
  }
  delete stack;
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
        cout << "|\t" << topCard->card->cardItems[i][j]->number << "\t";
      }
      cout << "|" << endl;
    }
    topCard = topCard->nextNodeCard;
    cout << "\n";
  }
}

bool verifyRepeated(BingoCard *bingoCard, string generatedNumber, int cardLine, int cardColumn)
{
  bool repeated = false;

  for (int i = 0; i < cardLine; i++)
  {
    if (generatedNumber == bingoCard->cardItems[i][cardColumn]->number)
    {
      repeated = true;
      break;
    }
    else
    {
      repeated = false;
    }
  }

  return repeated;
}

void deleteBingoCard(BingoCard *bingoCard)
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      delete bingoCard->cardItems[i][j];
    }
  }
  delete bingoCard;
}

// VERIFICAR NÚMEROS REPETIDOS DURANTE GERAÇÃO DE RANDÔMICO