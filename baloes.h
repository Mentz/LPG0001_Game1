void clearScreen();
void initialize();
void getPlayerNames(char *player1, char *player2); //pergunta e armazena nome dos jogadores
int getWallSize(); //retorna tamanho do tabuleiro
char playGame(char *player1, char *player2, char **mapa, int size); //retorna número do vencedor (0 para player 1, 1 para player 2)
void clearTable(char **mapa, int size); //limpa a parede
int paintTable(char **mapa, int x, int y, int player, int size, int *CC); //pinta parede
void printTable(char **mapa, int size);