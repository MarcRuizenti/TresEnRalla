#include "Save.h"

void Save(MainManager* mm) {
	system("cls");
	string nameArchivo;

	cout << "------- SAVE -------" << endl << endl;

	cout << "Introdueix al nom que vulguis que tingi l'arxiu: ";
	cin >> nameArchivo;

	ofstream outputFile;
	ifstream exite(nameArchivo);

	if (exite.good()) {
		string sn;
		bool isOk;
		cout << "Vols sobreescruira la partida?(s/n): ";
		cin >> sn;
		cout << endl;

		isOk = sn == "s" || sn == "n";

		while (!isOk){
			cout << "Vols sobreescruira la partida?(s/n): ";
			cin >> sn;
			cout << endl;

			isOk = sn == "s" || sn == "n";
		}

		if (sn == "n") {
			return;
		}
	}

	outputFile.open(nameArchivo, ios::trunc);

	if (!outputFile.is_open()) {
		cout << "No sa pogut obra" << endl;
		return;
	}

	for (int i = 0; i < mm->size; i++) {
		for (int j = 0; j < mm->size; j++) {
			outputFile << mm->map[i][j] << " ";
		}
	}

	for (int i = 0; i < mm->size; i++) {
		for (int j = 0; j < mm->size; j++) {
			mm->map[i][j] = ' ';
		}
	}

	outputFile << mm->turnos;

	outputFile.close();
	mm->currentScen = MENU;
}