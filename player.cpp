#include "player.h"



player::player() :score{ 0 }, only{}, moves{}, facing{true} {}
player::player(const String& _n, int h_p, int Defence, DA <Simple_Attack>& other, const special_attack& others, const char* filename) : only{ others }, moves{ other }, character{ _n, h_p, Defence }, score{ 0 }, facing{ true } { temp = LoadTexture(filename); }
player::player(const player& other) : score{ other.score }, character{ other }, moves{ other.moves }, only{ other.only } {
	Image temp1 = LoadImageFromTexture(other.temp);
	temp = LoadTextureFromImage(temp1);
	UnloadImage(temp1);
}

player& player::operator=(const player& other) {
	this->score = other.score;
	this->moves = other.moves;
	this->facing = other.facing;
	this->only = other.only;
	Image temp1 = LoadImageFromTexture(other.temp);
	temp = LoadTextureFromImage(temp1);
	UnloadImage(temp1);
	this->character::operator=(other);
	return *this;
}


int player::return_damage_of_attack(int a) {
	return this->moves[a].return_damage();
}


void player::draw_text_call(int a,bool facing) { this->moves[a].draw_texture(position,facing);}
void player::unloading(){

	for (int i = 0;i < this->moves.size();i++) {
		this->moves[i].unload_texture();
	}
}

bool player::allow_sp_attack() {
	return this->only.allow_attack();
}

int player::return_dm_of_special() {
	return this->only.return_damage();
}

void player::receiveDamage(int base_damage) {

	float temp1 = base_damage - this->return_this_def();
	int temp = this->return_cr_hp() - temp1;
	this->set_cr_hp(temp);
	if (this->return_cr_hp() <= 0) {
		this->set_status(false);
	}
}

void player::chek_collision(bool istrue, int base_damage) {
	if (istrue) {
		this->receiveDamage(base_damage);
	}
	else {
		return;
	}
}

void player::add_power(float a) {
	this->only.add_current_power(a);
}

void player::set_power() {
	this->only.set_current_power();
}