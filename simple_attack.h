#pragma once
#define SIMPLE_ATTACK_H
#include "attack.h"
#include <iostream>
using namespace std;

class Simple_Attack : public Attack {

public : 
	Simple_Attack() = default;
	Simple_Attack(int damage_per, String _n,const char* filename) : Attack(_n, damage_per,filename) {
		texture = LoadTexture(filename);
	}
	Simple_Attack(const Simple_Attack& other) : Attack(other) {};
	Simple_Attack& operator=(const Simple_Attack& other) { Attack :: operator=(other); return *this; }

	void draw_texture(Vector2 position,bool facingRight) override {
		Rectangle srcRect;
			if (facingRight) {
				srcRect = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };  // normal
			}
			else {
				srcRect = { (float)texture.width, 0.0f,-(float)texture.width, (float)texture.height };  // flipped
			}

			Rectangle destRect = { position.x, position.y,texture.width/2,texture.height/2 };
			DrawTexturePro(texture, srcRect, destRect, Vector2{0,0}, 0.0f, WHITE);
	
	}
	void unload_texture() override{ UnloadTexture(texture);}
	
};
