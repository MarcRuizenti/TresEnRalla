#include"newGame.h"
#include "mostrarMapa.h"
#include "Victoria.h"

void Game(MainManager* mm) {
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
		//Verificacion de input
		cout << "Tria una opcio valida: ";
		cin >> input;
		cout << endl;

		inputOk = input == '1' || input == '2' || input == '3';
	}

	if (input == '1') {
		int inputX;
		int inputY;
		int Y;
		int X;
		bool isOK;
		do {
			//Eleccion de posicion
			cout << "Diu la curdanada a X: ";
			cin >> inputX;

			cout << "Diu la curdanada a Y: ";
			cin >> inputY;
			cout << endl;

			isOK = mm->map[inputY - 1][inputX - 1] == ' ';


		} while (!isOK);
		mm->map[inputY - 1][inputX - 1] = 'X';

		if (VerificarVictoria(mm, 'X')) {
			//Verificar Victoria
			system("cls");
			MostrarMapa(mm);

			cout << "Felicitacions has guanyat!!!" << endl;

			system("pause");
			mm->currentScen = MENU;
			mm->turnos = 0;
			for (int i = 0; i < mm->size; i++) {
				for (int j = 0; j < mm->size; j++) {
					mm->map[i][j] = ' ';
				}
			}
			return;
		}

		if (mm->turnos >= 4) {
			system("cls");
			MostrarMapa(mm);
			cout << "Natellant al taule" << endl;
			mm->turnos = 0;
			for (int i = 0; i < mm->size; i++) {
				for (int j = 0; j < mm->size; j++) {
				mm->map[i][j] = ' ';
				}
			}
		}
		else {
			system("cls");
			MostrarMapa(mm);

			cout << "Turn del contricant" << endl;
			do {
				X = rand() % mm->size;
				Y = rand() % mm->size;

				isOK = mm->map[Y][X] == ' ';

			} while (!isOK);

			mm->map[Y][X] = 'O';
			mm->turnos++;

			if (VerificarVictoria(mm, 'O')) {
				system("cls");
				MostrarMapa(mm);

				cout << "Has perdut!! Ven jugat" << endl;

				system("pause");
				mm->currentScen = MENU;
				mm->turnos = 0;
				for (int i = 0; i < mm->size; i++) {
					for (int j = 0; j < mm->size; j++) {
						mm->map[i][j] = ' ';
					}
				}
				return;
			}
		}
	}
	else if (input == '2') {
		mm->currentScen = SAVE;
	}
	else if (input == '3') {
		mm->currentScen = MENU;
	}
	
	system("pause");
}

