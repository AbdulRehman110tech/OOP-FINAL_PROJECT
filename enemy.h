#pragma once
#define ENEMY_H
#include "character.h"
#include "attack.h"

class enemy : public character{
	Attack a;
	friend istream& operator>>(istream& is, enemy& other);
	friend ostream& operator<<(ostream& os, const enemy& other);

public : 
	enemy();
	enemy(const enemy& other);
	enemy(const String& _n, int h_p, int Defence,const String& nam,int damaj);
	enemy&  operator=(const enemy & other);
  int attack_palyer();
};
