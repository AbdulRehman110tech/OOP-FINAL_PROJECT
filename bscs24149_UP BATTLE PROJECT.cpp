#include <iostream>
#include "character.h"
#include "player.h"
#include "simple_attack.h"
#include "raylib.h"
#include "special_attack.h"
using namespace std;

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
	

	
	CloseWindow();
return 0;
}
