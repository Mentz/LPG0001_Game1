#include <stdio.h>
#include "baloes.h"

int main(void) {
	int n = 1;
	char player[2][50];
	initialize();
	getPlayerNames(player[0], player[1]);
	while (n != 0) {
		n = getWallSize();
		playGame(n);
		clearScreen();
	}

	return 0;
}