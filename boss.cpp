#include "boss.h"

boss::boss(const enemy& other, const DA<special_attack>& others) :enemy{ other }, a2{ others } {}
boss::boss(const boss& other) : a2{ other.a2 }, enemy{other} {}
boss& boss::operator=(const boss& other) {
	enemy::operator=(other);
	this->a2 = other.a2;
	return* this;
}
