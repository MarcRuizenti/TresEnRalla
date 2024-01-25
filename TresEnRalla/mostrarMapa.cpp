#include "mostrarMapa.h"

void MostrarMapa(MainManager* mm) {
	cout << " -------------" << endl;
	for (int i = 0; i < mm->size; i++) {
		for (int j = 0; j < mm->size; j++) {
			if (j != mm->size - 1) {
				cout << " | " << mm->map[i][j];
			}
			else {
				cout << " | " << mm->map[i][j] << " |" << endl;
			}
		}
		cout << " -------------" << endl;
	}
	cout << endl;
}