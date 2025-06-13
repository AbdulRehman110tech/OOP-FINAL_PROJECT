#include <iostream>
#include "character.h"
#include "player.h"
#include "simple_attack.h"
#include "raylib.h"
#include "special_attack.h"
#include "game_manager.h"
using namespace std;

game_manager * game_manager::instance = nullptr;
int main(){
	InitWindow(1000, 470, "Battle Game");
	
	DA <Simple_Attack> a (Simple_Attack(3, "Punch", "assests/fighter1(J).png"));
	a.add(Simple_Attack(3, "Kick", "assests/fighter1(K).png"));
	special_attack s(100,"Blast",5,"assests/fighter(L).png");
	player knight("Sir Braver", 200, 0,a,s, "assests/fighter1(D).png");
	knight.LoadTextureFromFile("assests/fighter1.png");

	knight.SetSpeed(0.5f);

	DA <Simple_Attack> a2(Simple_Attack(3, "Punch", "assests/fighter2(M).png"));
	a2.add(Simple_Attack(3, "Kick", "assests/fighter2(N).png"));
	special_attack s2(100, "Blast", 5, "assests/fighter2(B).png");
	player knight2("Sir Braver", 200,0, a2,s2, "assests/fighter2(D).png");
	knight2.LoadTextureFromFile("assests/fighter2.png");
	knight2.SetSpeed(0.5f);
	
	DA<player>p;p = knight;p.add(knight2);

	
	try {
		game_manager* g = game_manager::get_instance();
		g->load_data(p);
		//g->show_charcaters();
		g->show_menue("assests/menue.png");
	}
	catch (const String& other) {
		cout << other;
	}
	CloseWindow();
return 0;
}
