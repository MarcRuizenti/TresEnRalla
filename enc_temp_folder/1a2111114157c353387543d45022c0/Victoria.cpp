#include "Victoria.h"

bool verificarVictoria(MainManager* mm, char jugador) {
	// Verificar filas y columnas
	for (int i = 0; i < mm->size; ++i) {
		if ((mm->map[i][0] == jugador && mm->map[i][1] == jugador && mm->map[i][2] == jugador) || (mm->map[0][i] == jugador && mm->map[1][i] == jugador && mm->map[2][i] == jugador)) {
			return true;
		}
	}

	// Verificar diagonales
	if ((mm->map[0][0] == jugador && mm->map[1][1] == jugador && mm->map[2][2] == jugador) || (mm->map[0][2] == jugador && mm->map[1][1] == jugador && mm->map[2][0] == jugador)) {
		return true;
	}

	return false;
}