# THAT'S A BINGO!!!

<img src="https://i.imgflip.com/1rjzbt.jpg" width="332px">

## OBSERVAÇÕES:

- **IMPORTANTE:** A aplicação foi desenvoldida para rodar, primariamente, em ambiente Linux. Muito embora o código seja executado corretamente, a compilação em ambiente Windows pode trazer prejuízos na codificação de caracteres, emojis ou alguma funcionalidade.
- **CRITÉRIO DE DESEMPATE:** Em caso de duas cartelas que tenham o mesmo número restante para que sejam completadas e ganharem a partida, a cartela de MAIOR ID tem preferência na correção e será, portanto, a única vencedora da partida.
- As cartelas são deletadas automaticamente após o fim da partida (opção 1), de maneira que não é possível iniciar outro jogo com a cartela já marcada e utilizada na partida anterior.
- A função de deletar cartelas limpar as cartelas geradas mas não utilizadas.
- Quando geradas cartelas, automaticamente são salvas em arquivo .TXT, contendo o nome "bingocard" + o ID da cartela (ex: bingocard10).
- A deleção não afeta os arquivos gerados.
- Se novas cartelas forem geradas, os arquivos .txt serão atualizados automaticamente.
- Para deletá-los, faça individualmente.

## REQUISITOS DA APLICAÇÃO:

As regras podem ser conferidas [AQUI](https://github.com/julianosantosdev/fatec-ED-thats-a-bingo/blob/main/Projeto.pdf)

### FUNCIONAMENTO e INSTRUÇÕES:

- Essa aplicação em C++ simula um jogo de bingo, geração randômica de números (sem repetição) e uso intensivo de ponteiros e pilhas.
- Usando o menu interativo, você gera suas cartelas e, em seguida, escolhe a opção de iniciar o jogo, que vai sortear as "pedras" e automaticamente conferir suas cartelas, informando se o número foi marcado e em qual cartela.
- A formação de LINHA e/ou COLUNA só acontece uma vez por jogo e é anunciada na tela, informando qual cartela conquistou a linha ou coluna.
- Uma vez marcadas as LINHAS e COLUNAS, ainda que na mesma cartela, resta ao jogador que não teve linha ou coluna a chance de vencer fazendo a cartela cheia (fullhouse).
- Quando houver cartela completa a aplicação anuncia a cartela do vencedor e encerra o jogo.
- Após o encerramento, suas cartelas podem ainda ser visualizadas e também verificados quais números faltaram para completá-la.
- Finalmente, ao terminar uma partida, delete as cartelas usadas (opção 4) e gere quantas novas cartelas desejar (opção 2).

### COMO EXECUTAR:

- Clone o repositório;
- Abra um terminal dentro da pasta src;
- Execute o comando `g++ -o <nomeDaAplicacao> main.cpp`;
- Em seguida execute com: `./<nomeDaAplicacao>`;

### MENU:

<img width="502px" alt="image" src="https://github.com/user-attachments/assets/1f259190-04ee-4cc3-b7f4-978f2238d187">

<br>
<br>

### LISTAGEM DAS CARTELAS GERADAS E PRONTAS PARA JOGAR:

<img width="502px" alt="image" src="https://github.com/user-attachments/assets/76278e8f-fa5f-401b-bca0-fad3ed7536c3">

<br>
<br>

### LISTAGEM DAS CARTELAS PÓS-JOGO (em vermelho, os números pontuados ; em branco, os faltantes):

<img width="502px" alt="image" src="https://github.com/user-attachments/assets/a10757fe-ce71-4e60-96df-f71f7e89e275">

<br>
<br>

### INTERFACE DE ANDAMENTO DO JOGO EM TEMPO REAL:

<img width="502px" alt="image" src="https://github.com/user-attachments/assets/781755a8-6cc6-4691-8669-596abf24b7b7">

<br>
<br>

## DETALHES TÉCNICOS:

### MEMÓRIA HEAP:

A aplicação conta com gerenciamento otimizado de memória heap. Não há vazamentos após o encerramento da aplicação.

#### VALGRIND REPORT:

<img width="800px" alt="image" src="https://github.com/user-attachments/assets/876d285e-6726-4d38-8601-226e289437a4">

#### FERRAMENTAS UTILIZADAS:

- WSL2 Debian 12.2.0
- VSCode 1.95.3
- Windows Terminal 1.21.3231.0
- Valgrind 3.19.0
