#include <stdio.h>
#include "baloes.h"

int main(void) {
	int n = 1;
	initialize();
	while (n != 0) {
		n = getWallSize();
		playGame(n);
		clearScreen();
	}

	return 0;
}