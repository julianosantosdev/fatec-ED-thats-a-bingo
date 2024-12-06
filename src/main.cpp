#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <unistd.h>
#include <fstream>
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

BingoCardsStack *initStack();
BingoCard *generateBingoCard();

int menu();
int generateNumbers(int column);
void push(BingoCardsStack *stack, BingoCard *NewCard);
bool verifyRepeated(BingoCard *bingoCard, string generatedNumber, int cardLine, int cardColumn);
void readBingoCards(BingoCardsStack *stack);
void deleteBingoCard(BingoCard *bingoCard);
void destroyBingoCards(BingoCardsStack *stack);
void pop(BingoCardsStack *stack);
int callNumber();
void bingoGame(BingoCardsStack *stack);
void markBingoCards(BingoCardsStack *stack, int calledNumber);
bool checkBingoCard(BingoCardsStack *stack);
void resetCalledNumbers();
void createBingoCardTXT(BingoCardsStack *stack);
void waitForUser();

int numberCollection[75] = {0};
bool columnChecked = false;
bool lineChecked = false;

int main()
{
  srand(time(NULL));
  int option;
  int CardIDController = 0;

  BingoCardsStack *userStack = initStack();

  do
  {
    int choice = menu();

    switch (choice)
    {
    case 1:
      option = choice;
      if (userStack->top == NULL)
      {
        cout << "Você nao tem cartelas para jogar... Sinto muito 😔" << ".\n\n";
        break;
      }

      cout << "Iniciando Jogo..." << "\n\n";
      sleep(2);

      cout << "Embaralhando números..." << "\n\n";
      sleep(2);

      cout << "Ativando sistema antifraude..." << "\n\n";
      sleep(2);

      cout << "Chamando o Tigrinho 🐯..." << "\n\n";
      sleep(2);

      cout << "E... Começou!!!" << "\n\n";

      bingoGame(userStack);
      resetCalledNumbers();

      // destroyBingoCards(userStack); 
      // Destruir as cartas ao final da partida. Comentado porque assim posso exibir novamente as cartas mas com as marcacoes.

      lineChecked = false;
      columnChecked = false;
      break;

    case (2):
      option = choice;
      int quantity;
      cout << "Com quantas cartelas deseja Bingar? : ";
      cin >> quantity;
      cout << "\n\n";

      while (quantity != 0)
      {
        push(userStack, generateBingoCard());
        createBingoCardTXT(userStack);
        quantity--;
      }
      break;

    case 3:
      option = choice;
      readBingoCards(userStack);
      break;

    case 4:
      option = choice;
      destroyBingoCards(userStack);
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
  cout << "\033[1;32m";
  cout << "|=========  MENU  =======|" << endl;
  cout << "| 1 - INICIAR JOGO       |" << endl;
  cout << "| 2 - OBTER CARTELA      |" << endl;
  cout << "| 3 - VER CARTELAS       |" << endl;
  cout << "| 4 - DELETAR CARTELA    |" << endl;
  cout << "| 0 - ENCERRAR BINGO     |" << endl;
  cout << "|========================|" << endl;
  cout << "\033[1;0m";

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

void destroyBingoCards(BingoCardsStack *stack)
{
  if (stack->top == NULL)
  {
    cout << "Você nao tem cartelas para deletar..." << "\n";
  };

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
    cout << "ID DA CARTELA: " << topCard->card->cardID << "\n";
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        if (topCard->card->cardItems[i][j]->verify == true)
        {
          cout << "|\t" << "\033[1;31m" << topCard->card->cardItems[i][j]->number << "\033[1;0m" << "\t";
        }
        else
        {
          cout << "|\t" << topCard->card->cardItems[i][j]->number << "\t";
        }
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

    cout << "\033[1;36m" << "Numero chamado é... " << calledNumber << ".\033[1;0m\n";

    markBingoCards(stack, calledNumber);
    sleep(3);
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

    int lineMarked, columnMarked, fullHouseMarked = 0;

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
        cout << "\033[1;33m" << "LINHA na cartela " << topCard->card->cardID << "!\033[1;0m\n";
        waitForUser();
      }

      if (columnMarked == 5 && columnChecked == false)
      {
        columnChecked = true;
        cout << "\033[1;33m" << "COLUNA na cartela " << topCard->card->cardID << "!\033[1;0m\n";
        waitForUser();
      }
    }

    if (fullHouseMarked == 24)
    {
      cout << "OLHA A BOAAA na cartela " << topCard->card->cardID << "!!\n\n";
      sleep(1);
    }
    else if (fullHouseMarked == 25)
    {
      cout << "TEMOS UM GANHADOR...🤑🫣" << "\n";
      sleep(5);
      cout << "🎉🎉🎉🥳🥳🥳🏆🏆🏆 \033[5;37;104m" << "  BINGOOOOOOO na cartela " << topCard->card->cardID << "!!!  \033[1;0m 🏆🏆🏆🥳🥳🥳🎉🎉🎉\n\n\n";
      bingo = true;
      waitForUser();
      break;
    }
    topCard = topCard->nextNodeCard;
  }
  return bingo;
}

void createBingoCardTXT(BingoCardsStack *stack)
{
  int cardNumber = stack->top->card->cardID;
  string filename = "bingoCard" + to_string(cardNumber) + ".txt";
  ofstream bingoCardTXT;
  bingoCardTXT.open(filename);

  bingoCardTXT << "ID DA CARTELA: " << cardNumber << "\n\n";
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      bingoCardTXT << "|\t " << stack->top->card->cardItems[i][j]->number << "\t ";
    }
    bingoCardTXT << "|\n";
  }
  bingoCardTXT << "\n";

  bingoCardTXT.close();
}

void resetCalledNumbers()
{
  for (int i = 0; i < 75; i++)
  {
    numberCollection[i] = 0;
  }
}

void waitForUser()
{
  int stop;

  do
  {
    cout << "Digite 1 para continuar: ";
    cin >> stop;
    cout << "\n";
  } while (stop != 1);
}