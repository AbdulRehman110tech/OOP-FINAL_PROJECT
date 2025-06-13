#include "special_attack.h"

special_attack::special_attack() :power{ 0 }, curr_power{ 0 } {}
special_attack::special_attack(float pr, String _n, float _d, const char* filename) : power{ pr }, curr_power{ 0 }, Attack{_n,_d,filename} {
	texture = LoadTexture(filename);
	if (texture.id == 0) {
		std::cout << "Failed to load texture: " << filename << std::endl;
	}
}
special_attack::special_attack(const special_attack& other) : power{ other.power }, curr_power{ other.curr_power }, Attack{other} {}
special_attack& special_attack::operator=(const special_attack& other) {
	this->power = other.power;
	this->curr_power = other.curr_power;
	Attack::operator=(other);
	return *this;
}

bool special_attack::allow_attack() {
	if (this->curr_power >= this->power) {
		return true;
	}
	else {
		return false;
	}
}

void  special_attack::add_current_power(float sum) {
	if (this->curr_power < this->power) {
		this->curr_power = this->curr_power + sum;
	}
	else {
		this->curr_power = this->power;
	}
}

void special_attack::set_current_power(){
	this->curr_power = 0;
}

void  special_attack::draw_texture(Vector2 position, bool facingRight) {
	Rectangle srcRect;
	if (facingRight) {
		srcRect = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };  // normal
	}
	else {
		srcRect = { (float)texture.width, 0.0f,-(float)texture.width, (float)texture.height };  // flipped
	}

	Rectangle destRect = { position.x, position.y,texture.width / 2,texture.height / 2 };
	DrawTexturePro(texture, srcRect, destRect, Vector2{ 0,0 }, 0.0f, WHITE);
}


