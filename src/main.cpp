#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <unistd.h>

using namespace std;

struct CardNumber
{
  string number;
  bool verify = false;
};

struct BingoCard
{
  int cardID;
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
int callNumber();
void bingoGame(BingoCardsStack *stack);
void markBingoCards(BingoCardsStack *stack, int calledNumber);
bool checkBingoCard(BingoCardsStack *stack);
void resetCalledNumbers();

int numberCollection[75] = {0};
bool columnChecked = false;
bool lineChecked = false;

int main()
{
  srand(time(NULL));
  int *BingoCardQuantity;
  int option;
  int CardIDController = 0;

  BingoCardsStack *userStack = initStack();

  do
  {
    int choice = menu();

    switch (choice)
    {
    case 1:
      if (userStack->top == NULL)
      {
        cout << "Você nao tem cartelas para jogar... Sinto muito 😔" << "\n";
        break;
      }

      cout << "Iniciando Jogo..." << "\n";
      sleep(2);
      cout << "Remexendo o saco...";
      sleep(2);
      cout << "Começou!!" << "\n";

      bingoGame(userStack);
      resetCalledNumbers();
      destroyStack(userStack);
      break;

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
      delete userStack;
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
  // 0 -> B, 1 -> I, 2 -> N, 3 -> G, 4 -> O
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
  newNodeCard->card->cardID = stack->size;
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

int callNumber()
{
  int number = 0;

  do
  {
    number = rand() % 75 + 1;

  } while (numberCollection[number - 1] == number);

  numberCollection[number - 1] = number;
  return number;
}

void bingoGame(BingoCardsStack *stack)
{
  bool stop = false;

  while (stop == false)
  {
    int calledNumber = callNumber();
    cout << "Numero chamado é... " << calledNumber << "\n";
    markBingoCards(stack, calledNumber);
    sleep(1);
    cout << "\n";
    stop = checkBingoCard(stack);
  }
}

void markBingoCards(BingoCardsStack *stack, int calledNumber)
{
  NodeCard *topCard = stack->top;
  int j;

  if (calledNumber >= 1 && calledNumber <= 15)
  {
    j = 0;
  }
  else if (calledNumber > 15 && calledNumber <= 30)
  {
    j = 1;
  }
  else if (calledNumber > 30 && calledNumber <= 45)
  {
    j = 2;
  }
  else if (calledNumber > 45 && calledNumber <= 60)
  {
    j = 3;
  }
  else if (calledNumber > 60 && calledNumber <= 75)
  {
    j = 4;
  }

  string converted = to_string(calledNumber);

  while (topCard != NULL)
  {
    for (int i = 0; i < 5; i++)
    {
      if (topCard->card->cardItems[i][j]->number == converted)
      {
        topCard->card->cardItems[i][j]->verify = true;
        cout << "Numero " << calledNumber << " marcado na cartela " << topCard->card->cardID << ".\n";
      }
    }
    topCard = topCard->nextNodeCard;
  }
}

bool checkBingoCard(BingoCardsStack *stack)
{
  NodeCard *topCard = stack->top;
  bool bingo = false;

  while (topCard != NULL && bingo == false)
  {
    int fullHouseMarked = 0, lineMarked, columnMarked;

    for (int i = 0; i < 5; i++)
    {
      lineMarked = 0;
      columnMarked = 0;

      for (int j = 0; j < 5; j++)
      {
        if (topCard->card->cardItems[i][j]->verify == true)
        {
          fullHouseMarked++;
          lineMarked++;
        }
        if (topCard->card->cardItems[j][i]->verify == true)
        {
          columnMarked++;
        }
      }

      if (lineMarked == 5 && lineChecked == false)
      {
        lineChecked = true;
        cout << "LINHA na cartela " << topCard->card->cardID << ".\n";
      }

      if (columnMarked == 5 && lineChecked == false)
      {
        columnChecked = true;
        cout << "COLUNA na cartela " << topCard->card->cardID << ".\n";
      }
    }

    if (fullHouseMarked == 24)
    {
      cout << "OLHA A BOAAA na cartela " << topCard->card->cardID << ".\n";
    }
    else if (fullHouseMarked == 25)
    {
      cout << "BINGOOOOOOO na cartela " << topCard->card->cardID << "!!!\n\n";
      bingo = true;
      sleep(3);
    }
    topCard = topCard->nextNodeCard;
  }
  return bingo;
}

void resetCalledNumbers()
{
  for (int i = 0; i < 75; i++)
  {
    numberCollection[i] = 0;
  }
}