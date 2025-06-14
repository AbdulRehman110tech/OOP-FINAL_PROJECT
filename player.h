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
	float damageCooldown = 0.0f;
	const float maxCooldown = 0.5f;
public : 
	player();
	player(const String& _n, float h_p, float Defence, DA <Simple_Attack>& other, const special_attack& others, const char* filename, const char* file);
	player(const player& other);
	player& operator=(const player& other);

	float return_damage_of_attack(int a), return_dm_of_special();
	void draw_text_call(int a,bool facing);
	bool allow_sp_attack();
	void receiveDamage(float base_damage)override;
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

	void chek_collision(bool istrue, float base_damage) ;

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

	int return_position_of_x() {
		return  this->position.x;
	}

	bool can_take_damage() const {
		if (damageCooldown <= 0.0f) {
			return true;
		}
		else {
			return false;
		}
		
	}

	void reset_damage_cooldown() {
		damageCooldown = maxCooldown;
	}

	void update_cooldown() {
		if (damageCooldown > 0.0f)
			damageCooldown -= GetFrameTime(); 
	}


};


