//#include "game_manager.h"
//
////game_manager::game_manager(const DA <player>& other) : list{other} {}
//void game_manager::return_choice() {
//	int choice = 0;
//	if (choice == 1) {
//		this->run_PVP();
//	}
//	else if(choice==2){
//		// level mode 
//	}
//}
//
//void game_manager::run_PVP() {
//	int choice = 0;
//	player p1, p2;
//	cout << "Choose your character given below  Player 1 : ";
//	this->list.display();
//	cout << "Enter your choice : ";
//	cin >> choice;
//	cout << endl;
//	p1 = this->list[choice];
//	cout << "Choose your character given below player 2 : ";
//	this->list.display();
//	choice = 0;
//	cout << "Enter your choice : ";
//	cin >> choice;
//	p2 = this->list[choice];
//	char turn = 'x';
//	while (p1.return_status()== false || p2.return_status() == false) {
//		if (turn == 'x') {
//			char marzi = 0 ;
//		//	if (p1.allow_sp_attack()) {
//				cout << "You have your special attack use now  " << p1.return_name() << endl;
//				cout << "You want to use it or not (y/n) enter : ";
//				cin >> marzi;
//				if (marzi == 'y') {
//					p2.receiveDamage(p1.return_dm_of_special());
//					p1.set_power();
//				}
//			}
//			if (marzi != 'y' || marzi == 'n') {
//				cout << "Lists of Attack " << p1.return_name() << "  have: ";
//				p1.display_attacks();
//				cout << p1.return_name() << " your turn choose your attack : ";
//				int bata = 0;
//				cin >> bata;
//				p2.receiveDamage(p1.return_damage_of_attack(bata));
//				p1.add_power(p1.return_damage_of_attack(bata) * (80 / 100));
//			}
//		}
//		else {
//			char marzi = 0;
//			if (p2.allow_sp_attack()) {
//				cout << "You have your special attack use now  " << p2.return_name() << endl;
//				cout << "You want to use it or not (y/n) enter : ";
//				cin >> marzi;
//				if (marzi == 'y' || marzi == 'n') {
//					p1.receiveDamage(p2.return_dm_of_special());
//					p2.set_power();
//				}
//			}
//			if (marzi != 'y') {
//				cout << "Lists of Attack " << p2.return_name() << " have: ";
//				p2.display_attacks();
//				cout << p2.return_name() << " your turn choose your attack : ";
//				int bata = 0;
//				cin >> bata;
//				p1.receiveDamage(p2.return_damage_of_attack(bata));
//				p2.add_power(p2.return_damage_of_attack(bata) * (80 / 100));
//			}
//		}
//		if (turn == 'x') {
//			turn = 'y';
//		}
//		else {
//			turn = 'x';
//		}
//	}
//	if (p1.return_status() == false) {
//		cout << "Player 2 has won " << endl;
//	}
//	else if(p2.return_status() == false){
//		cout << "Player 1 has won " << endl;
//	}
//}