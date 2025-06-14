#pragma once
#define BOSS_H

#include <iostream>
#include "attack.h";
#include "special_attack.h"
#include "character.h"
#include "enemy.h"
#include "arr.h"
#include "simple_attack.h"
using namespace std;

class boss :public enemy{
special_attack a2;
float damageCooldown = 0.0f;
const float maxCooldown = 0.5f;
public : 
	boss() = default;
	boss(const boss& other);
	boss(const enemy& other, const special_attack& others);
	boss& operator=(const boss& other);
	void draw_power_bar(int x, int y, int height) {
		DrawRectangle(x, y, this->a2.return_power(), height, RED);
	}
	void draw_border_of_power(int posX, int posY, int width, int height) {
		DrawRectangleLinesEx(Rectangle{ (float)posX,(float)posY,(float)width,(float)height }, 3.5, BLACK);
	}

	bool allow_sp_attack() {
		return this->a2.allow_attack();
	}

	float return_dm_of_special() {
		return this->a2.return_damage();
	}

	void add_power(float a) {
		this->a2.add_current_power(a);
	}

	void draw_special_power(bool facing) {
		this->a2.draw_texture(position, facing);
	}

	void set_power() {
		this->a2.set_current_power();
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

