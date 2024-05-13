#include <windows.h>
#include <random>
#include <iostream>
#include <vector>

using namespace std;
//sleep(400); - задержка выполнения кода
int answ;
char answ1;

class Stats {
		public:
			int hp;
			int damage;
			string name;
			int resistance;
			int mana;
			int mag_resistance;
			double attack_speed;
	};

class Item : public Stats {
	public:
		Item(int vhp, int vdamage, string vname, int vresistance, int vmana, double vattack_speed, int vmag_resitance, int vmagdamage) {
			hp = vhp;
			damage = vdamage;
			name = vname;
			resistance = vresistance;
			mana = vmana;
			attack_speed = vattack_speed;
			mag_resistance = vmag_resitance;
			magdamage = vmagdamage;
		}
		int magdamage;
		int id;
		~Item() {
			this->hp = 0;
			this->damage = 0;
			this->resistance = 0;
			this->mag_resistance = 0;
			this->attack_speed = 0;
		}
};
	
class Inventory : public Stats {
	public:
		~Inventory() {
				this->hp = 0;
				this->damage = 0;
				this->resistance = 0;
				this->mag_resistance = 0;
				this->attack_speed = 0;
			}
		int gold;
};

class Enemy : public Stats {
	public:
		Enemy(int vhp, int vdamage, string vname, int vresistance, int vmana, int vmag_resitance , double vattack_speed) { // Конструктор obj_enemy
			hp = vhp;
			damage = vdamage;
			name = vname;
			resistance = vresistance;
			mana = vmana;
			mag_resistance = vmag_resitance;
			attack_speed = vattack_speed;
		}
		~Enemy() { // Деструктор obj_enemy
			this->hp = 0;
			this->damage = 0;
			this->resistance = 0;
			this->mag_resistance = 0;
			this->attack_speed = 0;
		}
};

class Player : public Stats {
	public:
		Player(int vhp, int vdamage, string vname, int vresistance, int vmana, double vattack_speed, int vmag_resitance, int vmagdamage) { // Конструктор obj_player
			hp = vhp;
			damage = vdamage;
			name = vname;
			resistance = vresistance;
			mana = vmana;
			attack_speed = vattack_speed;
			mag_resistance = vmag_resitance;
			magdamage = vmagdamage;
		}
		int magdamage;
		~Player() { // Деструктор obj_player
			this->hp = 0;
			this->damage = 0;
			this->resistance = 0;
			this->mag_resistance = 0;
			this->attack_speed = 0;
			this->magdamage = 0;
			this->mana = 0;
		}
};




// обьект игрока
Player player(100, 10, "Player", 0, 10, 1, 10, 10);

// обьекты врагов
Enemy goblin(100, 25, "Goblin", 1, 10, 2, 3000);
Enemy boss(1000, 80, "Boss", 10, 150, 10, 1000);

// обьекты предметов
Item BasicAxe(0, 15, "BasicAxe", -1, 0, 0.0, 0, 0);
Item BasicHelmet(20, 0, "BasicHelmet", 5, 0.1, 0, 0, 0);
Item BasicWand(0, 0, "BasicHelmet", 0, 50, 0.0, -2 , 10);

void answer() {
	while (answ > 3) {
		cout << "WARRNING:! \n Вы ввели не правильные данные. Попробуйет еще раз\n";
		cin >> answ;
	}
}

void goblin_kick() {
	Sleep(goblin.attack_speed * 1000);
	cout << "Гоблин ударил вас!\n";
	player.hp -= goblin.damage;
	cout << player.hp;
}

void player_kick() {
	cout << player.attack_speed;
	Sleep(player.attack_speed * 1000);
	cout << "Вы ударили гоблина\n";
	goblin.hp -= player.damage;
	cout << goblin.hp;
}

int main() {
	setlocale(LC_ALL, "RU");
	random_device rd;
    mt19937 gen(rd());
	uniform_int_distribution<> yaya(10 , 25);
	uniform_int_distribution<> exp(100, 500);
    bool factor = true;
	cout << "Игра началась!\n Выберите начальный предемет:\n\n1: Топор:" << BasicAxe.name << "\n  - физ. урон: +" << BasicAxe.damage << "\n  - снижение резиста: " << BasicAxe.resistance << "\n2: Шлем:" << BasicHelmet.name << "\n  - повышение резиста: +" << BasicHelmet.resistance << "\n  - увеличение скорости атаки: +" << BasicHelmet.attack_speed << "\n  - повышение хп: +" << BasicHelmet.hp << "\n3: Посох:" << BasicWand.name << "\n  - увеличение маны: +" << BasicWand.mana << "\n  - увеличение маг. урона: +" << BasicWand.magdamage << "\n  - снижение маг. резиста противников: " << BasicWand.mag_resistance << "\n\n";
	cin >> answ;
	while (true) {

		if (answ == 1) {
			player.damage += 22;
			goblin.resistance -= 1;
			boss.resistance -= 1;
		}
		else if (answ == 2) {
			player.resistance += 5;
			player.attack_speed -= 0.1;
			answ = 0;

		}
		else if (answ == 3) {
			player.mana += 50;
			player.magdamage += 10;
			boss.mag_resistance -= 2;
			goblin.mag_resistance -= 2;
			cout << player.mana << "\n" << player.magdamage << "\n" << boss.mag_resistance << "\n" << goblin.mag_resistance << endl;
		}
		else if (answ > 3) {
			answer();
		}
		for (int i = 0; i < 3; i++) {
			Sleep(1250);
			cout << "Вы гуляете по миру\n";
		}
		cout << "Вы встретили " << goblin.name << "! Желаете сразиться? 'Y'(yes)/'N'(no)" << endl;
		cin >> answ1;
		if (answ1 == 'Y' || answ1 == 'y') {
			cout << goblin.hp << endl;
			cout << player.hp <<  endl;
			while (true) {
				player_kick();
				goblin_kick();
				
				
				
				
				/*if (player.hp > 0 && goblin.hp > 0) {
					cout << "Вы получили " << yaya(gen) << " золота, " << exp(gen) << " опыта";
					break;
				}
				else {
					cout << "Вы проиграли :(";
					break;
				}*/
			}
		}
	}
	return 0;
}
