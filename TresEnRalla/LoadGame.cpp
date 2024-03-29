#include "LoadGame.h"

void LoadGame(MainManager* mm) {
	system("cls");
	string nameArchivo;

	cout << "------- LOAD -------" << endl << endl;

	cout << "Introdueix al nom del arxiu: ";
	cin >> nameArchivo;

	ifstream inputFile;

	inputFile.open(nameArchivo);

	if (!inputFile.is_open()) {
		cout << "No sa pogut obra" << endl;
		system("pause");
		return;
	}

	for (int i = 0; i < mm->size; i++) {
		for (int j = 0; j < mm->size; j++) {
			if (!inputFile.get(mm->map[i][j])) {
				cout << "Error al llegui" << endl;

				system("pause");
				return;
			}
		}
	}
	
	if (!inputFile >> mm->turnos) {
		cout << "Error al llegui turnos" << endl;

		system("pause");
		return;
	}

	inputFile.close();
	mm->currentScen = NEWGAME;
}