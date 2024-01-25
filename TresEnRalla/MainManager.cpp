#include"MainManager.h"

void MainManager::Inicialaiz() {
	currentScen = MENU;
	exit = false;


	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			map[i][j] = ' ';
		}
	}
}