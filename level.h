#pragma once
#define LEVEL_H
#include <iostream>
#include "raylib.h"
#include "string.h"
#include "player.h"
#include "enemy.h"
#include "boss.h"



class level {
	DA <enemy> bots;
	boss b1;
	bool status;
	Texture2D pic_level;
public :

	level() = default;
	level(const DA<enemy>& other, const boss& chaudry, const char* filename) : bots{ other }, b1{ chaudry }, status{ false } { pic_level = LoadTexture(filename); };
	level(const level& other) :bots{ other.bots }, b1{ other.b1 }, status{ other.status } {
		Image temp = LoadImageFromTexture(other.pic_level);
		pic_level = LoadTextureFromImage(temp);
		UnloadImage(temp);
	};
	level& operator=(const level& other) {
		bots = other.bots;
		b1 = other.b1;
		Image temp = LoadImageFromTexture(other.pic_level);
		pic_level = LoadTextureFromImage(temp);
		UnloadImage(temp);
		status = other.status;
	}

	bool return_state() { return status; }
	void set_status(bool istrue) {
		status = istrue;
	}

	void run_game(player& knight) {

	}


};
// enemies and one boss player not needed just initialize void work logic level array in game maneger status of level locked or un locked an be saved in file and 
// data present on main can also be saved if needed texture needed of level menue also needed which level to play in manager 