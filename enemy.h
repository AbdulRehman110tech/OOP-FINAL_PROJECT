#pragma once
#define ENEMY_H
#include "character.h"
#include "attack.h"
#include "simple_attack.h"
#include <fstream>

class enemy : public character{
	Simple_Attack a;
	Texture damage;
	
	int attack_count;
	bool movingright, state_hit;
public : 
	enemy() = default;
	void damage_pic(bool collision);
	enemy(const enemy& other);
	enemy(const String& _n, float h_p, float Defence, const String& nam, float damaj, const char* filename,const char*filename2,int ac);
	enemy&  operator=(const enemy & other); 
  void receiveDamage(float base_damage) override;
  void movecharacter(float x) {
	  if (!this->chekposition_x(GetScreenWidth(), GetScreenHeight())) {
		  if (position.x < x) {
			  position.x += speed ;
			  this->set_right_face(true);
		  }
		  else if (position.x > x) {
			  position.x -= speed ;
			  this->set_right_face(false);
		  }
	  }
	 
  }

  void setting_position(Vector2 playerPos){
	 
	  Vector2 enemyPos;

	  do {
		  float randX = (float)(rand() % 1000);  // Random X
		  enemyPos = Vector2{ randX, 300 };      // Fixed Y for simplicity
	  } while (abs(enemyPos.x - playerPos.x) < 100);  // Avoid overlapping zone (100 px)

	  // Set enemy position
	  this->SetPosition(enemyPos);
  }

  Rectangle get_Tec() {
	  return { this->position.x,position.y,(float)texture.width / 2,(float)texture.height / 2 };
  }

  void set_state(bool istrue) {
	  this->state_hit = istrue;
  }

  bool return_set_state() {
	  return this->state_hit;
  }

  void chek_collision(bool istrue, float base_damage) {
	  if (istrue) {
		  this->receiveDamage(base_damage);
	  }
	  else {
		  return;
	  }
  }

  void draw_text_call(bool facing) { a.draw_texture(position, facing); }

  bool return_moving_right() {
	  return this->movingright;
  }
  

  void set_right_face(bool istrue) {
	  this->movingright = istrue;
  }

  void DrawRectangle_hp(int x, int y, int height) {
	  DrawRectangle(x, y, this->current_hp, height, GREEN);

  };
  void DrawRectangleLines_hp(int posX, int posY, int width, int height) {
	  DrawRectangleLinesEx(Rectangle{ (float)posX,(float)posY,(float)width,(float)height }, 3.5, BLACK);

  };

  float return_damage_of_attack() {
	  return a.return_damage();
  }

  bool can_attack() {
	  if (this->attack_count <= 0) {
		  return false;
	  }
	  else
	  {
		  return true;
	  }
  }

  int retun_attck() {
	  return this->attack_count;
  }

  void set_attack() {
	  this->attack_count -=1;
  }

  /*void rakhwarha(std::fstream &other) {
	  character::rakhwana(other);
  }*/
 


};
