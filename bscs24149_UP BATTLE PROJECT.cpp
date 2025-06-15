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
	DA <Simple_Attack> a(Simple_Attack(3, "Punch", "assests/fighter1(J).png"));
	a.add(Simple_Attack(5, "Kick", "assests/fighter1(K).png"));
	a.add(Simple_Attack(10, "Blast", "assests/fighter(L).png"));
	special_attack s(100, "Blast", 10, "assests/fighter(L).png");
	player knight("Sir Braver", 200, 0, a, s, "assests/fighter1(D).png");
	knight.LoadTextureFromFile("assests/fighter1.png");
	knight.SetSpeed(10.0f);
	knight.SetPosition(Vector2{ 0,300 });
	enemy e("kuta", 50, 0, "falto", 1, "assests/little(attack).png", "assests/gorilla(damage).png", 3);
	e.LoadTextureFromFile("assests/little(idle).png");
	enemy en("kuta", 50, 0, "falto", 1, "assests/little(attack).png", "assests/gorilla(damage).png", 3);
	en.LoadTextureFromFile("assests/little(idle).png");
	enemy e2("kuta", 200, 0, "falto",3, "assests/fighter3(J).png", "assests/fighter3(D).png", 7);
	e2.LoadTextureFromFile("assests/fighter3.png");e2.SetSpeed(2.0f);
	DA<enemy> e1(e);
	DA<enemy> e3(en);
	e1.add(e); e1.add(e);
	special_attack s4(100, "Blast", 1, "assests/fighter3(L).png");
	boss b1(e2, s4);
	DA <Simple_Attack> a2(Simple_Attack(3, "Punch", "assests/fighter2(M).png"));
	a2.add(Simple_Attack(3, "Kick", "assests/fighter2(N).png"));
	special_attack s2(100, "Blast", 5, "assests/fighter2(B).png");
	player knight2("Sir Braver", 200, 0, a2, s2, "assests/fighter2(D).png");
	knight2.LoadTextureFromFile("assests/fighter2.png");
	knight2.SetSpeed(10.0f);
	DA <Simple_Attack> a3(Simple_Attack(3, "Punch", "assests/fighter3(J).png"));
	a3.add(Simple_Attack(3, "Kick", "assests/fighter3(K).png"));
	special_attack s3(100, "Blast", 5, "assests/fighter3(L).png");
	player knight3("Sir Braver", 200, 0, a3, s3, "assests/fighter3(D).png");
	knight3.LoadTextureFromFile("assests/fighter3.png");
	knight3.SetSpeed(10.0f);
	DA<player>p;p = knight;p.add(knight2);p.add(knight3);
	level l(e1, b1, "assests/level.png");
	DA <level> l1(l);
	l1.add(level(e2, b1, "assests/level.png"));
	try {
		game_manager* g = game_manager::get_instance();
		g->load_data(p,l);
		g->show_menue("assests/menue.png");
	}
	catch (const String& other) {
		cout << other;
	}

	CloseWindow();
return 0;
}
