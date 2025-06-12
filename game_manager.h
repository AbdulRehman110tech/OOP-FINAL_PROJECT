#pragma once
#define GAME_CHANGER_H
#include <iostream>
#include "player.h"
#include "arr.h"
#include "raylib.h"
using namespace std;

class game_manager {
	DA <player> list;
static game_manager* instance;
game_manager() = default;
game_manager(const DA <player>& other);
public :
	void get_instance() {
		if (this->instance == nullptr) {
			instance = new game_manager();
		}
		else {
			throw "Cannot create two game managers ";
		}
	}
	void show_menue(Vector2 mousePo, const char* filename);
	void menue_select_player(player one, player two, const char* filename);
	void run_PVP(player one, player two);
};

