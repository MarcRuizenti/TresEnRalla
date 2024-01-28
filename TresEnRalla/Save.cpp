#include "Save.h"

void Save(MainManager* mm) {
	system("cls");
	string nameArchivo;

	cout << "------- SAVE -------" << endl << endl;

	cout << "Introdueix al nom que vulguis que tingi l'arxiu: ";
	cin >> nameArchivo;

	std::ofstream outputFile;

	outputFile.open(nameArchivo, std::ios::trunc);

	if (!outputFile.is_open()) {
		std::cout << "No sa pogut obra" << endl;
		return;
	}

	outputFile << mm->map << ' ' << mm->turnos;

	outputFile.close();
}