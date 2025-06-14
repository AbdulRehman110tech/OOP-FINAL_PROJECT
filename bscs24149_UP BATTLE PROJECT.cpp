#include <iostream>
#include "character.h"
#include "player.h"
#include "simple_attack.h"
#include "raylib.h"
#include "special_attack.h"
#include "game_manager.h"
#include "enemy.h"
#include "boss.h"
#include<cstdlib>
using namespace std;



game_manager * game_manager::instance = nullptr;
int main(){
	InitWindow(1000, 470, "Battle Game");
	
	DA <Simple_Attack> a (Simple_Attack(3, "Punch", "assests/fighter1(J).png"));
	a.add(Simple_Attack(5, "Kick", "assests/fighter1(K).png"));
	a.add(Simple_Attack(10, "Blast", "assests/fighter(L).png"));
	special_attack s(100,"Blast",10,"assests/fighter(L).png");
	player knight("Sir Braver", 200, 0,a,s, "assests/fighter1(D).png");
	knight.LoadTextureFromFile("assests/fighter1.png");
	knight.SetSpeed(10.0f);
	knight.SetPosition(Vector2{ 0,300 });

	enemy e("kuta",50, 0, "falto",1, "assests/little(attack).png","assests/gorilla(damage).png",3);
	e.LoadTextureFromFile("assests/little(idle).png");
	
	enemy e2	("kuta",100, 0, "falto",1, "assests/fighter3(J).png", "assests/fighter3(D).png",7);
	e2.LoadTextureFromFile("assests/fighter3.png");e2.SetSpeed(2.0f);

	DA<enemy> e1(e);
	e1.add(e); e1.add(e);

	for (int i = 0;i < e1.size();i++) {
		e1[i].SetSpeed(i+1);
	}
	
	special_attack s2(100, "Blast",1, "assests/fighter3(L).png");
	boss b1(e2,s2);
	Vector2 playerPos = knight.GetPosition();  // Get player's current position

	for (int i = 0;i < e1.size();i++) {
		e1[i].setting_position(playerPos);
	}

	b1.SetPosition(Vector2{ 800,300 });
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
	bool move = true, all_true = true;
	int c = 0;
	Texture2D background = LoadTexture("assests/background1.png");
	Texture2D fight = LoadTexture("assests/fight(image).png");
	Texture2D boss1 = LoadTexture("assests/boss.png");
	SetTargetFPS(60);
	while (!WindowShouldClose() && knight.return_status() && b1.return_status()) {
		BeginDrawing();
		knight.update_cooldown();
		b1.update_cooldown();
		DrawTexturePro(background, Rectangle{ 0, 0, (float)background.width, (float)background.height }, Rectangle{ 0, 0, 1000.0f, 470.0f }, Vector2{ 0, 0 }, (float)0.0f, WHITE);
		knight.DrawRectangle_hp(10, 10, 20);
		knight.DrawRectangleLines_hp(10, 10, 201, 21);
		knight.draw_power_bar(10, 28, 10);
		knight.draw_border_of_power(10, 28, 101, 11);
		if (all_true == false) {
			b1.DrawRectangle_hp(780, 10, 20);
			b1.DrawRectangleLines_hp(780, 10,101, 21);
			b1.draw_power_bar(880, 28, 10);
			b1.draw_border_of_power(880, 28, 101, 11);
		}
		
		while (move) {
			BeginDrawing();
				DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
				DrawTexturePro(fight, Rectangle{ 0,0,(float)fight.width,(float)fight.height }, Rectangle{ 300,30,(float)fight.width,(float)fight.height }, Vector2{ 0,0 }, (float)0.0f, WHITE);
				DrawText("Press Spcae bar to continue  ", 300, 450, 20, RED);
			if (IsKeyPressed(KEY_SPACE)) {
				move = false;
			}
			EndDrawing();
		}

		while (c == 1) {
			BeginDrawing();
			DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
			DrawTexturePro(boss1, Rectangle{ 0,0,(float)boss1.width,(float)boss1.height }, Rectangle{ 300,30,(float)boss1.width,(float)boss1.height }, Vector2{ 0,0 }, (float)0.0f, WHITE);
			DrawText("Press Spcae bar to continue ", 310, 450, 20, RED);
			if (IsKeyPressed(KEY_SPACE)) {
				c++;
			}
			EndDrawing();
		}


	if (move == false) {
		if (all_true) {
			for (int i = 0;i < e1.size();i++) {
				if (!CheckCollisionRecs(knight.get_Tec(), e1[i].get_Tec())) { e1[i].movecharacter(knight.return_position_of_x()); }
			}
		}
		else {
			if (!CheckCollisionRecs(knight.get_Tec(), b1.get_Tec())) {
				b1.movecharacter(knight.return_position_of_x());
			}
		}
	}

		if (IsKeyDown(KEY_J) || IsKeyDown(KEY_K) || IsKeyDown(KEY_L)) {
			if (IsKeyDown(KEY_J)) {
				knight.draw_text_call(0, knight.return_facing());
				if (all_true) {
					for (int i = 0;i < e1.size();i++) {
						e1[i].set_state(CheckCollisionRecs(knight.get_Tec(), e1[i].get_Tec()));
					}
				}
				else {
					b1.set_state(CheckCollisionRecs(knight.get_Tec(), b1.get_Tec()));
				}
				
				if (IsKeyPressed(KEY_J)) {
					if (all_true) {
						for (int i = 0;i < e1.size();i++) {
							e1[i].chek_collision(e1[i].return_set_state(), knight.return_damage_of_attack(0));
							if (e1[i].return_set_state()) {
								knight.add_power(4);
								if (e1[i].return_status() == false) {
									e1.remove_at(i);
								}
							}
						}
					}
					else {
						b1.chek_collision(b1.return_set_state(), knight.return_damage_of_attack(0));
						if (b1.return_set_state()) {
							knight.add_power(4);
							if (b1.return_status() == false) {
								break;
							}
						}
					}
					
				}
			}

			else if (IsKeyDown(KEY_K)) {
				knight.draw_text_call(1, knight.return_facing());
				if (all_true) {
					for (int i = 0;i < e1.size();i++) {
						e1[i].set_state(CheckCollisionRecs(knight.get_Tec(), e1[i].get_Tec()));
					}
				}
				else {
					b1.set_state(CheckCollisionRecs(knight.get_Tec(), b1.get_Tec()));
				}
				if (IsKeyPressed(KEY_K)) {
					if (all_true) {
						for (int i = 0;i < e1.size();i++) {
							e1[i].chek_collision(e1[i].return_set_state(), knight.return_damage_of_attack(1));
							if (e1[i].return_set_state()) {
								knight.add_power(3);
								if (e1[i].return_status() == false) {
									e1.remove_at(i);
								}
							}
						}
					}
					else {
						b1.chek_collision(b1.return_set_state(), knight.return_damage_of_attack(1));
						if (b1.return_set_state()) {
							knight.add_power(3);
							if (b1.return_status() == false) {
								break;
							}
						}
					}

				}
			}

			else if (IsKeyDown(KEY_L) && knight.allow_sp_attack()) {
				knight.draw_special_power( knight.return_facing());
				if (all_true) {
					for (int i = 0;i < e1.size();i++) {
						e1[i].set_state(CheckCollisionRecs(knight.get_Tec(), e1[i].get_Tec()));
					}
				}
				else {
					b1.set_state(CheckCollisionRecs(knight.get_Tec(), b1.get_Tec()));
				}
				if (IsKeyPressed(KEY_L)) {
					if (all_true) {
						for (int i = 0;i < e1.size();i++) {
							e1[i].chek_collision(e1[i].return_set_state(), knight.return_dm_of_special());
							if (e1[i].return_set_state()) {
								if (e1[i].return_status() == false) {
									e1.remove_at(i);
								}
							}
						}
					}
					else {
						b1.chek_collision(b1.return_set_state(), knight.return_dm_of_special());
						if (b1.return_set_state()) {
							knight.add_power(4);
							if (b1.return_status() == false) {
								break;
							}
						}
					}
					knight.set_power();
					knight.add_power(2);
				}
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


		if (all_true) {
			for (int i = 0;i < e1.size();i++) {
				player1_state = CheckCollisionRecs(knight.get_Tec(), e1[i].get_Tec());
				// player  movement 
				if (player1_state && !(IsKeyDown(KEY_J)) && !(IsKeyDown(KEY_K)) && !(IsKeyDown(KEY_L))) {
						e1[i].draw_text_call(e1[i].return_moving_right());
						if (knight.can_take_damage()) {
							knight.chek_collision(true, e1[i].return_damage_of_attack());
							knight.reset_damage_cooldown();
						}
						if (knight.return_status() == false) {
							break;
						}
						else {
							e1[i].set_attack();
						}
				}
				else {
					if (!e1[i].return_set_state()) {
						if (e1[i].return_moving_right()) {
							e1[i].DrawCharacter();
						}
						else {
							e1[i].chekfacing(false);
						}
					}
					else {
						e1[i].damage_pic(true);
						e1[i].DrawRectangle_hp(780 - i * 220, 10, 20);
						e1[i].DrawRectangleLines_hp(780 - i * 220, 10, 51, 21);
						e1[i].set_state(false);
					}
				}
			}
		}
		else {
			player1_state = CheckCollisionRecs(knight.get_Tec(), b1.get_Tec());
			if (player1_state && b1.allow_sp_attack()) {
				if (b1.can_take_damage()) {
					b1.draw_special_power(b1.return_moving_right());
					b1.reset_damage_cooldown();
				}
				if (knight.can_take_damage()) {
					knight.chek_collision(true, b1.return_damage_of_attack());
					knight.reset_damage_cooldown();
				}

				if (knight.return_status() == false) {
					break;
				}
				b1.set_power();
			}
			else if (player1_state && !(IsKeyDown(KEY_J)) && !(IsKeyDown(KEY_K)) && !(IsKeyDown(KEY_L))) {
					b1.draw_text_call(b1.return_moving_right());
					if (knight.can_take_damage()) {
						knight.chek_collision(true, b1.return_damage_of_attack());
						knight.reset_damage_cooldown();
					}
					if (knight.return_status() == false) {
						break;
					}
					else {
						b1.add_power(2);
						b1.set_attack();
					}
			}
			else {
				if (!b1.return_set_state()) {
					if (b1.return_moving_right()) {
						b1.DrawCharacter();
					}
					else {
						b1.chekfacing(false);
					}
				}
				else {
					b1.damage_pic(true);
					b1.set_state(false);
				}
			}
		}
		EndDrawing();


		if (e1.size() <= 0) {
			all_true = false;
			c++;
		}
	
}
	UnloadTexture(background);
	UnloadTexture(fight);
	UnloadTexture(boss1);
return 0;
}
