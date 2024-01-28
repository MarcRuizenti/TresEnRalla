#pragma once
#include <fstream> 
#include <sstream> 
#include <string> 
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<string>
#include<vector>

using namespace std;

enum Scens {MENU, NEWGAME, LOADGAME, SAVE};

struct MainManager {
	Scens currentScen;
	bool exit;

	int size = 3;

	char map[3][3];

	int turnos;

	void Inicialaiz();
};
