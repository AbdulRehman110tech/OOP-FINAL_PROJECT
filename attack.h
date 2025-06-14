#pragma once
#define ATTACK_H
#include <iostream>
#include "string.h"
#include "raylib.h"
using namespace std;

class Attack{
protected: 
	String name;
	float damage_percent;
	Texture2D texture;
public :
	Attack() :name{}, damage_percent{ 0 } {};
	Attack(String _n, float _d, const char* filename) : name{ _n }, damage_percent{ _d } {};
	Attack(const Attack& other) : name{ other.name }, damage_percent{ other.damage_percent }, texture{other.texture} {};
	Attack& operator= (const Attack& other) {
		this->name = other.name;
		this->damage_percent = other.damage_percent;
		Image tempale = LoadImageFromTexture(other.texture);
		texture = LoadTextureFromImage(tempale);
		UnloadImage(tempale);
		return *this;

	}
	float return_damage() { return this->damage_percent; };
	void virtual draw_texture(Vector2 position, bool facingRight) = 0;
	void virtual unload_texture() = 0;
	virtual ~Attack() {};
};
