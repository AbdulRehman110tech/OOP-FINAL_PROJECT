#include "attack.h"

Attack::Attack() : {}
Attack::Attack(const Attack& other) : {}
Attack::Attack(String _n, int _d) :
Attack& Attack::operator=(const Attack& other) {
	this->name = other.name;
	this->damage_percent = other.damage_percent;
	return *this;

}



int Attack::return_damage() {

}