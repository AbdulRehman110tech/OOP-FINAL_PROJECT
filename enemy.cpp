//#include "enemy.h"
//
//enemy::enemy() :a{} {}
//enemy::enemy(const String& _n, int h_p, int Defence, const String& nam, int damaj) :character{ _n,h_p,Defence }, a{nam,damaj} {}
//enemy::enemy(const enemy& other) :character{ other } {}
//enemy& enemy::operator=(const enemy& other) {
//	this->a = other.a;
//	character::operator=(other);
//	return *this;
//}
//istream& operator>>(istream& is, enemy& other) {
//	
//	is >> (character&)other;
//	return is;
//}
//
//ostream& operator<<(ostream& os, const enemy& other) {
//	os << (character&)other;
//	os << other.a << endl;
//	return os;
//}
//
