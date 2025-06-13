#include <iostream>
#include "character.h"
#include "player.h"
#include "simple_attack.h"
#include "raylib.h"
#include "special_attack.h"
#include "game_manager.h"
#include "enemy.h"
#include<cstdlib>
using namespace std;

game_manager * game_manager::instance = nullptr;
int main(){
	InitWindow(1000, 470, "Battle Game");
	
	DA <Simple_Attack> a (Simple_Attack(3, "Punch", "assests/fighter1(J).png"));
	a.add(Simple_Attack(3, "Kick", "assests/fighter1(K).png"));
	special_attack s(100,"Blast",5,"assests/fighter(L).png");
	player knight("Sir Braver", 200, 0,a,s, "assests/fighter1(D).png");
	knight.LoadTextureFromFile("assests/fighter1.png");
	knight.SetSpeed(10.0f);
	knight.SetPosition(Vector2{ 0,300 });

	enemy e("kuta", 50, 0, "falto",0.9, "assests/little(attack).png","assests/gorilla(damage).png");
	e.LoadTextureFromFile("assests/little(idle).png");e.SetSpeed(3.0f);
	e.SetPosition(Vector2{ (float)(rand() % 1000),300 });

	//DA <Simple_Attack> a2(Simple_Attack(3, "Punch", "assests/fighter2(M).png"));
	//a2.add(Simple_Attack(3, "Kick", "assests/fighter2(N).png"));
	//special_attack s2(100, "Blast", 5, "assests/fighter2(B).png");
	//player knight2("Sir Braver", 200,0, a2,s2, "assests/fighter2(D).png");
	//knight2.LoadTextureFromFile("assests/fighter2.png");
	//knight2.SetSpeed(10.0f);
	//
	//DA<player>p;p = knight;p.add(knight2);
	//
	//try {
	//	game_manager* g = game_manager::get_instance();
	//	g->load_data(p);
	//	//g->show_charcaters();
	//	g->show_menue("assests/menue.png");
	//}
	//catch (const String& other) {
	//	cout << other;
	//}
	bool player1_state = false;
	Texture2D background = LoadTexture("assests/background1.png");
	SetTargetFPS(60);
	// last boot ke hp par band karwadena loop aur phir boss wala start kar dena 
	while (!WindowShouldClose() && knight.return_status()) {
		BeginDrawing();
		DrawTexturePro(background, Rectangle{ 0, 0, (float)background.width, (float)background.height }, Rectangle{ 0, 0, 1000.0f, 470.0f }, Vector2{ 0, 0 }, (float)0.0f, WHITE);
		knight.DrawRectangle_hp(10, 10, 20);
		knight.DrawRectangleLines_hp(10, 10, 201, 21);
		knight.draw_power_bar(10, 28, 10);
		knight.draw_border_of_power(10, 28, 101, 11);
		

		e.MoveCharacter(knight.return_position_of_x());
		if (IsKeyDown(KEY_J) || IsKeyDown(KEY_K) || IsKeyDown(KEY_L)) {
			if (IsKeyDown(KEY_J)) {
				knight.draw_text_call(0, knight.return_facing());
				e.set_state( CheckCollisionRecs(knight.get_Tec(), e.get_Tec()));
				if (IsKeyPressed(KEY_J)) {
					e.chek_collision(e.return_set_state(), knight.return_damage_of_attack(0));
					if (e.return_set_state()) {
						knight.add_power(3);
						if (e.return_status() == false) {
							break;
						}
					}
				}
			}

			else if (IsKeyDown(KEY_K)) {
				knight.draw_text_call(0, knight.return_facing());
				e.set_state(CheckCollisionRecs(knight.get_Tec(), e.get_Tec()));
				if (IsKeyPressed(KEY_K)) {
					e.chek_collision(e.return_set_state(), knight.return_damage_of_attack(0));
					if (e.return_set_state()) {
						knight.add_power(3);
						if (e.return_status() == false) {
							break;
						}
					}
				}
			}
			else if (IsKeyPressed(KEY_L) && knight.allow_sp_attack()) {
				// is ma allow attack ko rakh as chek jab trye ho to okay kar de andar rakh is key released while ke sath aur aus ma sirf picture rakh de ;
				while (!IsKeyReleased(KEY_L)) {
					DrawTexturePro(background, Rectangle{ 0, 0, (float)background.width, (float)background.height }, Rectangle{ 0, 0, 1000.0f, 470.0f }, Vector2{ 0, 0 }, (float)0.0f, WHITE);
					knight.draw_special_power(knight.return_facing());
					e.damage_pic(e.return_set_state());
					e.DrawRectangle_hp(780, 10, 20);
					e.DrawRectangleLines_hp(780, 10, 201, 21);
			    }
				// special power ma naam rakhwana ha file ka char aus ka attribute bna de ;
				e.set_state( CheckCollisionRecs(knight.get_Tec(), e.get_Tec()));
				e.chek_collision(e.return_set_state(), knight.return_damage_of_attack(0));
				if (e.return_set_state()) {
					if (e.return_status() == false) {
						break;
					}
				}
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
				knight.damage_pic(player1_state);

				player1_state = false;
			}
		}
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
		player1_state = CheckCollisionRecs(knight.get_Tec(), e.get_Tec());
		// player  movement 
		if (player1_state) {
			e.draw_text_call(e.return_moving_right());
			knight.chek_collision(player1_state, e.return_damage_of_attack());
			if (knight.return_status() == false) {
				break;
			}
		}
		else {
			if (!e.return_set_state()) {
				if (e.return_moving_right()) {
					e.DrawCharacter();
				}
				else {
					e.chekfacing(false);
				}
			}
			else {
				e.damage_pic(true);
				e.DrawRectangle_hp(780, 10, 20);
				e.DrawRectangleLines_hp(780, 10, 201, 21);
				e.set_state(false);
			}
		}




		EndDrawing();
	}

	
return 0;
}
