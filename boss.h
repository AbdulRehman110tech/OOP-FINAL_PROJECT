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
	DA <special_attack> a2;
	
public : 
	boss() = default;
	boss(const boss& other);
	boss(const enemy& other, const DA<special_attack>& others);
	boss& operator=(const boss& other);
};

