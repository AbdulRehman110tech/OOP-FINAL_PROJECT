#include "game_manager.h"

//game_manager::game_manager(const DA <player>& other) : list{other} {}
void game_manager::show_menue(const char* filename) {
	bool istrue = true;
	Texture2D background_menue = LoadTexture(filename);
	
	while (istrue) {
		BeginDrawing();
		DrawTexturePro(background_menue, Rectangle{ 0, 0, (float)background_menue.width, (float)background_menue.height }, Rectangle{ 0, 0, 1000.0f, 470.0f }, Vector2{ 0, 0 }, (float)0.0f, WHITE);
		Rectangle pvpButton1 = { 250, 50, 200, 60 };
		DrawText("PvP MODE (P)", pvpButton1.x + 40, pvpButton1.y + 15, 80, WHITE);
		Rectangle pvpButton2 = { 250, 150, 200, 60 };
		DrawText("LEVEL GAME (L)", pvpButton2.x + 40, pvpButton2.y + 15, 80, WHITE);
		Rectangle pvpButton3 = { 250, 250, 200, 60 };
		DrawText("EXIT (E)", pvpButton3.x + 40, pvpButton3.y + 15, 80, RED);
		EndDrawing();
		if (IsKeyDown(KEY_P)) {
			player one, two;
			this->menue_select_player(one, two,"assests/player.png");
			
		}
		else if (IsKeyDown(KEY_L)) {

		}
		else if (IsKeyDown(KEY_E)) {
			istrue = false;
		}
		
	}
	UnloadTexture(background_menue);
}

void game_manager::menue_select_player(player one,player two,const char* filename) {

	bool istrue1 = true;

	int j = 0;
	Texture2D backgroun_player = LoadTexture(filename);
	
	while (istrue1) {
		BeginDrawing();
		DrawTexturePro(backgroun_player, Rectangle{ 0, 0, (float)backgroun_player.width, (float)backgroun_player.height }, Rectangle{ 0, 0, 1000.0f, 470.0f }, Vector2{ 0, 0 }, (float)0.0f, WHITE);
		DrawText("Choose a given player from given set of players : ", 250, 20, 15, ORANGE);
		DrawText("Press Spcae bar to go to next charactcer ", 250, 430, 15, RED);
		
			if (IsKeyPressed(KEY_SPACE)) {
				j++;
				if (j >= list.size()) {
					j = 0;
				}
				
			}
			list[j].SetPosition(Vector2{ 400,250 });
			list[j].DrawCharacter();
		
		if (IsKeyPressed(KEY_ENTER)) {
			one = list[j];
			istrue1 = false;
		}
		EndDrawing();
	}
	j = 0;
	bool istrue2 = true;
	while (istrue2) {
		BeginDrawing();
		DrawText("Choose a given player from given set of players player 2: ", 250, 20, 15, ORANGE);
		DrawText("Press Spcae bar to go to next charactcer ", 250, 430, 15, RED);

		if (IsKeyPressed(KEY_SPACE)) {
			j++;
			if (j >= list.size()) {
				j = 0;
			}

		}
		list[j].SetPosition(Vector2{ 400,250 });
		list[j].DrawCharacter();


		if (IsKeyPressed(KEY_ENTER)) {
			two = list[j];
			istrue2 = false;
		}
		EndDrawing();
	}
	
	this->run_PVP(one,two);
}

void game_manager::run_PVP(player knight, player knight2) {
	Texture2D background = LoadTexture("assests/background1.png");
	knight.SetPosition(Vector2{ 0,300 });
	knight2.SetPosition(Vector2{ 800,300 });
	bool player1_state = false;
	bool player2_state = false;
	while (!WindowShouldClose() && knight.return_status() && knight2.return_status()) {
		BeginDrawing();
		DrawTexturePro(background, Rectangle{ 0, 0, (float)background.width, (float)background.height }, Rectangle{ 0, 0, 1000.0f, 470.0f }, Vector2{ 0, 0 }, (float)0.0f, WHITE);
		knight.DrawRectangle_hp(10, 10, 20);
		knight.DrawRectangleLines_hp(10, 10, 201, 21);
		knight.draw_power_bar(10, 28, 10);
		knight.draw_border_of_power(10, 28, 101, 11);
		knight2.DrawRectangle_hp(780, 10, 20);
		knight2.DrawRectangleLines_hp(780, 10, 201, 21);
		knight2.draw_power_bar(880, 28, 10);
		knight2.draw_border_of_power(880, 28, 101, 11);
		if (IsKeyDown(KEY_J) || IsKeyDown(KEY_K) || IsKeyDown(KEY_L)) {

			if (IsKeyDown(KEY_J)) {
				knight.draw_text_call(0, knight.return_facing());
				player2_state = CheckCollisionRecs(knight.get_Tec(), knight2.get_Tec());
				if (IsKeyPressed(KEY_J)) {
					knight2.chek_collision(player2_state, knight.return_damage_of_attack(0));
					if (player2_state) {
						if (knight2.return_status() == false) {
							DrawText("Player 1 WON ", 400, 30, 25, BLUE);
						}
					}
				}
			}
			else if (IsKeyDown(KEY_K)) {
				knight.draw_text_call(1, knight.return_facing());
				player2_state = CheckCollisionRecs(knight.get_Tec(), knight2.get_Tec());
				if (IsKeyPressed(KEY_K)) {
					knight2.chek_collision(player2_state, knight.return_damage_of_attack(0));
					if (player2_state) {
						if (knight2.return_status() == false) {
							DrawText("Player 1 WON ", 400, 30, 25, BLUE);
						}
					}
				}
			}
			else if (IsKeyDown(KEY_L) && knight.allow_sp_attack()) {
				knight.draw_special_power(knight.return_facing());
				// special power ma naam rakhwana ha file ka char aus ka attribute bna de ;
				player2_state = CheckCollisionRecs(knight.get_Tec(), knight2.get_Tec());
				knight2.chek_collision(player2_state, knight.return_damage_of_attack(0));
				if (player2_state) {
					if (knight2.return_status() == false) {
						DrawText("Player 1 WON ", 400, 30, 25, BLUE);
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
					knight.chekfacing(true);
				}
			}
			else {
				knight.damage_pic(player1_state);
				knight2.add_power(0.2);
				player1_state = false;
			}
		}

		if (IsKeyDown(KEY_M) || IsKeyDown(KEY_N) || IsKeyDown(KEY_B)) {

			if (IsKeyDown(KEY_M)) {
				bool temp = knight2.return_facing();
				temp ^= true ^ false;
				knight2.draw_text_call(0, temp);
				player1_state = CheckCollisionRecs(knight.get_Tec(), knight2.get_Tec());
				if (IsKeyPressed(KEY_M)) {
					knight.chek_collision(player1_state, knight2.return_damage_of_attack(0));
					if (player1_state) {
						if (knight.return_status() == false) {
							DrawText("Player 2 WON ", 400, 30, 25, BLUE);
							break;
						}
					}
				}
			}
			else if (IsKeyDown(KEY_N)) {
				bool temp = knight2.return_facing();
				temp ^= true ^ false;
				knight2.draw_text_call(1, temp);
				player1_state = CheckCollisionRecs(knight.get_Tec(), knight2.get_Tec());
				if (IsKeyPressed(KEY_N)) {
					knight.chek_collision(player1_state, knight2.return_damage_of_attack(0));
					if (player1_state) {
						if (knight.return_status() == false) {
							DrawText("Player 2 WON ", 400, 30, 25, BLUE);
						}
					}
				}
			}
			else if (IsKeyDown(KEY_B)) {
				if (knight2.allow_sp_attack()) {
					knight2.draw_special_power(knight.return_facing());
					player1_state = CheckCollisionRecs(knight.get_Tec(), knight2.get_Tec());
					knight.chek_collision(player1_state, knight2.return_damage_of_attack(0));
					if (player1_state) {
						if (knight.return_status() == false) {
							DrawText("Player 2 WON ", 400, 30, 25, BLUE);
							break;
						}
					}
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
				knight2.damage_pic(player2_state);
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
}