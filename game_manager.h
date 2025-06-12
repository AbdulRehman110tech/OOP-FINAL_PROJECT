#pragma once
#define GAME_CHANGER_H
#include <iostream>
#include "player.h"
#include "arr.h"
#include "raylib.h"
#include <vector>
using namespace std;

class game_manager {
	DA <player> list;
static game_manager* instance;
game_manager() = default;
game_manager(const DA <player>& other);
~game_manager() {};
public :
	static game_manager* get_instance() {
		if (instance == nullptr) {
		return	instance = new game_manager();
		}
		else {
			throw "Cannot create two game managers ";
		}
	}
	void show_menue( const char* filename);
	void show_charcaters() {
		int i = 0;
		while (!WindowShouldClose()) {
			BeginDrawing();
			list[i].damage_pic(true);
			if (IsKeyPressed(KEY_Q)) {
				i++;
			}
			EndDrawing();
		}
	}
	void menue_select_player(player one, player two, const char* filename);
	void run_PVP(player one, player two);
	void load_data(const DA<player>& other) {
		this->list = other;
	}
};

