#include"newGame.h"
#include "mostrarMapa.h"

void NewGame(MainManager* mm) {
	system("cls");
	MostrarMapa(mm);

	char input;
	bool inputOk;
	
	cout << "1 - Posar fitxa" << endl;
	cout << "2 - Guarda" << endl;
	cout << "3 - Menu" << endl << endl;

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
		int inputX;
		int inputY;
		bool isOK;
		do {
			cout << "Diu la curdanada a X: ";
			cin >> inputX;

			cout << "Diu la curdanada a Y: ";
			cin >> inputY;
			cout << endl;

			isOK = mm->map[inputY - 1][inputX - 1] == ' ';


		} while (!isOK);

		mm->map[inputY - 1][inputX - 1] = 'X';

		system("cls");
		MostrarMapa(mm);
		
		cout << "Turn del contricant" << endl;

		int X = rand() % mm->size;
		int Y = rand() % mm->size;

		isOK = mm->map[Y][X] == ' ';

		while (!isOK){
			int X = rand() % mm->size;
			int Y = rand() % mm->size;
			isOK = mm->map[Y][X] == ' ';
		}

		mm->map[Y][X] == 'O';
	}
	else if (input == '2') {
		mm->currentScen = SAVE;
	}
	else if (input == '3') {
		mm->currentScen = MENU;
	}
	
	system("pause");
}
