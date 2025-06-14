#pragma once

#include <iostream>
#include "string.h"
#include "raylib.h"
using namespace std;
class character {
protected:
	String name;
	float H_P, Def;
	float current_hp;
	bool status;
	// raylib shit 

	Texture2D texture;
	Vector2 position;
	float speed;
	

public:
	character() = default;
	character(String _n, float h_p, float Defence) : name{ _n }, H_P{ h_p }, current_hp{ h_p }, Def{ Defence }, status{ true } {};
	character(const character& other) : name{ other.name }, H_P{ other.H_P }, current_hp{ other.current_hp }, Def{ other.Def }, status{ other.status }, position{ other.position }, speed{ other.speed } {
		Image temp = LoadImageFromTexture(other.texture);
		texture = LoadTextureFromImage(temp);
		UnloadImage(temp);
	}
	character& operator=(const character& other) {
		this->name = other.name;
		this->current_hp = other.current_hp;
		this->H_P = other.H_P;
		this->Def = other.Def;
		this->status = other.status;
		Image tempale = LoadImageFromTexture(other.texture);
		texture = LoadTextureFromImage(tempale);
		UnloadImage(tempale);
		this->position = other.position;
		this->speed = other.speed;
		
		return *this;
	}
	virtual ~character() {}


	virtual void receiveDamage(float base_damage) = 0;
	String return_name() { return this->name; };

	int return_cr_hp() { return this->current_hp; }
	int return_this_def() { return this->Def; }
	int return_hp() { return this->H_P; };
	void set_cr_hp(int a) { this->current_hp = a; }
	void set_status(bool istrue) {this->status = istrue;}
	bool return_status() { return this->status; }

	// raylib material

	void LoadTextureFromFile(const char* filePath) {
		texture = LoadTexture(filePath);
	
	}

		void DrawCharacter() {

			DrawTextureEx(texture,position,0.0f,0.5f, WHITE);
		}

		void MoveCharacter(int direction) {
			switch (direction) {
			case 0: position.x -= speed; break; // Left
			case 1: position.x += speed; break; // Right
			case 2: position.y -= speed; break; // Up
			case 3: position.y += speed; break; // Down
			default: break;
			}
		}

		void SetPosition(Vector2 pos) {
			this->position = pos;
		}

		Vector2 GetPosition() const {
			return position;
		}

		void SetSpeed(float spd) {
			speed = spd;
		}

		float GetSpeed() const {
			return speed;
		}

		void unloadtexture() {
			UnloadTexture(texture);
		}

		bool chekposition_x(const int screenWidth, const int screenheight) {
			
			if (position.x < 0) { position.x = 0; return true; }
			if (position.x > screenWidth - texture.width) { position.x = screenWidth - texture.width; return true; }
		
			return false;
		}

		bool chekposition_y(const int screenWidth, const int screenheight){
			

				if (position.y < 0) {
					position.y = 0;
					return true;
				}
				
				if (position.y > screenheight - texture.height) { position.y = screenheight - texture.height;return true; }
				return false;
			
		}

		void chekfacing(bool facingRight) {
			Rectangle srcRect;
			if (facingRight) {
				srcRect = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };  // normal
			}
			else {
				srcRect = { (float)texture.width, 0.0f,-(float)texture.width, (float)texture.height };  // flipped
			}

			Rectangle destRect = { position.x, position.y,texture.width/2,texture.height/2 };
			DrawTexturePro(texture, srcRect, destRect, Vector2{0,0}, 0.0f, WHITE);
		
		}
			
		Texture2D return_texture() { return this->texture; }
		
};

