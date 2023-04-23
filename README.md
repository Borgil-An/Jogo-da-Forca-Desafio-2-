# Jogo-da-Forca-Desafio-2-
Jogo da forca em C para o desafio 2 do monitor de pc

ENG: ''This is a game written in C where the player has to guess a word by entering letters until they either win by correctly 
guessing the word or lose by running out of chances. The game randomly selects a word from an array of words and displays a hint for the player.

The program defines a structure called MatchData to hold the game data, including the chosen word, the hint, the remaining 
letters to be guessed, and the remaining chances. The main function uses a while loop to repeatedly run the game until the player chooses to exit.

The program first calls the function selecionarPalavraAleatoria to select a random word from the array of words and populate the MatchData structure. 
Then, it displays the hint and enters a loop where it repeatedly calls exibirPartida to display the current game state, lerLetraDoUsuario to read the player's input, 
and atualizarPalavra to update the game state. The loop continues until the player wins or loses.

When the game is over, the program displays a message indicating whether the player won or lost and prompts them to play again or exit. 
The program ends if the player chooses to exit.

The program uses several helper functions, including limparTela to clear the console screen, 
strtok to split the word and hint string, and rand and srand to generate random numbers for selecting a word from the array.''




PT BR: ''Este é um jogo escrito em C onde o jogador deve adivinhar uma palavra inserindo letras até que ele ganhe ao acertar a palavra correta ou perca ao ficar sem chances. 
O jogo seleciona aleatoriamente uma palavra de uma matriz de palavras e exibe uma dica para o jogador.

O programa define uma estrutura chamada MatchData para armazenar os dados do jogo, incluindo a palavra escolhida, a dica, as letras restantes a serem adivinhadas e as 
chances restantes. A função principal usa um loop while para executar o jogo repetidamente até que o jogador escolha sair.

O programa chama primeiro a função selecionarPalavraAleatoria para selecionar uma palavra aleatória da matriz de palavras e preencher a estrutura MatchData. 
Em seguida, ele exibe a dica e entra em um loop onde chama repetidamente exibirPartida para exibir o estado atual do jogo, lerLetraDoUsuario para ler a entrada do jogador e 
atualizarPalavra para atualizar o estado do jogo. O loop continua até que o jogador ganhe ou perca.

Quando o jogo termina, o programa exibe uma mensagem indicando se o jogador ganhou ou perdeu e solicita que ele jogue novamente ou saia. 
O programa termina se o jogador escolher sair.

O programa usa várias funções auxiliares, incluindo limparTela para limpar a tela do console, strtok para dividir a string de 
palavra e dica e rand e srand para gerar números aleatórios para selecionar uma palavra da matriz''
