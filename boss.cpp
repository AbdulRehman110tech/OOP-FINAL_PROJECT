//#include "boss.h"
//
//boss::boss() :a{}, a2{} {}
//boss::boss(const DA <Attack>& other, const special_attack& others) :a{ other }, a2{ others } {}
//boss::boss(const boss& other) :a{ other.a }, a2{ other.a2 } {}
//boss& boss::operator=(const boss& other) {
//	this->a = other.a;
//	this->a2 = other.a2;
//	return* this;
//}
//
//ostream& operator<<(ostream& os, const boss& other) {
//	other.a.display();
//	cout << other.a2 << endl;
//	return os;
//}