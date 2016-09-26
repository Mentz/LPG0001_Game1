#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "baloes.h"

int main(void) {
	clearScreen();
	int n = 1, i;
	char player[2][50];

	while (1) {
		initialize();
		getPlayerNames(player[0], player[1]);
		n = getWallSize();

		char** mapa;
		mapa = malloc(n * sizeof * mapa);
  		for (i = 0; i < n; i++)
    		mapa[i] = malloc(n * sizeof * mapa[i]);
		clearTable(mapa, n);
		clearScreen();

		if(playGame(player[0], player[1], mapa, n) == 'N')
			break;
		clearScreen();
	}

	return 0;
}