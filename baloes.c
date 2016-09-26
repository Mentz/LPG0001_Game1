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
		scanf("%d",&x);
	}
	return x;
}

void clearTable(char **mapa, int size){
	int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			mapa[i][j] = '#';
		}
	}
}

void printTable(char **mapa, int size){
	int i, j;

	printf("  ");
	if(size >= 10)
		printf(" ");
	for(i = 0; i < size; i++){
		if(i != 0 && size >= 10){
			if(i <= 9)
				printf("  ");
			else
				printf(" ");
		}else{
			printf(" ");
		}
		printf("%d", i);
	}
	printf("\n");

	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			if(j == 0){
				if(i <= 9 && size >= 10)
					printf(" ");
				printf("%d ", i);

			}
			if(j != 0 && size >= 10){
				printf("  ");
			}else
				printf(" ");

			printf("%c", mapa[i][j]);
		}
		printf("\n");
	}
}

int paintTable(char **mapa, int x, int y, int player, int size, int *CC){
	srand(time(NULL));
	int larg = 1+(rand()%((int)(size*0.20))), i , j;
	int posx = x-larg, posy = y-larg, cont = 0;

	for(i = posy; i <= x+larg; i++){
		for(j = posx; j <= y+larg; j++){
			if(i >= 0 && j >= 0 && i < size && j < size){
				cont++;
				
				if(mapa[i][j] == '#')
					*(CC) += 1;

				if(player)
					mapa[i][j] = 'B';
				else
					mapa[i][j] = 'A';
			}
		}
	}
}

char playGame(char *player1, char *player2, char **mapa, int size) {
	int i, CC = 0;
	for (i = 2 ;; i++) {
		printf("Vez de ");
		if(i%2 == 0)
			printf("%s (A) ", player1);
		else
			printf("%s (B) ", player2);
		printf("jogar\n");

		printTable(mapa, size);
		printf("%d\n", CC);
		printf("Posição X e Y do arremesso\n");
		int x, y;
		scanf("%d %d", &x, &y);
		paintTable(mapa, x, y, i%2, size, &CC);
			
		if(CC == size*size){
			clearScreen();
			printTable(mapa, size);

			if(i%2 == 0)
				printf("%s (A) venceu o jogo!\n", player1);
			else
				printf("%s (B) venceu o jogo!\n", player2);
			
			printf("Iniciar uma nova partida? [S/N]\n");
			char aux;
			getchar();
			scanf("%c", &aux);
			return aux;
		}

		clearScreen();
	}
}