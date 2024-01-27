#include"menu.h"
#include "newGame.h"

int main() {
	srand(time(NULL));

	MainManager* mm = new MainManager;
	mm->Inicialaiz();
	do {
		switch (mm->currentScen)
		{
		case MENU:
			Menu(mm);
			break;
		case NEWGAME:
			NewGame(mm);
			break;
		case LOADGAME:

			break;
		case SAVE:

			break;
		default:
			break;
		}
	} while (!mm->exit);

	return 0;
}