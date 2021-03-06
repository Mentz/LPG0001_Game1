#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "baloes.h"

void clearScreen() {
	printf("\e[H\e[2J");
}

void initialize() {
	printf("### Seja bem-vindo ao jogo de pintar paredes ### \n");
}

void getPlayerNames(char *player1, char *player2) {
	printf("Insira nome dos jogadores\n");
	printf("(A) "); scanf("%s",player1);
	printf("(B) "); scanf("%s",player2);
}

int getWallSize() {
	int x = 1;
	printf("Tamanho da parede [4...50]\n");
	scanf("%d",&x);
	while ( x < 4 || x > 50) {
		printf("Número inválido!\n");
		printf("Tamanho da parede [4...50]\n");
		scanf("%d",&x);
	}
	return x;
}

void clearTable(char **mapa, int size){
	int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			mapa[i][j] = '.';
		}
	}
}

void printTable(char **mapa, int size){
	int i, j;

	if(size >= 10) {
		printf("    ");
		for(i = 0; i < size; i++){
			if((i+1)/10 < 1) printf("  "); else printf(" %d", (i+1)/10);
		}
		printf("\n ");
	}
	printf("   ");
	for(i = 0; i < size; i++){
		printf(" %d", (i+1)%10);
	}
	printf("\n");
	if(size >= 10) printf("    "); else printf("   ");
	for(i = 0; i <= size*2; i++){
		printf("_");
	}
	printf("\n");
	for(i = 0; i < size; i++){
		if(size > 9) printf("%-2d |",i+1); else printf("%-1d |",i+1);
		for(j = 0; j < size; j++){
			printf(" %c", mapa[i][j]);
		}
		printf(" |\n");
	}
	printf("%s",(size >= 10) ? "    ":"   ");
	for(i = 0; i <= size*2; i++){
		printf("‾");
	}
	printf("\n");
}

void paintTable(char **mapa, int x, int y, int player, int size, int *CC){
	if (x >= size || y >= size || x < 0 || y < 0) {} else {
		srand(time(NULL));
		int area = 1+(rand()%((size*size)/5));
		int i, posx = x, posy = y, dirx = rand()%2, diry = rand()%2, cont = 1; //diry(0 pra cima, 1 pra baixo), dirx(0 pra direita, 1 pra esquerda)
		if(mapa[posy][posx]=='.') *CC += 1;
		mapa[posy][posx] = (!player) ? 'A' : 'B';
		area--;
		while (area > 0) {
			i = cont;
			while (i-- > 0 && area) {
				posy += (diry) ? 1 : -1;
				if (posy >= 0 && posy < size && posx >= 0 && posx < size) {
					if(mapa[posy][posx]=='.') *CC += 1;
					mapa[posy][posx] = (!player) ? 'A' : 'B';
				}
				area--;
			}
			diry = !diry;
			i = cont;
			while (i-- > 0 && area) {
				posx += (dirx) ? 1 : -1;
				if (posy >= 0 && posy < size && posx >= 0 && posx < size) {
					if(mapa[posy][posx]=='.') *CC += 1;
					mapa[posy][posx] = (!player) ? 'A' : 'B';
				}
				area--;
			}
			dirx = !dirx;
			cont++;
		}
	}
}

char playGame(char *player1, char *player2, char **mapa, int size) {
	int i = 0, CC = 0, area = size*size;
	while (1) {
		printf("Vez de %s (tinta %s) jogar\n\n",(!i)?player1:player2,(!i)?"A":"B");

		printTable(mapa, size);
		printf("\nPosições vazias: %d\n", area-CC);
		printf("Linha e Coluna do arremesso\n");
		int x, y;
		scanf("%d %d", &y, &x);
		x--; y--;
		paintTable(mapa, x, y, i, size, &CC);
			
		if(CC == area){

			clearScreen();
			printTable(mapa, size);
			if(!i)
				printf("%s (A) venceu o jogo!\n", player1);
			else
				printf("%s (B) venceu o jogo!\n", player2);
			printf("Iniciar uma nova partida? [S/N]\n");
			
			char aux = 'a';
			while (aux != 'S' && aux != 'N') {
				getchar();
				scanf("%c", &aux);
				aux += (aux == 'n' || aux == 's')?'A'-'a':0;
				if (aux != 'N' && aux != 'S')
					printf("Escolha inválida.\nIniciar uma nova partida? [S/N]\n");
			}
			clearScreen();
			return aux;
		}
		i = !i;
		clearScreen();
	}
}