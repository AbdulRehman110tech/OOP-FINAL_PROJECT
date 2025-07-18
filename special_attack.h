#pragma once
#define SPECIAL_ATTACK_H
#include "attack.h"

class special_attack : public Attack {
	float power, curr_power;
	
public : 
	special_attack();
	special_attack(float pr, String _n, float _d, const char* filename);
	special_attack(const special_attack& other);
	special_attack& operator=(const special_attack& other);
	bool allow_attack();
	void set_current_power();
	int return_power() { return this->curr_power; }
	void add_current_power(float sum);
	
	void draw_texture(Vector2 w, bool facingright)override;
	void unload_texture() override { UnloadTexture(texture); }
};
