#include <stdio.h>
#include "baloes.h"

void clearScreen() {
	printf("\e[H\e[2J");
}

void initialize() {
	printf("Seja bem-vindo ao jogo de pintar paredes\ncom arremessos de balões de tinta!\n");
}

void getPlayerNames(char *player1, char *player2) {
	printf("Favor inserir nome do jogador 1\n");
	scanf("%s",player1);
	printf("Favor inserir nome do jogador 2\n");
	scanf("%s",player2);
}

int getWallSize() {
	int x = 1;
	printf("Favor digitar o tamanho da parede desejada:\nTamanho entre 4 e 50, ou digite 0 para sair.\n");
	scanf("%d",&x);
	while (x > 0 && x < 4 && x > 50) {
		printf("Número inválido!\nDigite um número entre 4 e 50,\n ou digite 0 para sair.\n");
		scanf("%d",&x);
	}
	return x;
}

int playGame(int tableSize) {

}