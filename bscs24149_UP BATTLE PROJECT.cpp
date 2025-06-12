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
	
	DA <Simple_Attack> a (Simple_Attack(10, "Punch", "assests/fighter1(J).png"));
	a.add(Simple_Attack(10, "Kick", "assests/fighter1(K).png"));
	special_attack s(100,"Blast",20,"assests/fighter(L).png");
	player knight("Sir Braver", 200, 5,a,s, "assests/fighter1(D).png");
	knight.LoadTextureFromFile("assests/fighter1.png");
	knight.SetPosition({ 0, 300 });
	knight.SetSpeed(0.5f);

	player knight2("Sir Braver", 200, 5, a,s, "assests/fighter1(D).png");
	knight2.LoadTextureFromFile("assests/fighter1.png");
	knight2.SetPosition({ 800, 300 });
	knight2.SetSpeed(0.5f);
	cout << "Hello world how are you wht are you doing " << endl;

	DA<player>p(knight);
	p.add(knight2);
	try {
		game_manager* g = game_manager::get_instance();
		
	}
	catch (const String& other) {
		cout << other;
	}
	CloseWindow();
return 0;
}
