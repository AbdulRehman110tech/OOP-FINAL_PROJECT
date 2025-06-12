#pragma once

#include <iostream>
#include "character.h"
#include "simple_attack.h"
#include "arr.h"
#include "special_attack.h"
using namespace std;

class player : public character {
	int score;
	DA<Simple_Attack> moves;
	bool facing;
	special_attack only;
	Texture2D temp;
public : 
	player();
	player(const String& _n, int h_p, int Defence, DA <Simple_Attack>& other, const special_attack& others, const char* filename);
	player(const player& other);
	player& operator=(const player& other);

	int return_damage_of_attack(int a), return_dm_of_special();
	void draw_text_call(int a,bool facing);
	bool allow_sp_attack();
	void receiveDamage(int base_damage)override;
	void unloading();
	bool return_facing() {
		return this->facing;
	}
	void set_facing(bool istrue) {
		this->facing = istrue;
	}

	Rectangle get_Tec() {
		return { this->position.x,position.y,(float)texture.width/2,(float)texture.height/2};
	}

	void chek_collision(bool istrue, int base_damage) ;

	void damage_pic(bool collision) {
		if (collision) {
			DrawTextureEx(temp,position,0.0f,0.5f, WHITE);
	}
	}

	void DrawRectangle_hp(int x, int y, int height) {
		DrawRectangle(x, y, this->current_hp, height, GREEN);
		
	};
	void DrawRectangleLines_hp(int posX, int posY, int width, int height) {
		DrawRectangleLinesEx(Rectangle {(float)posX,(float)posY,(float)width,(float)height}, 3.5, BLACK);

	};

	void draw_power_bar(int x, int y, int height) {
		DrawRectangle(x, y, this->only.return_power(), height , RED);
	}

	void draw_border_of_power(int posX, int posY, int width, int height) {
		DrawRectangleLinesEx(Rectangle{ (float)posX,(float)posY,(float)width,(float)height }, 3.5, BLACK);
	}

	void add_power(float a);
	void set_power();

	void draw_special_power(bool facing) {
		this->only.draw_texture(position, facing);
	}

	void unload_Special_attack() {
		this->only.unload_texture();
	}
	~player() {
		this->unloadtexture();
		this->unloading();
		this->unload_Special_attack();
	}
};


