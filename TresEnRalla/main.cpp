#include"menu.h"
#include "newGame.h"
#include "Save.h"

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
			Game(mm);
			break;
		case LOADGAME:

			break;
		case SAVE:
			Save(mm);
			break;
		default:
			break;
		}
	} while (!mm->exit);

	return 0;
}