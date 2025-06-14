#include "enemy.h"

enemy::enemy(const String& _n, float h_p, float Defence, const String& nam, float damaj, const char* filename, const char* filename2, int ac, const char* file) :character{ _n,h_p,Defence,file }, a{ damaj,nam,filename }, movingright{ false }, state_hit{ false }, attack_count{ac} { damage = LoadTexture(filename2); }
enemy::enemy(const enemy& other) :character{ other } {
	Image temp1 = LoadImageFromTexture(other.damage);
	damage = LoadTextureFromImage(temp1);
	UnloadImage(temp1);
	this->a = other.a;
	movingright = other.movingright;
	state_hit = other.state_hit;
}
enemy& enemy::operator=(const enemy& other) {
	this->a = other.a;
	Image temp1 = LoadImageFromTexture(other.damage);
	damage = LoadTextureFromImage(temp1);
	UnloadImage(temp1);
	movingright = other.movingright;
	state_hit = other.state_hit;
	character::operator=(other);
	return *this;
}
void enemy::damage_pic(bool collision) {
	if (collision) {
		DrawTextureEx(damage, position, 0.0f, 0.5f, WHITE);
	}
}

void enemy::receiveDamage(float base_damage) {
	float temp1 = base_damage - this->return_this_def();
	float temp = this->return_cr_hp() - temp1;
	this->set_cr_hp(temp);
	if (this->return_cr_hp() <= 0) {
		this->set_status(false);
	}
}

