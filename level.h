#pragma once
#define LEVEL_H
#include <iostream>
#include "raylib.h"
#include "string.h"
#include "player.h"
#include "enemy.h"
#include <fstream>
#include "boss.h"

class level {
	DA <enemy> bots;
	boss b1;
	bool status;
	Texture2D pic_level;
	fstream file;
public :

	level() = default;
	level(const DA<enemy>& other, const boss& chaudry, const char* filename) : bots{ other }, b1{ chaudry }, status{ false } { pic_level = LoadTexture(filename); };
	level(const level& other) :bots{ other.bots }, b1{ other.b1 }, status{ other.status } {
		Image temp = LoadImageFromTexture(other.pic_level);
		pic_level = LoadTextureFromImage(temp);
		UnloadImage(temp);
	};
	level& operator=(const level& other) {
		bots = other.bots;
		b1 = other.b1;
		Image temp = LoadImageFromTexture(other.pic_level);
		pic_level = LoadTextureFromImage(temp);
		UnloadImage(temp);
		status = other.status;
	}

	bool return_state() { return status; }
	void set_status(bool istrue) {
		status = istrue;
	}

	void load(fstream& f) {
		try {
			if (f.is_open()) {
				f.write((char*)status, sizeof(status));
			}
			else {
				throw runtime_error("File could not be opened");
			}
		}
		catch (const exception& e) {
			cout << "Exception caught" << e.what() << endl;
		}
		
	}

	void unload(fstream& f) {
		try {
			if (f.is_open()) {
				f.read((char*)status, sizeof(status));
			}
			else {
				throw runtime_error("File could not be opened");
			}
		}
		catch (const exception& e) {
			cout << "Exception caught" << e.what() << endl;
		}
	}



	void run_game(player& knight) {
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
				b1.DrawRectangleLines_hp(780, 10, 101, 21);
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
					for (int i = 0;i < bots.size();i++) {
						if (!CheckCollisionRecs(knight.get_Tec(), bots[i].get_Tec())) { bots[i].movecharacter(knight.return_position_of_x()); }
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
						for (int i = 0;i < bots.size();i++) {
							bots[i].set_state(CheckCollisionRecs(knight.get_Tec(), bots[i].get_Tec()));
						}
					}
					else {
						b1.set_state(CheckCollisionRecs(knight.get_Tec(), b1.get_Tec()));
					}

					if (IsKeyPressed(KEY_J)) {
						if (all_true) {
							for (int i = 0;i < bots.size();i++) {
								bots[i].chek_collision(bots[i].return_set_state(), knight.return_damage_of_attack(0));
								if (bots[i].return_set_state()) {
									knight.add_power(4);
									if (bots[i].return_status() == false) {
										bots.remove_at(i);
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
						for (int i = 0;i < bots.size();i++) {
							bots[i].set_state(CheckCollisionRecs(knight.get_Tec(), bots[i].get_Tec()));
						}
					}
					else {
						b1.set_state(CheckCollisionRecs(knight.get_Tec(), b1.get_Tec()));
					}
					if (IsKeyPressed(KEY_K)) {
						if (all_true) {
							for (int i = 0;i < bots.size();i++) {
								bots[i].chek_collision(bots[i].return_set_state(), knight.return_damage_of_attack(1));
								if (bots[i].return_set_state()) {
									knight.add_power(3);
									if (bots[i].return_status() == false) {
										bots.remove_at(i);
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
					knight.draw_special_power(knight.return_facing());
					if (all_true) {
						for (int i = 0;i < bots.size();i++) {
							bots[i].set_state(CheckCollisionRecs(knight.get_Tec(), bots[i].get_Tec()));
						}
					}
					else {
						b1.set_state(CheckCollisionRecs(knight.get_Tec(), b1.get_Tec()));
					}
					if (IsKeyPressed(KEY_L)) {
						if (all_true) {
							for (int i = 0;i < bots.size();i++) {
								bots[i].chek_collision(bots[i].return_set_state(), knight.return_dm_of_special());
								if (bots[i].return_set_state()) {
									if (bots[i].return_status() == false) {
										bots.remove_at(i);
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
				for (int i = 0;i < bots.size();i++) {
					player1_state = CheckCollisionRecs(knight.get_Tec(), bots[i].get_Tec());
					// player  movement 
					if (player1_state && !(IsKeyDown(KEY_J)) && !(IsKeyDown(KEY_K)) && !(IsKeyDown(KEY_L))) {
						bots[i].draw_text_call(bots[i].return_moving_right());
						if (knight.can_take_damage()) {
							knight.chek_collision(true, bots[i].return_damage_of_attack());
							knight.reset_damage_cooldown();
						}
						if (knight.return_status() == false) {
							break;
						}
						else {
							bots[i].set_attack();
						}
					}
					else {
						if (!bots[i].return_set_state()) {
							if (bots[i].return_moving_right()) {
								bots[i].DrawCharacter();
							}
							else {
								bots[i].chekfacing(false);
							}
						}
						else {
							bots[i].damage_pic(true);
							bots[i].DrawRectangle_hp(780 - i * 220, 10, 20);
							bots[i].DrawRectangleLines_hp(780 - i * 220, 10, 51, 21);
							bots[i].set_state(false);
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


			if (bots.size() <= 0) {
				all_true = false;
				c++;
			}

		}
		UnloadTexture(background);
		UnloadTexture(fight);
		UnloadTexture(boss1);
	}
};
// enemies and one boss player not needed just initialize void work logic level array in game maneger status of level locked or un locked an be saved in file and 
// data present on main can also be saved if needed texture needed of level menue also needed which level to play in manager 