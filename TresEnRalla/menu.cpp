#include"menu.h"

void Menu(MainManager* mm) {
	system("cls");

	char input;
	bool inputOk;

	cout << "---------- Tres en ratlla ----------" << endl << endl;

	cout << "1 - Nova partida" << endl;
	cout << "2 - Carregar partida guardada" << endl;
	cout << "3 - Sortida" << endl << endl;

	cout << "Tria una opcio: ";
	cin >> input;
	cout << endl;

	inputOk = input == '1' || input == '2' || input == '3';

	while (!inputOk) {
		cout << "Tria una opcio valida: ";
		cin >> input;
		cout << endl;

		inputOk = input == '1' || input == '2' || input == '3';
	}

	if (input == '1') {
		mm->currentScen = NEWGAME;
	}
	else if (input == '2') {
		mm->currentScen = LOADGAME;
	}
	else if (input == '3') {
		mm->exit = true;
	}
}