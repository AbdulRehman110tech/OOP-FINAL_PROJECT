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
			this->menue_select_player_run_pvp("assests/player.png");
		}
		else if (IsKeyDown(KEY_L)) {

		}
		else if (IsKeyDown(KEY_E)) {
			istrue = false;
		}
		
	}
	UnloadTexture(background_menue);
}

void game_manager::menue_select_player_run_lvl(const char* filename) {
	bool istrue1 = true;
	int i1 = 0, i2 = 0;
	int j = 0;
	Texture2D backgroun_player = LoadTexture(filename);
	SetTargetFPS(60);
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
			i1 = j;
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
			i2 = j;
			istrue2 = false;
		}
		EndDrawing();
	}
	//level menue bnan ab 
}

void game_manager::menue_select_player_run_pvp(const char* filename) {
	bool istrue1 = true;
	int i1 = 0, i2 = 0;
	int j = 0;
	Texture2D backgroun_player = LoadTexture(filename);
	SetTargetFPS(60);
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
			i1 = j;
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
			i2 = j;
			istrue2 = false;
		}
		EndDrawing();
	}
	
	this->run_PVP(i1,i2);
}

void game_manager::run_PVP(int index1,int index2) {

	bool move = true;
	Texture2D fight = LoadTexture("assests/fight(image).png");
	player one, two;
	one = list[index1];
	two = list[index2];
	Texture2D background = LoadTexture("assests/background1.png");
	one.SetPosition(Vector2{0,300});
	two.SetPosition(Vector2{800,300});
	bool player1_state = false;
	bool player2_state = false;
	while (!WindowShouldClose() && one.return_status() && two.return_status()) {
		BeginDrawing();

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
		DrawTexturePro(background, Rectangle{ 0, 0, (float)background.width, (float)background.height }, Rectangle{ 0, 0, 1000.0f, 470.0f }, Vector2{ 0, 0 }, (float)0.0f, WHITE);
		one.DrawRectangle_hp(10, 10, 20);
		one.DrawRectangleLines_hp(10, 10, 201, 21);
		one.draw_power_bar(10, 28, 10);
		one.draw_border_of_power(10, 28, 101, 11);
		two.DrawRectangle_hp(780, 10, 20);
		two.DrawRectangleLines_hp(780, 10, 201, 21);
		two.draw_power_bar(880, 28, 10);
		two.draw_border_of_power(880, 28, 101, 11);
		if (IsKeyDown(KEY_J) || IsKeyDown(KEY_K) || IsKeyDown(KEY_L)) {
			if (IsKeyDown(KEY_J)) {
				one.draw_text_call(0, one.return_facing());
				player2_state = CheckCollisionRecs(one.get_Tec(), two.get_Tec());
				if (IsKeyPressed(KEY_J)) {
					two.chek_collision(player2_state, one.return_damage_of_attack(0));
					if (player2_state) {
						one.add_power(3);
						if (two.return_status() == false) {
							break;
						}
					}
				}
			}
			else if (IsKeyDown(KEY_K)) {
				one.draw_text_call(1, one.return_facing());
				player2_state = CheckCollisionRecs(one.get_Tec(), two.get_Tec());
				if (IsKeyPressed(KEY_K)) {
					two.chek_collision(player2_state, one.return_damage_of_attack(0));
					if (player2_state) {
						one.add_power(3);
						if (two.return_status() == false) {
							break;
						}
					}
				}
			}
			else if (IsKeyDown(KEY_L) && one.allow_sp_attack()) {
					one.draw_special_power(one.return_facing());
				// special power ma naam rakhwana ha file ka char aus ka attribute bna de ;
				player2_state = CheckCollisionRecs(one.get_Tec(), two.get_Tec());
				two.chek_collision(player2_state, one.return_damage_of_attack(0));
				if (player2_state) {
					if (two.return_status() == false) {
						break;
					}
				}
				one.set_power();
			}

		}
		else {
			if (player1_state == false) {
				if (one.return_facing()) {
					one.DrawCharacter();
				}
				else {
					one.chekfacing(false);
				}
			}
			else {
				one.damage_pic(player1_state);
				player1_state = false;
			}
		}

		if (IsKeyDown(KEY_M) || IsKeyDown(KEY_N) || IsKeyDown(KEY_B)) {

			if (IsKeyDown(KEY_M)) {
				bool temp = two.return_facing();
				temp ^= true ^ false;
				two.draw_text_call(0, temp);
				player1_state = CheckCollisionRecs(one.get_Tec(), two.get_Tec());
				if (IsKeyPressed(KEY_M)) {
					one.chek_collision(player1_state, two.return_damage_of_attack(0));
					if (player1_state) {
						two.add_power(2);
						if (one.return_status() == false) {
					
							break;
						}
					}
				}
			}
			else if (IsKeyDown(KEY_N)) {
				bool temp = two.return_facing();
				temp ^= true ^ false;
				two.draw_text_call(1, temp);
				player1_state = CheckCollisionRecs(one.get_Tec(), two.get_Tec());
				if (IsKeyPressed(KEY_N)) {
					one.chek_collision(player1_state, two.return_damage_of_attack(0));
					if (player1_state) {
						two.add_power(2);
						if (one.return_status() == false) {
				
						}
					}
				}
			}
			else if (IsKeyDown(KEY_B)) {
				if (two.allow_sp_attack()) {
					two.draw_special_power(one.return_facing());
					player1_state = CheckCollisionRecs(one.get_Tec(), two.get_Tec());
					one.chek_collision(player1_state, two.return_damage_of_attack(0));
					if (player1_state) {
						if (one.return_status() == false) {
							break;
						}
					}
					two.set_power();
				}
			}
		}
		else {
			if (player2_state == false) {
				if (two.return_facing()) {
					two.chekfacing(false);
				}
				else {
					two.DrawCharacter();
				}
			}
			else {
				two.damage_pic(player2_state);
				player2_state = false;
			}
		}
		EndDrawing();
		// playrer 1 right moving chek 
		if (IsKeyDown(KEY_D)) {
			if (!one.chekposition_x(1150, 470)) {
				one.MoveCharacter(1);
			}
			one.set_facing(true);
		}
		// player 1 left move chek 
		if (IsKeyDown(KEY_A)) {

			if (!one.chekposition_x(1150, 470)) {
				one.MoveCharacter(0);
			}

			one.set_facing(false);
		}
		// player 1 left move end

		// player 2 cheks firts for the right move 
		if (IsKeyDown(KEY_RIGHT)) {
			if (!two.chekposition_x(1150, 470)) {
				two.MoveCharacter(1);
			}
			two.set_facing(false);
		}
		// player 2 left move chek 
		if (IsKeyDown(KEY_LEFT)) {
			if (!two.chekposition_x(1150, 470)) {
				two.MoveCharacter(0);
			}
			two.set_facing(true);
		}
	}
	Texture2D   win1 = LoadTexture("assests/player1(W).png");
	Texture2D   win2 = LoadTexture("assests/player2(W).png");
	while (!IsKeyPressed(KEY_ENTER)) {
		BeginDrawing();
		DrawTexturePro(background, Rectangle{ 0, 0, (float)background.width, (float)background.height }, Rectangle{ 0, 0, 1000.0f, 470.0f }, Vector2{ 0, 0 }, (float)0.0f, WHITE);
		if (one.return_status()) {
			DrawTexturePro(win1, Rectangle{ 0,0,(float)win1.width,(float)win1.height }, Rectangle{ 300,30,(float)win1.width*2,(float)win1.height*2 }, Vector2{ 0,0 }, (float)0.0f, WHITE);
		}
		else {
			DrawTexturePro(win2, Rectangle{ 0,0,(float)win2.width,(float)win2.height }, Rectangle{ 300,30,(float)win2.width*2,(float)win2.height*2 }, Vector2{ 0,0 }, (float)0.0f, WHITE);
		}
		EndDrawing();
	}
	UnloadTexture(background);
	UnloadTexture(win1);
	UnloadTexture(fight);
	UnloadTexture(win2);
}