# THAT'S A BINGO!!!

<img src="https://i.imgflip.com/1rjzbt.jpg" width="332px">

---

## INSTRUÇÕES E OBSERVAÇÕES:

- **IMPORTANTE:** A aplicação foi desenvoldida para rodar, primariamente, em ambiente Linux. Muito embora o código seja executado corretamente, a compilação em ambiente Windows pode trazer prejuízos na codificação de caracteres, emojis ou alguma funcionalidade.
- **CRITÉRIO DE DESEMPATE:** Em caso de duas cartelas que tenham o mesmo número restante para que sejam completadas e ganharem a partida, a cartela de MAIOR ID tem preferência na correção e será, portanto, a única vencedora da partida.
- As cartelas são deletadas automaticamente após o fim da partida (opção 1), de maneira que não é possível iniciar outro jogo com a cartela já marcada e utilizada na partida anterior.
- A função de deletar cartelas limpar as cartelas geradas mas não utilizadas.
- Quando geradas cartelas, automaticamente são salvas em arquivo .TXT, contendo o nome "bingocard" + o ID da cartela (ex: bingocard10).
- A deleção não afeta os arquivos gerados.
- Se novas cartelas forem geradas, os arquivos .txt serão atualizados automaticamente.
- Para deletá-los, faça individualmente.

---

### REQUISITOS DA APLICAÇÃO:

As regras podem ser conferidas [AQUI](https://github.com/julianosantosdev/fatec-ED-thats-a-bingo/blob/main/Projeto.pdf)

#### A APLICAÇÃO:

Essa aplicação em C++ simula um jogo de bingo, geração randômica de números (sem repetição) e uso intensivo de ponteiros e pilhas.
Usando o menu interativo, você cria gera suas cartelas e, em seguida, escolhe a opção de iniciar o jogo, que vai sortear as "pedras" e automaticamente conferir suas cartelas, anunciando quando houver a formação da LINHA, COLUNA e, finalmente, quando houver a cartela completa e qual cartela foi a completa (fullhouse);

#### MENU:

<img width="332px" alt="image" src="https://github.com/user-attachments/assets/3ff5c395-5252-46aa-83c7-749750d44257" style="border-radius:8px">

<br>
<br>

#### INTERFACE DE ANDAMENTO DO JOGO EM TEMPO REAL:

<img width="502px" alt="image" src="https://github.com/user-attachments/assets/cc2e4991-814f-4d5b-b440-85784ea61aa0" style="border-radius:8px">

<br>
<br>

#### LISTAGEM DAS CARTELAS GERADAS E PRONTAS PARA JOGOR:

<img width="502px" alt="image" src="https://github.com/user-attachments/assets/ab79f1b5-1244-4dbd-9b3f-99f9ca1af54f" style="border-radius:8px">

---

#### MEMÓRIA HEAP:

A aplicação conta com gerenciamento otimizado de memória heap. Não há vazamentos após o encerramento da aplicação.
VALGRIND REPORT:

<img width="800px" alt="image" src="https://github.com/user-attachments/assets/0adc56ab-1189-455e-8478-9489d258e578" style="border-radius:8px">

#### FERRAMENTAS UTILIZADAS:

- WSL2 Debian 12 Bookworm
- VSCode 1.95.3
- Windows Terminal 1.21.3231.0
- Valgrind 3.19.0
