# Projeto "Olha a Boa" - Cartela de Bingo

O bingo é um jogo que envolve a marcação de números em uma cartela, conforme eles são sorteados aleatoriamente por um chamador.  
O objetivo é preencher uma linha, coluna, ou um padrão específico de números antes dos outros jogadores e anunciar "Bingo!" para sinalizar a vitória.

Com o advento da tecnologia, o bingo também ganhou versões digitais, onde jogadores podem participar remotamente, com números sendo chamados automaticamente e cartelas virtuais sendo preenchidas automaticamente.

Neste projeto, você irá desenvolver um gerenciador de cartelas.

O jogador poderá gerenciar uma ou mais cartelas.

---

## Requisitos do Projeto

### 1. Menu Interativo

- Criar um menu interativo na função `main` que permita ao usuário interagir com o programa.
- Opções no menu:
  - Cadastrar uma ou mais cartelas.
  - Marcar um número na cartela.
  - Visualizar cartelas.
  - Outras interações pertinentes.

### 2. Estrutura de Dados

- Criar estruturas de dados adequadas para armazenar uma lista de cartelas.
- O jogador deve informar quantas cartelas ele quer, e o programa deve gerar as cartelas.

### 3. Estrutura das Cartelas

Cada cartela é organizada em uma grade de 5x5 com 25 quadrados.  
O quadrado central (geralmente chamado de "FREE") é livre e automaticamente preenchido.  
Cada coluna é rotulada com uma das letras da palavra "BINGO" e possui um intervalo específico de números:

Os números em cada coluna são selecionados aleatoriamente dentro de seus intervalos, garantindo que não haja repetições.

| Coluna | Intervalo de Números |
| ------ | -------------------- |
| **B**  | 1 a 15               |
| **I**  | 16 a 30              |
| **N**  | 31 a 45 (com "FREE") |
| **G**  | 46 a 60              |
| **O**  | 61 a 75              |

#### Exemplo:

| **B** | **I** | **N** | **G** | **O** |
| ----- | ----- | ----- | ----- | ----- |
| 12    | 20    | 44    | 54    | 69    |
| 15    | 19    | 34    | 51    | 74    |
| 4     | 25    | FREE  | 50    | 68    |
| 11    | 16    | 40    | 48    | 66    |
| 6     | 29    | 36    | 58    | 72    |

### 4. Visualização de Cartelas

- Permitir ao jogador visualizar as cartelas que está utilizando no jogo.

### 5. Marcação de Números

- O jogador poderá inserir o número chamado.
- O programa deve marcar o número na cartela.

#### 5.1. Regras de Alerta

- **COLUNA**: Caso todos os 5 quadrados de uma coluna estejam marcados, o programa deve exibir a mensagem `COLUNA`.
- **LINHA**: Caso todos os 5 quadrados de uma linha estejam marcados, o programa deve exibir a mensagem `LINHA`.
- **BINGO**: Caso todos os quadrados da cartela estejam marcados, o programa deve exibir a mensagem `BINGO`.
- **Olha a Boa**: Caso os quadrados da cartela estejam preenchidos e falte apenas um número, o programa deve exibir a mensagem `Olha a Boa!`.

### 6. Histórico de Números Chamados

- O programa deve informar os números que já foram chamados.
- Exemplo:
  - Números chamados: `1, 2, 4, 6, 14, 15, 19, 25, 34, 40, 41, 52, 54, 67, 69`.
  - Cartela 1: `4, 6, 19, 25, 34, 40, 54, 69`.

### 7. Armazenamento das Cartelas

- O programa deve gravar cada cartela gerada em um arquivo de texto separado.
- Exemplo:
  - Se o jogador pedir uma cartela, o programa deve gerar um arquivo para a cartela.
  - Se o jogador pedir duas cartelas, o programa deve gerar dois arquivos, um para cada cartela.

---
