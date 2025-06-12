#pragma once
#define ATTACK_H
#include <iostream>
#include "string.h"
#include "raylib.h"
using namespace std;

class Attack{
protected: 
	String name;
	int damage_percent;
	Texture2D texture;
public :
	Attack() :name{}, damage_percent{ 0 } {};
	Attack(String _n, int _d, const char* filename) : name{ _n }, damage_percent{ _d } {};
	Attack(const Attack& other) : name{ other.name }, damage_percent{ other.damage_percent } {};
	Attack& operator= (const Attack& other) {
		this->name = other.name;
		this->damage_percent = other.damage_percent;
		this->texture = other.texture;
		return *this;

	}
	int return_damage() { return this->damage_percent; };
	void virtual draw_texture(Vector2 position, bool facingRight) = 0;
	void virtual unload_texture() = 0;
	virtual ~Attack() {};
};
