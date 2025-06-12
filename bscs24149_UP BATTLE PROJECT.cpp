#include <iostream>
#include "character.h"
#include "player.h"
#include "simple_attack.h"
#include "raylib.h"
#include "special_attack.h"
using namespace std;

int main(){
	InitWindow(1000, 470, "Battle Game");
	Texture2D background = LoadTexture("assests/background1.png");
	DA <Simple_Attack> a (Simple_Attack(10, "Punch", "assests/fighter1(J).png"));
	a.add(Simple_Attack(10, "Kick", "assests/fighter1(K).png"));
	special_attack s(100,"Blast",20,"assests/fighter(L).png");
	player knight("Sir Braver", 200, 5,a,s);
	knight.LoadTextureFromFile("assests/fighter1.png");
	knight.SetPosition({ 0, 300 });
	knight.SetSpeed(0.5f);

	player knight2("Sir Braver", 200, 5, a,s);
	knight2.LoadTextureFromFile("assests/fighter1.png");
	knight2.SetPosition({ 800, 300 });
	knight2.SetSpeed(0.5f);
	bool player1_state = false;
	bool player2_state = false;
	while (!WindowShouldClose()) {
		BeginDrawing();
		Rectangle src = { 0, 0, (float)background.width, (float)background.height };
		Rectangle dest = { 0, 0, 1000.0f, 470.0f };
		Vector2 origin = { 0, 0 };
		float rotation = 0.0f;
		DrawTexturePro(background, src, dest, origin, rotation, WHITE);
		knight.DrawRectangle_hp(10,10,20);
		knight.DrawRectangleLines_hp(10, 10, 201, 21);
		knight.draw_power_bar(10, 28, 10);
		knight.draw_border_of_power(10, 28, 101,11);
		knight2.DrawRectangle_hp(780, 10, 20);
		knight2.DrawRectangleLines_hp(780, 10, 201, 21);
		knight2.draw_power_bar(880, 28, 10);
		knight2.draw_border_of_power(880, 28, 101, 11);
		if (IsKeyDown(KEY_J) || IsKeyDown(KEY_K) || IsKeyDown(KEY_L)) {

			if (IsKeyDown(KEY_J)) {
				knight.draw_text_call(0, knight.return_facing());
				player2_state = CheckCollisionRecs(knight.get_Tec(), knight2.get_Tec());
				knight2.chek_collision(player2_state, knight.return_damage_of_attack(0));
			}
			else if(IsKeyDown(KEY_K)){
				knight.draw_text_call(1, knight.return_facing());
				player2_state = CheckCollisionRecs(knight.get_Tec(), knight2.get_Tec());
				knight2.chek_collision(player2_state, knight.return_damage_of_attack(0));
			}
			else if (IsKeyDown(KEY_L)&& knight.allow_sp_attack()) {
					knight.draw_special_power(knight.return_facing());
					player2_state = CheckCollisionRecs(knight.get_Tec(), knight2.get_Tec());
					knight2.chek_collision(player2_state, knight.return_damage_of_attack(0));
					knight.set_power();
				
				
			}
		
		}
		else {
			if (player1_state == false) {
				if (knight.return_facing()) {
					knight.DrawCharacter();
				}
				else {
					knight.chekfacing(false);
				}
			}
			else {
				knight.damage_pic(player1_state, "assests/fighter1(D).png");
				knight2.add_power(5);
				player1_state = false;
			}
		}

		if (IsKeyDown(KEY_M)||IsKeyDown(KEY_N) || IsKeyDown(KEY_B)) {
			
			if (IsKeyDown(KEY_M)) {
				bool temp = knight2.return_facing();
				temp ^= true ^ false;
				knight2.draw_text_call(0, temp);
				player1_state = CheckCollisionRecs(knight.get_Tec(), knight2.get_Tec());
				knight.chek_collision(player1_state, knight2.return_damage_of_attack(0));
			}
			else if (IsKeyDown(KEY_N)) {
				bool temp = knight2.return_facing();
				temp ^= true ^ false;
				knight2.draw_text_call(1, temp);
				player1_state = CheckCollisionRecs(knight.get_Tec(), knight2.get_Tec());
				knight.chek_collision(player1_state, knight2.return_damage_of_attack(0));
			}
			else if (IsKeyDown(KEY_B)) {
				if (knight2.allow_sp_attack()) {
					knight2.draw_special_power(knight.return_facing());
					player1_state = CheckCollisionRecs(knight.get_Tec(), knight2.get_Tec());
					knight.chek_collision(player1_state, knight2.return_damage_of_attack(0));
					knight2.set_power();
				}
			}
		}
		else {
			if (player2_state == false) {
				if (knight2.return_facing()) {
					knight2.chekfacing(false);
				}
				else {
					knight2.DrawCharacter();
				}
			}
			else {
				knight2.damage_pic(player2_state, "assests/fighter1(D).png");
				knight.add_power(5);
				player2_state = false;
			}
		}
		EndDrawing();
		// playrer 1 right moving chek 
		if (IsKeyDown(KEY_D)) {
				if (!knight.chekposition_x(1150, 470)) {
					knight.MoveCharacter(1);
				}
				knight.set_facing(true);
		}
		// player 1 left move chek 
		if (IsKeyDown(KEY_A)) {
				
					if (!knight.chekposition_x(1150, 470)) {
						knight.MoveCharacter(0);
					}

				knight.set_facing(false);
			}
		// player 1 left move end

		// player 2 cheks firts for the right move 
		if (IsKeyDown(KEY_RIGHT)) {
					if (!knight2.chekposition_x(1150, 470)) {
						knight2.MoveCharacter(1);
					}			
				knight2.set_facing(false);
		}
		// player 2 left move chek 
		if (IsKeyDown(KEY_LEFT)) {
					if (!knight2.chekposition_x(1150, 470)) {
						knight2.MoveCharacter(0);
					}
					knight2.set_facing(true);
		}

	}
	UnloadTexture(background);
	knight.unloadtexture();
	knight.unloading();
	knight.unload_Special_attack();
	knight2.unloadtexture();
	knight2.unloading();
	knight2.unload_Special_attack();
	CloseWindow();
return 0;
}
