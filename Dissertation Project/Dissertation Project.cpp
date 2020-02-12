// Dissertation Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //two I/O stream things.
#include <fstream>
#include <windows.h> //this is for 'sleep'.
#include <string>
using namespace std;

//VARIABLES

int choice;
string loots;
int itemchoice;
int spellchoice;
int specification;
int aichoice;
bool cave1 = false;
bool cave2 = false;
bool cave3 = false;
bool line[4] = { true, false, false, false };

int levelone[5][5] = { 1,  2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
bool levelonebool[5][5] = { true, true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true };
char levelonechar[5][5] = { { 'X', 'X', 'X', 'X', 'X'} ,{ 'X', 'X', 'X', 'X', 'X'} ,{ 'X', 'X', 'X', 'X', 'X'} ,{ 'X', 'X', 'X', 'X', 'X'} ,{ 'X', 'X', 'X', 'X', 'X'} };

int leveltwo[6][6] = { 1,  2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36 };
bool leveltwobool[7][7] = { true, true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, true, true, true, true, true, true, true, true, true, true, true };
char leveltwochar[6][6] = { { 'X', 'X', 'X', 'X', 'X', 'X'},{ 'X', 'X', 'X', 'X', 'X', 'X' },{ 'X', 'X', 'X', 'X', 'X', 'X' },{ 'X', 'X', 'X', 'X', 'X', 'X' },{ 'X', 'X', 'X', 'X', 'X', 'X' },{ 'X', 'X', 'X', 'X', 'X', 'X' } };

int levelthree[7][7] = { 1,  2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49 };
bool levelthreebool[7][7] = { true, true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true };
char levelthreechar[7][7] = { { 'X', 'X', 'X', 'X', 'X', 'X', 'X' },{ 'X', 'X', 'X', 'X', 'X', 'X', 'X' },{ 'X', 'X', 'X', 'X', 'X', 'X', 'X' },{ 'X', 'X', 'X', 'X', 'X', 'X', 'X' },{ 'X', 'X', 'X', 'X', 'X', 'X', 'X' },{ 'X', 'X', 'X', 'X', 'X', 'X', 'X' },{ 'X', 'X', 'X', 'X', 'X', 'X', 'X' }, };

//IDENTIFIERS

int main();
void fightloop();
void drop();
void finalboss();

//CLASSES

class hero
{
public:
	void addX(int &x, int y) //these functions allows me to change the stats in any way. y doesn't need a pointer, as it's just the arbitrary number i'm adding to x.
	{
		x += y; //adds a certain number to whichever thing I want, and then checks if it's added too much or not.
	};
	void minusX(int &x, int y)
	{
		x -= y;
		if (x < 0)
		{
			x = 0;
		};
	};
	//BASIC STATS
	int ATK;
	int DEF;
	int MAG;
	int MP;
	int HP;
	int HitPoints;
	//LESS IMPORTANT
	string name;
	string sword;
	int inventory[15];
	int spellbook[8];
	//CONDITIONS
	bool poison;
	bool freeze;
	int points;
	int empowered;
	bool block;
	int ShieldHp = 20;
	int armorset = 0;
	bool light = false;
	//IMPORTANT STUFF	
	int GP;
	int kills;
	float lore;
	int swordchoice;
	int mapperc;
	int modifier = 0;
	bool TESTER = 0;
	//POSITIONALS
	int X;
	int Y;
	int PX;
	int PY;
};

class enemy
{
public:
	void addX(int &x, int y) //these functions allows me to change the stats in any way. y doesn't need a pointer, as it's just the arbitrary number i'm adding to x.
	{
		x += y; //adds a certain number to whichever thing I want, and then checks if it's added too much or not.
	};
	void minusX(int &x, int y)
	{
		x -= y;
		if (x < 0)
		{
			x = 0;
		};
	};
	int ATK;
	int HP;
	int DEF = 0;
	int MP;
	int MAG;
	string level;
	int lootlevel;
	string trait;
	bool poison;
	bool freeze;
	bool stun;
	int poisonpower = 1;
};

enemy TE;
hero varias;

//READING FUNCTIONS

void lineBreak(int breaks) //I just wanted to make this function so I could quickly make a lot of line breaks, for effect an ease of reading.
{
	for (int i = 1; i <= breaks; i++)
	{
		cout << endl;
	};
	Sleep(1500); //I don't want to be writing 'Sleep' too much, so this just makes it a bit easier.
};

void read(int choice, int lineNo) //this is a more complicated function that I learnt in my own time, using I/O stream. It's a large part of the code, and makes the code a lot easier to look at.
{
	string files[2]; //I made a second story file to read from, as the first was getting too large. These make it so I can read from both.
	files[0] = "story01.txt.txt";
	files[1] = "story02.txt";
	std::ifstream file(files[choice]); //fetches the certain 'story' file which holds all the dialogue for the game. Please don't move it.
	std::string line;
	int lineCount = 1;	//It's important to keep this initialised as '1', as this 'syncs up' the reading of the file with the integer 'lineCount'.
	while (std::getline(file, line)) //important I/O stream stuff, which essentially says 'while the file is open, read it'.
	{
		if (lineCount == lineNo) //makes sure to only read out the line I have specified in the function call.
		{
			std::cout << line << endl;
		}
		lineCount++; //the code loops until it reaches the line requested in the function call, and then will read it.
	}
	Sleep(2500); //this 'sleep' is just there to give the reader time to read and for effect. 'sleep' counts in milliseconds, sadly, so 2700 means it waits for 3 seconds.
};

void sectionRead(int choice, int a, int b) //after writing out this 'for' loop a few times in my code, I realised it would be even neater to use a my 'read' function inside a function!
{
	if (varias.TESTER = !1)
	{
		for (int i = a; i <= b; i++)
		{
			read(choice, i); //this 'for' loop just makes sure that it only reads between the certain parts of 'story' that I want. Specifically, between lines a and b.
		};
	}
};

//PREP FUNCTIONS

void EnemyCreator(int level)
{
	TE.poisonpower = 1;
	TE.poison = false;
	switch (level)
	{
	case 1:
		TE.minusX(TE.ATK, 40);
		TE.minusX(TE.HP, 40);
		//making sure theyre both at 0
		TE.addX(TE.ATK, 10);
		TE.addX(TE.HP, 10);
		TE.level = "Level 1 Rat";
		TE.trait = "null";
		TE.lootlevel = 1;
		break;
	case 2:
		TE.minusX(TE.ATK, 40);
		TE.minusX(TE.HP, 40);
		//making sure theyre both at 0
		TE.addX(TE.ATK, 15);
		TE.addX(TE.HP, 15);
		TE.level = "Level 2 Goblin";
		TE.trait = "null";
		TE.lootlevel = 2;
		break;
	case 3:
		TE.minusX(TE.ATK, 40);
		TE.minusX(TE.HP, 40);
		//making sure theyre both at 0
		TE.addX(TE.ATK, 20);
		TE.addX(TE.HP, 30);
		TE.level = "Level 3 Armored Ogre";
		TE.trait = "Armored";
		TE.lootlevel = 3;
		break;
	case 4:
		TE.minusX(TE.ATK, 40);
		TE.minusX(TE.HP, 40);
		//making sure theyre both at 0
		TE.addX(TE.ATK, 25);
		TE.addX(TE.HP, 20);
		TE.level = "Level 4 Demon";
		TE.trait = "Undead";
		TE.lootlevel = 10;
		break;
	case 5:
		TE.minusX(TE.ATK, 40);
		TE.minusX(TE.HP, 40);
		//making sure theyre both at 0
		TE.addX(TE.ATK, 20);
		TE.addX(TE.HP, 25);
		TE.level = "Level 5 Flying Beast";
		TE.trait = "Flying";
		TE.lootlevel = 10;
		break;
	case 6:
		TE.minusX(TE.ATK, 40);
		TE.minusX(TE.HP, 40);
		//making sure theyre both at 0
		TE.addX(TE.ATK, 25);
		TE.addX(TE.HP, 40);
		TE.level = "Level 6 Hell-Drake";
		TE.trait = "Undead";
		TE.lootlevel = 9;
		break;
	case 7:
		TE.minusX(TE.ATK, 40);
		TE.minusX(TE.HP, 40);
		//making sure theyre both at 0
		TE.addX(TE.ATK, 4);
		TE.addX(TE.HP, 10);
		TE.level = "Level 2 Gremlin";
		TE.trait = "null";
		TE.lootlevel = 0;
		break;
	case 8:
		TE.minusX(TE.ATK, 40);
		TE.minusX(TE.HP, 40);
		//making sure theyre both at 0
		TE.addX(TE.ATK, 15);
		TE.addX(TE.HP, 30);
		TE.level = "Level 3 Human Bandit";
		TE.trait = "Poison";
		TE.lootlevel = 6;
		break;
	case 9:
		TE.minusX(TE.ATK, 40);
		TE.minusX(TE.HP, 40);
		//making sure theyre both at 0
		TE.addX(TE.ATK, 18);
		TE.addX(TE.HP, 30);
		TE.level = "Level 2 Forest Spirit";
		TE.trait = "Magical";
		TE.lootlevel = 4;
		break;
	case 10:
		TE.minusX(TE.ATK, 40);
		TE.minusX(TE.HP, 40);
		//making sure theyre both at 0
		TE.addX(TE.ATK, 30);
		TE.addX(TE.HP, 20);
		TE.level = "Level 3 Beastman";
		TE.trait = "null";
		TE.lootlevel = 5;
		break;
	case 11:
		TE.minusX(TE.ATK, 40);
		TE.minusX(TE.HP, 40);
		//making sure theyre both at 0
		TE.addX(TE.ATK, 20);
		TE.addX(TE.HP, 30);
		TE.level = "Level 5 Great Falcon";
		TE.trait = "Flying";
		TE.lootlevel = 7;
		break;
	case 12:
		TE.minusX(TE.ATK, 40);
		TE.minusX(TE.HP, 40);
		//making sure theyre both at 0
		TE.addX(TE.ATK, 20);
		TE.addX(TE.HP, 40);
		TE.level = "Level 7 Great Corpse";
		TE.trait = "Undead";
		TE.lootlevel = 8;
		break;

	}

}

void standinhero()
{
	varias.HP = 0;
	varias.ATK = 0;
	varias.MAG = 0;
	varias.DEF = 0;
	varias.name = "Varias";
	varias.sword = "The King's Sword";
	varias.ShieldHp = 10;
	varias.empowered = 0;
	varias.GP = 0;
	varias.kills = 0;
	varias.lore = 0;
	varias.inventory[0] = 1;
	varias.inventory[1] = 1;
	varias.inventory[2] = 2;
	varias.inventory[3] = 2;
	varias.inventory[4] = 6;
	varias.inventory[5] = 0;
	varias.inventory[6] = 0;
	varias.inventory[7] = 0;
	varias.inventory[8] = 0;
	varias.inventory[9] = 0;
	varias.inventory[10] = 0;
	varias.inventory[11] = 0;
	varias.inventory[12] = 0;
	varias.inventory[13] = 0;
	varias.inventory[14] = 0;
	varias.spellbook[0] = 0;
	varias.spellbook[1] = 1;
	varias.spellbook[2] = 10;
	varias.spellbook[3] = 10;
	varias.spellbook[4] = 10;
	varias.spellbook[5] = 10;
	varias.spellbook[6] = 10;
	varias.spellbook[7] = 10;
	varias.points = 25;
}

void heroMaker()
{
	cout << "First, please allocate your hero's abilities." << endl;
	while (specification <= 5)
	{
		specification++;
		cout << "You have " << varias.points << " EXP points left to allocate!" << endl;
		switch (specification)
		{
		case 1:
			cout << "How many ATK points does your hero have?" << endl;
			cin >> varias.ATK;
			varias.points -= varias.ATK;
			break;
		case 2:
			cout << "How many DEF points does your hero have?" << endl;
			cin >> varias.DEF;
			varias.points -= varias.DEF;
			break;
		case 3:
			cout << "How much HP does your hero have? 1 HP will be 10 Hit Points." << endl;
			cin >> varias.HP;
			varias.points -= varias.HP;
			varias.HitPoints = (varias.HP * 10);
			break;
		case 4:
			cout << "How many MAG points does your hero have? 1 MAG will create 5 Mana" << endl;
			cin >> varias.MAG;
			varias.points -= varias.MAG;
			varias.MP = (varias.MAG * 5);
			break;
		case 5:
			cout << "Congratulations! Your hero has " << varias.ATK << " attack, " << varias.HitPoints << " Hit Points, " << varias.DEF << " Defense, and " << varias.MP << " MP!" << endl;
			lineBreak(1);
			cout << "Is this okay? Enter 0 for no, or any other number for yes.";
			cin >> choice;
			if (choice == 0)
			{
				specification = 0;
				varias.points = 25;
			}
			break;
		case 6:
			cout << "Finally, please name your trusty sword!" << endl;
			cin >> varias.sword;
			cout << varias.name << " and " << varias.sword << " will now depart on their quest!" << endl;
			lineBreak(2);
			break;
		}
		if (varias.points < 0)
		{
			cout << "You do not have enough EXP points. Please start again." << endl;
			specification = 0;
			varias.points = 25;
		}
		lineBreak(1);
	}
}

void collect()
{
	for (int a = 0; a < 5; a++)
	{
		for (int i = 0; i < 5; i++)
		{
			switch (levelonechar[a][i])
			{
			case 'O':
				varias.mapperc++;
				break;
			case 'N':
				varias.mapperc++;
				break;
			case 'C':
				varias.mapperc++;
				break;
			case 'X':
				break;
			}
		}
	}
	for (int a = 0; a < 6; a++)
	{
		for (int i = 0; i < 6; i++)
		{
			switch (leveltwochar[a][i])
			{
			case 'O':
				varias.mapperc++;
				break;
			case 'N':
				varias.mapperc++;
				break;
			case 'C':
				varias.mapperc++;
				break;
			case 'X':
				break;
			}
		}
	}
	for (int a = 7; a < 5; a++)
	{
		for (int i = 7; i < 5; i++)
		{
			switch (levelthreechar[a][i])
			{
			case 'O':
				varias.mapperc++;
				break;
			case 'N':
				varias.mapperc++;
				break;
			case 'C':
				varias.mapperc++;
				break;
			case 'X':
				break;
			}
		}
	}
	cout << "Kills: " << varias.kills << endl << "Gold: " << varias.GP << endl << "Lore: " << varias.lore << endl << "Map Percentage: " << varias.mapperc << "/110" << endl;
}

//SYSTEM FUNCTIONS

void gameover()
{
	cout << "You have been defeated!" << endl;
	Sleep(1000);
	cout << "You slump to the floor, and blackout." << endl;
	Sleep(1000);
	cout << "YOU DIED" << endl;
	collect();
	cin >> choice;
	lineBreak(10);
	main();
}

void fightstarter(int level)
{
	EnemyCreator(level);
	choice = 0;
	cout << "You encounter a " << TE.level << "!" << endl;
	fightloop();
}

void levelup()
{
	varias.addX(varias.HitPoints, 5);
	varias.addX(varias.MP, 5);
	varias.addX(varias.MAG, 1);
	varias.addX(varias.ATK, 1);
	varias.addX(varias.DEF, 1);
}

void bossmaker()
{
	TE.ATK = varias.ATK * 2;
	TE.DEF = varias.DEF / 2;
	TE.HP = varias.HP * 10;
	TE.level = "Level 10 Jarl";
	TE.MP = varias.MAG * 5;
	TE.MAG = varias.MAG;

	cout << "You encounter Ser Jarl." << endl;
}

void mapone() 
{
	cout << "You take a look at your map." << endl;
	lineBreak(1);
	levelonechar[varias.Y][varias.X] = 'O';
	for (int i = 0; i <= 4; i++)
	{
		cout << levelonechar[i][0] << levelonechar[i][1] << levelonechar[i][2] << levelonechar[i][3] << levelonechar[i][4] << endl;
	}
	levelonechar[varias.Y][varias.X] = 'X';
}

void maptwo()
{
	cout << "You take a look at your map." << endl;
	lineBreak(1);
	leveltwochar[varias.Y][varias.X] = 'O';
	for (int i = 0; i <= 5; i++)
	{
		cout << leveltwochar[i][0] << leveltwochar[i][1] << leveltwochar[i][2] << leveltwochar[i][3] << leveltwochar[i][4] << leveltwochar[i][5] << endl;
	}
	leveltwochar[varias.Y][varias.X] = 'X';
}

void mapthree()
{
	cout << "You take a look at your map." << endl;
	lineBreak(1);
	levelthreechar[varias.Y][varias.X] = 'O';
	for (int i = 0; i <= 6; i++)
	{
		cout << levelthreechar[i][0] << levelthreechar[i][1] << levelthreechar[i][2] << levelthreechar[i][3] << levelthreechar[i][4] << levelthreechar[i][5] << levelthreechar[i][6] << endl;
	}
	levelthreechar[varias.Y][varias.X] = 'X';
}

//COMBAT FUNCTIONS

void Attack()
{
	cout << "You swing your " << varias.sword << " at the enemy..." << endl;
	if (varias.empowered > 0) //IF IT'S STRONG, IGNORE TRAITS
	{
		lineBreak(1);
		cout << "You hit the enemy, and your empowered sword deals extra damage!" << endl;
		cout << "You deal " << varias.ATK + varias.MAG << " points of damage!" << endl;
		TE.minusX(TE.HP, (varias.ATK + varias.MAG));
		if (TE.trait == "Magical" || TE.trait == "Undead")
		{
			cout << "The spell does extra damage against the spectral enemy!" << endl;
			TE.minusX(TE.HP, 15);
		}
	}
	else //FOR TRAITS
	{
		lineBreak(1);
		if (TE.trait == "Armored")
		{
			cout << "Your sword bounces off the enemy's armor! Find a way to shatter it!" << endl;
			Sleep(500);
			cout << "You deal " << varias.ATK / 2 << " points of damage!" << endl;
			TE.minusX(TE.HP, (varias.ATK / 2));
		}
		else if (TE.trait == "Undead")
		{
			cout << "The enemy's undead body repels your blade, and you receive some damage!" << endl;
			Sleep(500);
			cout << "You deal " << varias.ATK / 2 << " points of damage!" << endl;
			TE.minusX(TE.HP, (varias.ATK / 2));
			varias.minusX(varias.HitPoints, 5);
		}
		else if (TE.trait == "Flying")
		{
			cout << "The enemy is flying! It swoops down and shreds your defenses!" << endl;
			Sleep(500);
			varias.minusX(varias.DEF, 2);
			cout << "You deal " << varias.ATK << " points of damage!" << endl;
			TE.minusX(TE.HP, varias.ATK);
		}
		else
		{
			cout << "You hit the enemy!" << endl;
			Sleep(500);
			cout << "You deal " << (varias.ATK - TE.DEF) << " points of damage!" << endl;
			TE.minusX(TE.HP, (varias.ATK - TE.DEF));
		}
	}
	switch (varias.modifier)
	{
	case 0:
		break;
	case 1:
		cout << varias.sword << " deals extra damage!" << endl;
		TE.minusX(TE.HP, 10);
		break;
	case 2:
		cout << varias.sword << " inflicts poison on the enemy!" << endl;
		TE.poison = true;
		TE.poisonpower++;
		break;
	case 3:
		cout << varias.sword << " performs a follow-up blast!" << endl;
		TE.minusX(TE.HP, varias.MAG);
		break;
	case 4:
		cout << varias.sword << " Jarl struggles to fight against his own blade. His defenses slip!" << endl;
		TE.DEF--;
		break;
	case 5:
		aichoice = rand() % 4 + 1;
		switch (aichoice)
		{
		case 1:
			cout << varias.sword << " deals massive critical damage!" << endl;
			TE.minusX(TE.HP, varias.ATK);
			break;
		case 2:
			cout << varias.sword << " fails to cut the enemy!" << endl;
			break;
		case 3:
			cout << varias.sword << " fails to cut the enemy!" << endl;
			break;
		case 4:
			cout << varias.sword << " fails to cut the enemy!" << endl;
			break;
		}
		break;
	}
}

void Magic()
{
	//spellbook 1 = fire blast
	//spellbook 2 = ice storm
	//spellbook 3 = leaf blade
	//spellbook 4 = death strike
	//spellbook 5 = obliterate
	//spellbook 6 = golden fist
	//7 = light
	spellchoice = 0;
	lineBreak(1);
	cout << "You have " <<varias.MP << " MP." << endl;
	cout << "So far, you have learnt these spells:" << endl;
	lineBreak(1);
	for (int i = 0; i < 8; i++)
	{
		switch (varias.spellbook[i])
		{
		case 0:
			cout << "0 - Heal" << endl;
			break;
		case 1:
			cout << "1 - Fire blast(3 MP, 10 dmg)" << endl;
			break;
		case 2:
			cout << "2 - Ice Storm (4 MP, 5 dmg - freezes the enemy)" << endl;
			break;
		case 3:
			cout << "3 - Leaf Blade (5 MP - empowers your sword for a few turns)" << endl;
			break;
		case 4:
			cout << "4 - Death Strike (5 MP, 10 dmg - poisons the enemy)" << endl;
			break;
		case 5:
			cout << "5 - Obliterate (All remaining MP, 20+ dmg)" << endl;
			break;
		case 6:
			cout << "6 - Golden Fist (10 MP, (ATK+MAG) dmg - stuns the enemy)" << endl;
			break;
		case 7:
			cout << "7 - Light (5 MP/turn, 10 dmg/turn - activate/deactivate)" << endl;
			break;
		}
	}
	cout << "What will you use?" << endl;
	cin >> spellchoice;
	cout << "You try to cast the spell..." << endl;
	Sleep(2000);
	switch (spellchoice)
	{
	case 0:
		cout << "How much MP would you like to use to heal yourself?" << endl;
		cout << "1 MP will heal " << varias.MAG << " points of HP, up to 20 at once." << endl;
		cout << "You have " << varias.HitPoints << " points of HP" << endl;
		cin >> choice;
		if (choice <= varias.MP) //if they choose an okay amount of MP
		{
			if ((choice * varias.MAG) < 20)//if they less than 20
			{
				cout << "You are healed for " << (choice * varias.MAG) << " HP!" << endl;
				varias.addX(varias.HitPoints, (choice * varias.MAG));
				if (varias.poison == true)
				{
					cout << "Your poison also clears up!" << endl;
					varias.poison = false;
				}
				varias.minusX(varias.MP, choice);
			}
			else if((choice*varias.MAG) >= 20) //otherwise if they heal more than 20
			{
				cout << "You are healed for 20 HP!" << endl;
				varias.addX(varias.HitPoints, (20));
				if (varias.poison == true)
				{
					cout << "Your poison also clears up!" << endl;
					varias.poison = false;
				}
				varias.minusX(varias.MP, choice);
			}
		}
		else if (choice > varias.MP)//if they use too much mp
		{
			cout << "You overcharge your heal, and it cripples your strength!" << endl;
			varias.minusX(varias.HitPoints, choice);
		}
		break;
	case 1:
		if (varias.MP < 3)
		{
			cout << "The spell backfires!" << endl;
			varias.minusX(varias.HitPoints, 5);
			varias.minusX(varias.MP, 3);
		}
		else if(varias.MP > 3)
		{
			cout << "You cast Fire Blast!" << endl;
			TE.minusX(TE.HP, (10 + varias.MAG));
			varias.minusX(varias.MP, 3);
			if (TE.trait == "Magical")
			{
				cout << "The spell does extra damage against the spectral enemy!" << endl;
				TE.minusX(TE.HP, 15);
			}
		}
		break;
	case 2:
		if (varias.MP < 4 || (varias.spellbook[2] == 10))
		{
			cout << "The spell backfires!" << endl;
			varias.minusX(varias.HitPoints, 5);
			varias.minusX(varias.MP, 4);
		}
		else
		{
			cout << "You cast Ice Storm!" << endl;
			TE.minusX(TE.HP, (5 + varias.MAG));
			TE.freeze = true;
			varias.minusX(varias.MP, 4);
			if (TE.trait == "Magical")
			{
				cout << "The spell does extra damage against the spectral enemy!" << endl;
				TE.minusX(TE.HP, 15);
			}
			else if (TE.trait == "Flying")
			{
				TE.minusX(TE.HP, 20);
				cout << "The cold cripples the enemy's wings, and it drops to the floor!" << endl;
				TE.trait = "null";
			}
		}
		break;
	case 3:
		if (varias.MP < 5 || (varias.spellbook[3] == 10))
		{
			cout << "The spell backfires!" << endl;
			varias.minusX(varias.HitPoints, 5);
			varias.minusX(varias.MP, 5);
		}
		else
		{
			cout << "You cast Leaf Blade!" << endl;
			Sleep(500);
			cout << varias.sword << " lights up a bright green!" << endl;
			varias.empowered = 5;
			varias.minusX(varias.MP, 5);
		}
		break;
	case 4:
		if (varias.MP < 5 || (varias.spellbook[4] == 10))
		{
			cout << "The spell backfires!" << endl;
			varias.minusX(varias.HitPoints, 10);
			varias.poison = true;
			varias.minusX(varias.MP, 5);
		}
		else
		{
			cout << "You cast Death Strike!" << endl;
			TE.minusX(TE.HP, (10 + varias.MAG));
			TE.poison = true;
			varias.minusX(varias.MP, 5);
			if (TE.trait == "Magical")
			{
				cout << "The spell does extra damage against the spectral enemy!" << endl;
				TE.minusX(TE.HP, 15);
			}
		}
		break;
	case 5:
		if (varias.MP < 1 || (varias.spellbook[5] == 10))
		{
			cout << "The spell backfires!" << endl;
			varias.minusX(varias.HitPoints, 500);
		}
		else
		{
			cout << "You cast Obliterate!" << endl;
			TE.minusX(TE.HP, (20 + varias.MP + varias.MAG));
			varias.MP = 0;
			if (TE.trait == "Magical")
			{
				cout << "The spell does extra damage against the spectral enemy!" << endl;
				TE.minusX(TE.HP, 15);
			}
		}
		break;
	case 6:
		if (varias.MP < 10 || (varias.spellbook[6] == 10))
		{
			cout << "The spell backfires!" << endl;
			varias.minusX(varias.HitPoints, 500);
		}
		else
		{
			cout << "You cast Golden Fist!" << endl;
			TE.minusX(TE.HP, (10 + varias.MAG + varias.ATK));
			varias.minusX(varias.MP, 10);
			if (TE.trait == "Magical")
			{
				cout << "The spell does extra damage against the spectral enemy!" << endl;
				TE.minusX(TE.HP, 15);
			}
			lineBreak(1);
			cout << "The enemy is stunned!" << endl;
			TE.stun = true;
		}
		break;
	case 7:
		if (varias.MP < 5 || (varias.spellbook[7] == 10))
		{
			cout << "The spell backfires!" << endl;
			varias.minusX(varias.HitPoints, 10);
		}
		else
		{
			if (varias.light == true)
			{
				cout << "You deactivate Light!" << endl;
				varias.light = false;
			}
			else
			{
				cout << "You cast Light!" << endl;
				varias.light = true;
			}
		}
		break;

	}
	lineBreak(1);
}

void Item()
{
	itemchoice = 0;
	lineBreak(1);
	cout << "Rummaging through your inventory, you find" << endl;
	//1 = health potion
	//2 = mana potion
	//3 = throwing knife (far away enemies)
	//4 = cross (for undead)
	//5 = hammer (armored enemies)
	//6 = magic scroll
	//7 = shield
	//8 = glass blade
	//9 = beastman horn
	//10 = large HP
	lineBreak(1);
	for (int i = 0; i < 15; i++)
	{
		switch (varias.inventory[i])
		{
		case 0:
			break;
		case 1:
			cout << i << "- A health potion (Heals a sixth of your HP, and cures poison)" << endl;
			break;
		case 2:
			cout << i << "- A mana potion (Replenishes 5 Mana)" << endl;
			break;
		case 3:
			cout << i << "- A throwing knife (Hits far away enemies)" << endl;
			break;
		case 4:
			cout << i << "- A cross (Useful against undead and demons)" << endl;
			break;
		case 5:
			cout << i << "- A hammer (For breaking armor)" << endl;
			break;
		case 6:
			cout << i << "- Your magic scroll (You have no idea what it does)" << endl;
			break;
		case 7:
			cout << i << "- A sturdy shield (Blocks damage, and gives you a chance to use an HP poiton)" << endl;
			break;
		case 8:
			cout << i << "- A fragile glass blade (Allows you to attack twice)" << endl;
			break;
		case 9:
			cout << i << "- A beastman horn! (Allows for a small follow-up attack)" << endl;
			break;
		case 10:
			cout << i << "- A ManaLife potion! (Heals half your missing HP and 20 mana, and cures poison)" << endl;
			break;
		case 11:
			cout << i << "- A poison bomb! (Applies a large poison)" << endl;
			break;
		}
	}
	Sleep(1000);
	cout << "What will you use?" << endl;
	cin >> itemchoice;
	switch (varias.inventory[itemchoice])
	{
	case 0:
		break;
	case 1:
		Sleep(500);
		cout << "you swig your health potion, and feel better!" << endl;
		varias.addX(varias.HitPoints, ((varias.HP*10) / 6));
		varias.poison = false;
		cout << "The item has been used up!" << endl;
		Sleep(1000);
		varias.inventory[itemchoice] = 0;
		break;
	case 2:
		Sleep(500);
		cout << "You take your mana potion" << endl << "It tastes awful, but you can feel your strength returning!" << endl;
		varias.addX(varias.MP, 5);
		cout << "The item has been used up!" << endl;
		Sleep(1000);
		varias.inventory[itemchoice] = 0;
		break;
	case 3:
		cout << "You lob your throwing knife at the enemy!" << endl;
		Sleep(500);
		TE.minusX(TE.HP, (varias.ATK + 5));
		if (TE.trait == "Flying")
		{
			TE.minusX(TE.HP, 5);
			cout << "Hitting their wings, they drop to the floor!" << endl;
		}
		cout << "The item has been used up!" << endl;
		Sleep(1000);
		varias.inventory[itemchoice] = 0;
		break;
	case 4:
		cout << "You bear your cross against the enemy!" << endl;
		Sleep(500);
		if (TE.trait == "Undead" || "Demon")
		{
			cout << "The enemy recoils in pain!" << endl;
			TE.minusX(TE.HP, 20);
			cout << "The item has been used up!" << endl;
			Sleep(1000);
			varias.inventory[itemchoice] = 0;
		}
		else
		{
			cout << "It has no effect!" << endl;
		}
		break;
	case 5:
		cout << "You brutally bring your hammer to bear on the enemy!" << endl;
		Sleep(500);
		if (TE.trait == "Armored")
		{
			cout << "The enemy's armor shatters!" << endl;
			TE.trait == "null";
			TE.minusX(TE.HP, (TE.HP / 4));
			Sleep(1000);
			cout << "The item has been used up!" << endl;
			varias.inventory[itemchoice] = 0;
		}
		TE.minusX(TE.HP, varias.ATK);
		break;
	case 6:
		cout << "Desperately, you read your ancient magic scroll!" << endl;
		Sleep(2000);
		cout << "The world begins to shake around you!" << endl;
		TE.minusX(TE.HP, ((TE.HP / 2) + varias.MAG + varias.ATK));
		Sleep(1000);
		cout << "The enemy is wounded dearly!" << endl;
		lineBreak(1);
		cout << "The item has been used up!" << endl;
		Sleep(1000);
		varias.inventory[itemchoice] = 0;
		break;
	case 7:
		if (varias.block != true)
		{
			cout << "You grab your shield, bringing it up. You're sure you won't take any damage from physical attacks." << endl;
			Sleep(1000);
			varias.block = true;
			for (int i = 0; i <= 15; i++)
			{
				if (varias.inventory[i] == 1)
				{
					varias.inventory[i] = 0;
					i = 16;
					cout << "You take the opportunity to also swig a health potion, and feel better!" << endl;
					varias.addX(varias.HitPoints, ((varias.HP*10) / 6));
				}
			}
			varias.inventory[itemchoice] = 0;
		}
		break;
	case 8:
		lineBreak(1);
		cout << "You equip your glass blade, and swing it at the enemy!" << endl;
		TE.minusX(TE.HP, (varias.ATK + 10));
		Sleep(500);
		cout << "After dealing amazing damage, it shatters! You follow up with " << varias.sword << "!" << endl;
		Attack();
		varias.inventory[itemchoice] = 0;
		break;
	case 9:
		lineBreak(1);
		cout << "You stab the horn into the enemy's body, wounding them!" << endl;
		TE.minusX(TE.HP, (varias.ATK + 5));
		varias.inventory[itemchoice] = 0;
		cout << "The horn is stuck into the enemy; you then attack!" << endl;
		Attack();
		break;
	case 10:
		lineBreak(1);
		cout << "It takes a while to drink, but you feel a great deal better! Your wounds close." << endl;
		varias.addX(varias.HitPoints, (((varias.HP*10) - varias.HitPoints) / 2));
		varias.addX(varias.MP, 20);
		varias.poison = false;
		varias.inventory[itemchoice] = 0;
		Sleep(1000);
		cout << "You toss the bottle aside." << endl;
		break;
	case 11:
		lineBreak(1);
		cout << "You lob the poison bomb!" << endl;
		Sleep(1000);
		cout << "It hits and poisons its target!" << endl;
		varias.inventory[itemchoice] = 0;
		TE.poison = true;
		TE.poisonpower = 3;
		break;
	}

}

//EXTRA FUNCTIONS

void swordchoice()
{
	lineBreak(1);
	sectionRead(1, 32, 36);
	cout << "Which sword would you like to take?" << endl;
	for (int i = 0; i < 15; i++)
	{
		switch (i)
		{
		case 1:
			cout << "A fresh Iron Sword, a replica of your own, almost. (+10 ATK)" << endl;
			break;
		case 2:
			cout << "A poison laced rapier. (+1 poison every attack)" << endl;
			break;
		case 3:
			cout << "The Bolt of Frustrum; a rare blade thought lost for years. (MAG-based follow-up attack)" << endl;
			break;
		case 4:
			cout << "Jarl's sword. You wonder how he lost it - he might want it back." << endl;
			break;
		case 5:
			cout << "A jagged saw-blade that you recognise from the Beastmen tribes of the South. (Crit chance(double DMG))" << endl;
			break;
		}
		Sleep(1000);
	}
	cin >> choice;
	varias.swordchoice = choice;
	cout << "Are you sure you would like to take this sword?" << endl << "1. Yes" << endl << "0. No" << endl;
	cin >> choice;
	if (choice == 1)
	{
		switch (varias.swordchoice)
		{
		case 1:
			varias.sword = "Iron Sword";
			break;
		case 2:
			varias.sword = "Poison Rapier";
			break;
		case 3:
			varias.sword = "Bolt of Frustrum";
			break;
		case 4:
			varias.sword = "Jarl's Sword";
			break;
		case 5:
			varias.sword = "Beastman Saw-Blade";
			break;
		}
		varias.modifier = varias.swordchoice;
	}

}

void treasure(int treasure)
{
	switch (treasure)
	{
	case 1:
		cout << "Someone must have lost a health potion! You pick it up." << endl;
		for (int i = 0; i <= 15; i++)
		{
			if (varias.inventory[i] == 0)
			{
				varias.inventory[i] = 1;
				i = 16;
			}
		}
		break;
	case 2:
		cout << "Taking in your surroundings, you feel inspired, and level up!" << endl;
		levelup();
		break;
	case 3:
		switch (varias.armorset)
		{
		case 0:
			cout << "You find a set of well made vambraces! Checking them over, you snap them on, and are convinced of their sturdiness." << endl;
			break;
		case 1:
			cout << "You discover a pair of greaves, lost in the mud. Someone must have tossed them aside to move quicker." << endl << "Your own pair is wearing out, and these look a great deal more comfortable. You figure nobody would miss them." << endl;
			break;
		case 2:
			cout << "You find an old gauntlet, hidden away. You recognise the craftsmanship, though; this was made by the magi-tailor Arvess." << endl << "One of many replicas - not the finished product - but strong nonetheless." << endl;
			lineBreak(1);
			cout << "You switch your own gloves out for it, and feel some great magic power flow through you." << endl;
			lineBreak(1);
			cout << "You have learnt [GOLDEN FIST]!" << endl;
			varias.spellbook[6] = 6;
		case 3:
			cout << "You find a new sheathe for your sword. In fact, it fits perfectly." << endl << "So much so that you toss your old, battered sheathe aside." << endl;
			break;
		}
		varias.addX(varias.DEF, 5);
		lineBreak(1);
		cout << "Your DEF has raised!" << endl;
		varias.armorset++;
		break;
	case 4:
		cout << "You find a rare foregin glassblade! You add it to your inventory" << endl;
		//LORE
		for (int i = 0; i <= 15; i++)
		{
			if (varias.inventory[i] == 0)
			{
				varias.inventory[i] = 8;
				i = 16;
			}
		}
		break;
	}
}

void trap(int trap)
{
	switch (trap)
	{
	case 1:
		cout << "A gremlin sneaks into your backpack and steals a few things!" << endl;
		varias.minusX(varias.GP, 5);
		varias.minusX(varias.HitPoints, 4);
		for (int i = 0; i <= 15; i++)
		{
			if (varias.inventory[i] == 1)
			{
				varias.inventory[i] = 0;
				i = 16;
			}
		}
		break;
	case 2:
		cout << "A swarm of bats attack you!" << endl;
		lineBreak(1);
		cout << "You fight back, but begin to lose your way!" << endl;
		if (varias.ATK > 10)
		{
			lineBreak(1);
			cout << "You manage to fight off the bats before becoming too lost!" << endl;
		}
		else
		{
			lineBreak(1);
			cout << "You struggle about, searching for some light!" << endl;
			lineBreak(1);
			if (cave1 == true)
			{
				cout << "You find yourself at the opening to the cave..." << endl;
				varias.X = 2;
				varias.Y = 0;
			}
			else if (cave2 == true)
			{
				cout << "You wind up back at the start of the path through the forest." << endl;
				varias.X = 0;
				varias.Y = 0;
			}
			else if (cave3 == true)
			{
				cout << "The scenery opens up around you, and you realise you've wandered back out onto the mountainside." << endl;
				varias.X = 0;
				varias.Y = 6;
			}
		}
		break;
	case 3:
		cout << "You fall into a pit of goo, and your sword grows dull as it corrodes it!" << endl;
		varias.minusX(varias.HitPoints, 5);
		varias.minusX(varias.ATK, 3);
		break;
	case 4:
		cout << "An earthquake goes off in the cave, and the stalactites above you begin to fall!" << endl;
		if (varias.DEF > 8)
		{
			lineBreak(1);
			cout << "Your armor saves you from the worst of it, but you are seriously exhausted." << endl;
			varias.minusX(varias.HitPoints, 10);
		}
		else
		{
			lineBreak(1);
			cout << "Your armor isn't strong enough to hold out, and you're battered by the spikes!" << endl;
			varias.minusX(varias.HitPoints, 20);
		}
		break;
	case 5:
		cout << "A vine swings out and almost lashes you across the face!" << endl;		
		Sleep(1000);
		lineBreak(1);
		if (varias.MP > 10)
		{
			cout << "You blast it to ashes with a burst of magical fire!" << endl;
			varias.MP--;
		}
		else
		{
			cout << "With no way to quickly react, it smacks you, and you feel your vision swim." << endl;
			varias.poison = true;
			varias.minusX(varias.HitPoints, (5));
			cout << "You have been poisoned!" << endl;
		}
		break;
	case 6:
		cout << "You see a ancient rune ahead of you, plastered to a blank wall. What do you do?" << endl << "1. Use your limited magical knowledge to unlock it." << endl << "2. Do nothing." << endl;
		cin >> choice;
		if (choice == 1)
		{
			lineBreak(1);
			cout << "You hold your hand aloft, and attempt to decypher the rune." << endl;
			lineBreak(1);
			if (varias.MAG > 10)
			{
				cout << "You succeed! The walls melts away like it was nothing, and you are rewarded with a ManaLife potion, and level up!" << endl;
				cout << "You also take the time to sort out your inventory." << endl;
				drop();
				for (int i = 0; i <= 15; i++)
				{
					if (varias.inventory[i] == 0)
					{
						varias.inventory[i] = 9;
						i = 16;
					}
				}
				levelup();
			}
			else
			{
				cout << "The rune blasts you back!" << endl;
				varias.minusX(varias.HitPoints, (varias.HP / 4));
			}
		}
		else
		{
			cout << "You decide the rune is best left alone, and hurry on." << endl;
		}
		break;
	case 7:
		cout << "Inside one of the ruin's halls, you find an old corpse." << endl;
		lineBreak(1);
		cout << "It shuffles to life, and you wonder if you should fight it or not." << endl << "1. fight the corpse." << endl << "2. retreat" << endl;
		cin >> choice;
		if (choice == 1)
		{
			fightstarter(12);
		}
		else
		{
			cout << "It's a pity, but you leave the corpse to shamble through the ruins alone." << endl;
		}
		break;
	}
}

void secret(int secret)
{
	switch (secret)
	{
	case 1:
		sectionRead(0, 41, 48);
		varias.lore++;
		break;
	case  2:
		sectionRead(0, 50, 52);
		varias.lore++;
		break;
	case 3:
		sectionRead(0, 54, 59);
		varias.lore++;
		break;
	case 4:
		sectionRead(0, 89, 94);
		varias.lore++;
		break;
	case 5:
		sectionRead(0, 96, 100);
		varias.lore++;
		break;
	case 6:
		sectionRead(0, 102, 106);
		varias.lore++;
		break;
	case 7:
		sectionRead(0, 108, 111);
		varias.lore++;
		break;
	case 8: //LESS IMPORTANT
		sectionRead(1, 9, 13);
		varias.lore++;
		break;
	case 9: //ALSO IMPORTANT
		sectionRead(1, 15, 19);
		varias.lore++;
		break;
	case 10: //BOSS PREP
		sectionRead(1, 28, 30);
		varias.lore++;
		break;
	case 11: //IMPORTANT ONE
		sectionRead(1, 21, 26);
		varias.lore++;
		break;
	}
}

void block()
{
	lineBreak(1);
	cout << "There doesn't seem to be any way ahead." << endl << "You can't go this way." << endl;
	Sleep(1000);
	cout << "You turn around and go back the way you came." << endl;

	if (cave1 == true)
	{
		levelonechar[varias.Y][varias.X] = 'N';
	}
	else if (cave2 == true)
	{
		leveltwochar[varias.Y][varias.X] = 'N';
	}
	else if (cave3 == true)
	{
		levelthreechar[varias.Y][varias.X] = 'N';
	}	
	varias.X = varias.PX;
	varias.Y = varias.PY;
}

string loot()
{
	switch (TE.lootlevel)
	{
	case 0:
		return " one gold ";
		varias.addX(varias.GP, 1);
		break;
	case 1:
		varias.addX(varias.GP, 10);
		for (int i = 0; i <= 15; i++)
		{
			if (varias.inventory[i] == 0)
			{
				varias.inventory[i] = 1;
				i = 16;
			}
		}
		lineBreak(1);
		cout << "You level up!" << endl;
		levelup();
		return " ten gold and a health potion ";
		break;
	case 2:
		varias.addX(varias.GP, 15);
		for (int i = 0; i <= 15; i++)
		{
			if (varias.inventory[i] == 0)
			{
				varias.inventory[i] = 5;
				i = 16;
			}
		}
		lineBreak(1);
		cout << "You level up!" << endl;
		levelup();
		return " fifteen gold and a hammer ";
		break;
	case 3:
		varias.addX(varias.GP, 20);
		for (int i = 0; i <= 15; i++)
		{
			if (varias.inventory[i] == 0)
			{
				varias.inventory[i] = 2;
				i = 16;
			}
		}
		for (int i = 0; i <= 15; i++)
		{
			if (varias.inventory[i] == 0)
			{
				varias.inventory[i] = 7;
				i = 16;
			}
		}
		lineBreak(1);
		cout << "You level up!" << endl;
		levelup();
		return " twenty gold, a mana potion and a sturdy shield ";
		break;
	case 4:
		varias.addX(varias.GP, 10);
		for (int i = 0; i <= 15; i++)
		{
			if (varias.inventory[i] == 0)
			{
				varias.inventory[i] = 1;
				i = 16;
			}
		}
		for (int i = 0; i <= 15; i++)
		{
			if (varias.inventory[i] == 0)
			{
				varias.inventory[i] = 11;
				i = 16;
			}
		}
		lineBreak(1);
		cout << "You level up!" << endl;
		levelup();
		return " ten gold, a poison bomb, and a health potion ";
		break;
	case 5:
		varias.addX(varias.GP, 10);
		for (int i = 0; i <= 15; i++)
		{
			if (varias.inventory[i] == 0)
			{
				varias.inventory[i] = 1;
				i = 16;
			}
		}
		for (int i = 0; i <= 15; i++)
		{
			if (varias.inventory[i] == 0)
			{
				varias.inventory[i] = 9;
				i = 16;
			}
		}
		lineBreak(1);
		cout << "You level up!" << endl;
		levelup();
		return " ten gold, a health potion and a beastman horn ";
		break;
	case 6:
		varias.addX(varias.GP, 20);
		varias.spellbook[2] = 2;
		varias.spellbook[3] = 3;
		lineBreak(1);
		cout << "You level up!" << endl;
		levelup();
		return " twenty gold, and a spellbook containing [ICE STORM] and [LEAF BLADE] ";
		break;
	case 7:
		varias.addX(varias.GP, 20);
		varias.spellbook[4] = 4;
		varias.spellbook[5] = 5;
		for (int i = 0; i <= 15; i++)
		{
			if (varias.inventory[i] == 0)
			{
				varias.inventory[i] = 9;
				i = 16;
			}
		}
		lineBreak(1);
		cout << "You level up!" << endl;
		levelup();
		return " twenty gold, a ManaLife potion, and a spellbook containing [DEATH STRIKE] and [OBLITERATE] ";
		break;
	case 8:
		varias.addX(varias.GP, 50);
		for (int i = 0; i <= 15; i++)
		{
			if (varias.inventory[i] == 0)
			{
				varias.inventory[i] = 4;
				i = 16;
			}
		}
		cout << "You level up!" << endl;
		levelup();
		varias.spellbook[7] = 7;
		return " fifty gold, a golden cross, and a spellbook containing [LIGHT] ";
		break;
	case 9:		
		varias.addX(varias.GP, 10);
		swordchoice();
		//DO THE SWORDS
		return " ten gold ";
		break;
	case 10:

		for (int i = 0; i <= 15; i++)
		{
			if (varias.inventory[i] == 0)
			{
				varias.inventory[i] = 1;
				i = 16;
			}
		}
		for (int i = 0; i <= 15; i++)
		{
			if (varias.inventory[i] == 0)
			{
				varias.inventory[i] = 2;
				i = 16;
			}
		}
		lineBreak(1);
		cout << "You level up!" << endl;
		levelup();
		return " ten gold, a health potion and a mana potion ";
		break;
	}
}

void drop()
{
	lineBreak(1);
	cout << "You can take the time to sort out your inventory." << endl << "Is there anything you would like to drop?" << endl;
	for (int i = 0; i < 15; i++)
	{
		switch (varias.inventory[i])
		{
		case 0:
			break;
		case 1:
			cout << i << "- A health potion (Heals a sixth of your HP, and cures poison)" << endl;
			break;
		case 2:
			cout << i << "- A mana potion (Replenishes 5 Mana)" << endl;
			break;
		case 3:
			cout << i << "- A throwing knife (Hits flying enemies)" << endl;
			break;
		case 4:
			cout << i << "- A cross (Useful against the undead)" << endl;
			break;
		case 5:
			cout << i << "- A hammer (for breaking armor)" << endl;
			break;
		case 6:
			cout << i << "- Your magic scroll; you have no idea what it does..." << endl;
			break;
		case 7:
			cout << i << "- A sturdy shield (Blocks enemy attacks, and gives you the chance to drink an HP potion)" << endl;
			break;
		case 8:
			cout << i << "- A fragile glass blade! Allows you to attack twice!" << endl;
			break;
		case 9:
			cout << i << "- A beastman horn! (Allows for a small follow-up attack)" << endl;
			break;
		}
	}
		lineBreak(1);
		cout << "Type 20 to drop nothing." << endl;
		cin >> choice;
		varias.inventory[choice] = 0;
		lineBreak(1);
		cout << "Would you like to drop anything else? 0 - yes." << endl;
		cin >> choice;
		if (choice == 0)
		{
			drop();
		}
}

//MAIN FUNCTIONS

void bossloop()
{
	lineBreak(1);
	cout << "What will you do?" << endl << "1 - Attack!" << endl << "2 - Magic!" << endl << "3 - item!" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		Attack();
		break;
	case 2:
		Magic();
		break;
	case 3:
		Item();
		break;
	}
	Sleep(1000);

	if (varias.light == true)//USING LIGHT
	{
		lineBreak(1);
		if (varias.MP >= 5)
		{
			cout << "Light deals damage to Jarl!" << endl;
			TE.minusX(TE.HP, 10 + varias.MAG);
			varias.minusX(varias.MP, 5);
			cout << "You have " << varias.MP << " MP left!" << endl;
		}
		else if (varias.MP < 5)
		{
			cout << "You feel a sting as Light deactivates!" << endl;
			varias.minusX(varias.HitPoints, 5);
			varias.light = false;
		}
	}

	if (TE.poison == true)//POISON DMG
	{
		lineBreak(1);
		cout << "Jarl takes damage from poison!" << endl;
		TE.minusX(TE.HP, (5*TE.poisonpower));
	}

	if (TE.HP <= 0) //IF THE ENEMY IS DEAD
	{
		cout << "Jarl collapses. You have won!" << endl;
		lineBreak(1);
		Sleep(500);
		varias.kills++;
	}
	else if (TE.freeze == true) //ELSE IF THE ENEMY IS FROZEN OR STUNNED
	{
		cout << "Jarl is frozen! He can't attack!" << endl;
		TE.freeze = false;
		if (varias.HitPoints <= 0) //ARE YOU DEAD?
		{
			gameover();
		}
		else if (varias.HitPoints > 0)
		{
			cout << "The battle continues, although Jarl looks much weaker." << endl;
			if (varias.poison == true) //POISON DMG
			{
				varias.minusX(varias.HitPoints, 4);
				cout << "You take damage from poison!" << endl;
				if (varias.HitPoints <= 0) //ARE YOU DEAD?
				{
					gameover();
				}
			}
			cout << "You have " << varias.HitPoints << " HP remaining!" << endl;
			if (varias.empowered > 0) //EMPOWERED LOSES STRENGTH
			{
				varias.empowered--;
				cout << varias.sword << " loses some of it's magical power! You have " << varias.empowered << " turns left." << endl;
			}
			bossloop();
		}
	}
	else if (TE.stun == true)
	{
		cout << "Jarl reels from the attack, and fails to strike back!" << endl;
		TE.stun = false;
		if (varias.HitPoints <= 0) //ARE YOU DEAD?
		{
			gameover();
		}
		else if (varias.HitPoints > 0)
		{
			cout << "The battle continues, although Jarl looks much weaker." << endl;
			if (varias.poison == true) //POISON DMG
			{
				varias.minusX(varias.HitPoints, 4);
				cout << "You take damage from poison!" << endl;
				if (varias.HitPoints <= 0) //ARE YOU DEAD?
				{
					gameover();
				}
			}
			cout << "You have " << varias.HitPoints << " HP remaining!" << endl;
			if (varias.empowered > 0) //EMPOWERED LOSES STRENGTH
			{
				varias.empowered--;
				cout << varias.sword << " loses some of it's magical power! You have " << varias.empowered << " turns left." << endl;
			}
			bossloop();
		}
	}
	else if (TE.HP > 0) //IF IT IS ALIVE, IT ATTACKS!
	{
		aichoice = rand() % 2 + 1; //DOES IT ATTACK OR USE MAGIC?
		switch (aichoice)
		{
		case 1:
			if (varias.block == true) //IF YOUR SHIELD IS UP - SHIELD DOESNT BLOCK MAGIC?
			{
				varias.minusX(varias.ShieldHp, TE.ATK);
				if (varias.ShieldHp == 0) //IF IT BREAKS DURING THE ATTACK
				{
					cout << "Your shield shatters, but you have taken no damage!" << endl;
					Sleep(500);
					cout << "The shield is now useless. You toss it aside." << endl;
					varias.block = false;
					varias.ShieldHp = 20;
				}
				else //IF IT DOESNT
				{
					cout << "You successfully block the attack, and your shield looks like it can take a few more hits!" << endl;
				}
			}
			else //ENEMY ATTACK
			{
				cout << "Jarl strikes back with his dagger!" << endl;

				Sleep(500);
				if ((TE.ATK - varias.DEF) >= 0)
				{
					cout << "He deals " << (TE.ATK - varias.DEF) << " Points of damage to you!" << endl;
					varias.minusX(varias.HitPoints, (TE.ATK - varias.DEF));
				}
				else //IF YOU'RE BEEFY ENOUGH, TAKE NO DMG
				{
					cout << "Your armor holds strong, and you take no damage!" << endl;
					Sleep(500);
					cout << "Your armor weakens as it takes the brunt of the attack." << endl;
					varias.minusX(varias.DEF, 1); //STACKING ARMOR DOESNT WORK
				}
			}
			break;
		case 2:
			cout << "Jarl prepares a magical attack!" << endl;
			aichoice = rand() % 5 + 1;
			lineBreak(1);
			switch (aichoice)
			{
			case 1:
				break;
				cout << "Jarl casts Posion Blast!" << endl;
				if (TE.MP > 10)
				{
					cout << "He succeeds, striking you with a hideous attack!" << endl;
					varias.minusX(varias.HitPoints, 10);
					varias.poison = true;
				}
				else if (TE.MP < 10)
				{
					cout << "Jarl attempts to cast the spell, but it backfires!" << endl;
					TE.poison = true;
					TE.poisonpower++;
					TE.minusX(TE.HP, 15);
				}
			case 2:
				cout << "Jarl casts Heat Wave!" << endl;
				if (TE.MP > 10)
				{
					cout << "He succeeds, striking you with a burning blast!" << endl;
					varias.minusX(varias.HitPoints, 15);
				}
				else if (TE.MP < 10)
				{
					cout << "Jarl attempts to cast the spell, but it backfires!" << endl;
					TE.minusX(TE.HP, 20);
				}
				break;
			case 3:
				cout << "Jarl casts Summon!" << endl;
				if (TE.MP > 10)
				{
					cout << "He succeeds, conjuring an awful gremlin infront of you!" << endl;
					varias.minusX(varias.HitPoints, 5);
					Sleep(1000);
					cout << "He stands back, letting his familiar fight for him." << endl;	
					fightstarter(7);
				}
				else if (TE.MP < 10)
				{
					cout << "Jarl attempts to cast the spell, but it backfires!" << endl;
					TE.minusX(TE.HP, 20);
				}
				break;
			case 4:
				cout << "Jarl casts Throw!" << endl;
				if (TE.MP > 20)
				{
					cout << "He succeeds, tossing you against the hard walls!" << endl;
					varias.minusX(varias.HitPoints, 15);
					cout << "Your defenses weaken!" << endl;
					varias.minusX(varias.DEF, 5);
				}
				else if (TE.MP < 20)
				{
					cout << "Jarl attempts to cast the spell, but it backfires!" << endl;
					TE.minusX(TE.HP, 30);
				}
				break;
			case 5:
				cout << "Jarl casts Hate!" << endl;
				if (TE.MP > 20)
				{
					cout << "He succeeds, striking you with all his power!" << endl;
					varias.minusX(varias.HitPoints, 25);
					TE.MP = 0;
				}
				else if (TE.MP < 20)
				{
					cout << "Jarl attempts to cast the spell, but it backfires!" << endl;
					TE.minusX(TE.HP, 50);
					TE.MP = 0;
				}
				break;
			}
			break;
		}
		if (varias.HitPoints <= 0) //ARE YOU DEAD?
		{
			gameover();
		}
		else if (varias.HitPoints > 0)
		{
			cout << "The battle continues, although Jarl looks much weaker." << endl;
			if (varias.poison == true) //POISON DMG
			{
				varias.minusX(varias.HitPoints, 4);
				cout << "You take damage from poison!" << endl;
				if (varias.HitPoints <= 0) //ARE YOU DEAD?
				{
					gameover();
				}
			}
			cout << "You have " << varias.HitPoints << " HP remaining!" << endl;
			if (varias.empowered > 0) //EMPOWERED LOSES STRENGTH
			{
				varias.empowered--;
				cout << varias.sword << " loses some of it's magical power! You have " << varias.empowered << " turns left." << endl;
			}

			if ((TE.HP < 50) && (line[0] == true))
			{
				cout << "Jarl is growing tired. You can see the terrified look on his face; he never wanted to have to fight you." << endl;
				line[0] = false;
				line[1] = true;
			}
			else if ((TE.HP < 40) && (line[1] == true))
			{
				cout << "Jarl barely dodges an attack to lean against the wall, gasping for air. He's an apprentice for a reason." << endl;
				line[1] = false;
				line[2] = true;
			}
			else if ((TE.HP < 20) && (line[2] == true))
			{
				cout << "Jarl spits blood from his mouth, clearing his throat to speak. 'You fight like all the other knights, you know...'" << endl;
				line[2] = false;
				line[3] = true;
			}
			else if ((TE.HP < 50) && (line[3] == true))
			{
				cout << "Jarl has all but given up, on his last legs. 'Try not to feel too bad about this.' It almost sounds like he's surrendering." << endl;
			}
			bossloop();
		}
	}
}

void fightloop()
{
	lineBreak(1);
	cout << "What will you do?" << endl << "1 - Attack!" << endl << "2 - Magic!" << endl << "3 - item!" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		Attack();
		break;
	case 2:
		Magic();
		break;
	case 3:
		Item();
		break;
	}
	Sleep(1000);

	if (varias.light == true)
	{
		lineBreak(1);
		if (varias.MP >= 5)//USING LIGHT
		{
			cout << "Light deals damage to the enemy!" << endl;
			TE.minusX(TE.HP, 10 + varias.MAG);
			varias.minusX(varias.MP, 5);
			cout << "You have " << varias.MP << " MP left!" << endl;
		}
		else if (varias.MP < 5)
		{
			cout << "You feel a sting as Light deactivates!" << endl;
			varias.minusX(varias.HitPoints, 5);
			varias.light = false;
		}
	}

	if (TE.poison == true)
	{
		lineBreak(1);
		cout << "The enemy takes damage from poison!" << endl;
		TE.minusX(TE.HP, (5*TE.poisonpower));
	}

	if(TE.HP <= 0) //IF THE ENEMY IS DEAD
	{
		cout << "The enemy collapses. You have won!" << endl;
		loots = loot();
		lineBreak(1);
		Sleep(500);
		varias.kills++;
		cout << "Your Enemy drops" << loots << endl << "You add it to your inventory." << endl;
	}
	else if (TE.freeze == true) //ELSE IF THE ENEMY IS FROZEN OR STUNNED
	{
		cout << "The enemy is frozen! It can't attack!" << endl;
		TE.freeze = false;
		if (varias.HitPoints <= 0) //ARE YOU DEAD?
		{
			gameover();
		}
		else if (varias.HitPoints > 0)
		{
			cout << "The battle continues, although your enemy is weaker." << endl;
			if (varias.poison == true) //POISON DMG
			{
				varias.minusX(varias.HitPoints, 5);
				cout << "You take damage from poison!" << endl;
				if (varias.HitPoints <= 0) //ARE YOU DEAD?
				{
					gameover();
				}
			}
			cout << "You have " << varias.HitPoints << " HP remaining!" << endl;
			if (varias.empowered > 0) //EMPOWERED LOSES STRENGTH
			{
				varias.empowered--;
				cout << varias.sword << " loses some of it's magical power! You have " << varias.empowered << " turns left." << endl;
			}
			fightloop();
		}
	}
	else if (TE.stun == true)
	{
		cout << "The enemy reels from the attack, and fails to strike back!" << endl;
		TE.stun = false;
		if (varias.HitPoints <= 0) //ARE YOU DEAD?
		{
			gameover();
		}
		else if (varias.HitPoints > 0)
		{
			cout << "The battle continues, although your enemy is weaker." << endl;
			if (varias.poison == true) //POISON DMG
			{
				varias.minusX(varias.HitPoints, 5);
				cout << "You take damage from poison!" << endl;
				if (varias.HitPoints <= 0) //ARE YOU DEAD?
				{
					gameover();
				}
			}
			cout << "You have " << varias.HitPoints << " HP remaining!" << endl;
			if (varias.empowered > 0) //EMPOWERED LOSES STRENGTH
			{
				varias.empowered--;
				cout << varias.sword << " loses some of it's magical power! You have " << varias.empowered << " turns left." << endl;
			}
			fightloop();
		}
	}
	else if (TE.HP > 0) //IF IT IS ALIVE, IT ATTACKS!
	{
		if (varias.block == true) //IF YOU SHIELD IS UP
		{
			varias.minusX(varias.ShieldHp, TE.ATK);
			if (varias.ShieldHp == 0) //IF IT BREAKS DURING THE ATTACK
			{
				cout << "Your shield shatters, but you have taken no damage!" << endl;
				Sleep(500);
				cout << "The shield is now useless. You toss it aside." << endl;
				varias.block = false;
				varias.ShieldHp = 10;
			}
			else //IF IT DOESNT
			{
				cout << "You successfully block the attack, and your shield looks like it can take a few more hits!" << endl;
			}
		}
		else //ENEMY ATTACK
		{
			cout << "The enemy strikes back!" << endl;
			Sleep(500);
			if ((TE.ATK - varias.DEF) >= 0)
			{
				cout << "It deals " << (TE.ATK - varias.DEF) << " Points of damage to you!" << endl;
				varias.minusX(varias.HitPoints, (TE.ATK - varias.DEF));
				if (TE.trait == "Poison" && varias.poison == false)
				{
					cout << "You are poisoned!" << endl;
					varias.poison = true;
				}
			}
			else //IF YOU'RE BEEFY ENOUGH, TAKE NO DMG
			{
				cout << "Your armor holds strong, and you take no damage!" << endl;
				if (TE.trait == "Poison" && varias.poison == false)
				{
					cout << "You are poisoned!" << endl;
					varias.poison = true;
				}
			}
		}
		if (varias.HitPoints <= 0) //ARE YOU DEAD?
		{
			gameover();
		}
		else if (varias.HitPoints > 0)
		{
			cout << "The battle continues, although your enemy is weaker." << endl;
			if (varias.poison == true) //POISON DMG
			{
				varias.minusX(varias.HitPoints, 5);
				cout << "You take damage from poison!" << endl;
			}
			cout << "You have " << varias.HitPoints << " HP remaining!" << endl;
			if (varias.empowered > 0) //EMPOWERED LOSES STRENGTH
			{
				varias.empowered--;
				cout << varias.sword << " loses some of it's magical power! You have " << varias.empowered << " turns left." << endl;
			}
			fightloop();
		}
	}
}

void caveone()
{
	varias.X = 2;
	varias.Y = 0;
	cave1 = true;
	cout << "Entering the cave from the north, the exit on your map is a few hours south." << endl;
	sectionRead(0, 30, 32);
	//DO SOME READING HERE, STORY IS FOR LATER THO
	while (cave1 == true)
	{
		mapone();
		lineBreak(1);
		cout << "The cave goes quiet around you." << endl << "It seems you have a chance to move on..." << endl;
		Sleep(1000);
		cout << "1: Move south" << endl << "2: Move north" << endl << "3: Move west" << endl << "4: Move east" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			varias.Y++;
			break;
		case 2:
			varias.Y--;
		case 3:
			varias.X--;
			break;
		case 4:
			varias.X++;
			break;
		}
		if (varias.X > 4)
		{
			cout << "You've wandered off of your map! You become lost in the cave for a short while!" << endl;
			lineBreak(2);
			Sleep(2000);
			cout << "Whilst walking around in the dark, you encounter an enemy!" << endl;
			fightstarter(7);
			lineBreak(1);
			cout << "After beating your enemy, you return to the path." << endl;
			varias.X = 4;
		}
		if (varias.X < 0)
		{
			cout << "You've wandered off of your map! You become lost in the cave for a short while!" << endl;
			lineBreak(2);
			Sleep(2000);
			cout << "Whilst walking around in the dark, you encounter an enemy!" << endl;
			fightstarter(7);
			lineBreak(1);
			cout << "After beating your enemy, you return to the path." << endl;
			varias.X = 0;
		}
		if (varias.Y < 0)
		{
			cout << "You've wandered off of your map! You become lost in the cave for a short while!" << endl;
			lineBreak(2);
			Sleep(2000);
			cout << "Whilst walking around in the dark, you encounter an enemy!" << endl;
			fightstarter(7);
			lineBreak(1);
			cout << "After beating your enemy, you return to the path." << endl;
			varias.Y = 0;
		}
		if (varias.Y > 4)
		{
			cout << "You've wandered off of your map! You become lost in the cave for a short while!" << endl;
			lineBreak(2);
			Sleep(2000);
			cout << "Whilst walking around in the dark, you encounter an enemy!" << endl;
			fightstarter(7);
			lineBreak(1);
			cout << "After beating your enemy, you return to the path." << endl;
			varias.Y = 4;
		}
		//REMEMBER THAT ARRAYS= 0->4
		//F = FIGHT, T = TREASURE, B = BLANK, S = SECRET, X = EVENT E = ENTRANCE/EXIT
		//01 02 03 04 05 - 0,0 0,1 0,2 0,3 0,4 - T F2 E F1 F2
		//06 07 08 09 10 - 1,0 1,1 1,2 1,3 1,4 - F2 S X F1 X
		//11 12 13 14 15 - 2,0 2,1 2,2 2,3 2,4 - B F1 F2 T S
		//16 17 18 19 20 - 3,0 3,1 3,2 3,3 3,4 - F2 T X F2 B
		//21 22 23 24 25 - 4,0 4,1 4,2 4,3 4,4 - X E F3 S T
		//ENTER AT X = 2 (NUMBER 3)
		//EXIT EITHER AT Y = 5 (20-25) OR 4,1 (22)
		//HAVE THREE OR FOUR 'TREASURE' SPOTS
		//HAVE A FEW BLANKS
		//PLENTY OF FIGHTS
		switch (levelone[varias.Y][varias.X])
		{
		case 1:
			//treasure
			if (levelonebool[0][0] == true)
			{
				treasure(1);
				levelonebool[0][0] = false;
			}
			break;
		case 2:
			//goblin fight
			if (levelonebool[0][1] == true)
			{		
				fightstarter(2);
				levelonebool[0][1] = false;
			}
			break;
		case 3:
			//ENTER
			break;
		case 4:
			//rat fight
			if (levelonebool[0][3] == true)
			{
				fightstarter(1);
				levelonebool[0][3] = false;
			}
			break;
		case 5:
			//goblin fight
			if (levelonebool[0][4] == true)
			{	
				fightstarter(2);
				levelonebool[0][4] = false;
			}

			break;
		case 6:
			//goblin fight
			if (levelonebool[1][0] == true)
			{
				fightstarter(2);
				levelonebool[1][0] = false;
			}
			break;
		case 7:	
			//secret
			if (levelonebool[1][1] == true)
			{
				secret(1);
				levelonebool[1][1] = false;
			}
			break;
		case 8:
			//trap
			if (levelonebool[1][2] == true)
			{
				trap(1);
				levelonebool[1][2] = false;
			}
			break;
		case 9:
			//rat fight
			if (levelonebool[1][3] == true)
			{
				fightstarter(1);
				levelonebool[1][3] = false;
			}
			break;
		case 10:
			//trap
			if (levelonebool[1][4] == true)
			{
				trap(2);
				levelonebool[1][4] = false;
			}
			break;
		case 11:
			//blank
			if (levelonebool[2][0] == true)
			{
				levelonebool[2][0] = false;
			}
			break;
		case 12:
			//rat
			if (levelonebool[2][1] == true)
			{	
				fightstarter(1);
				levelonebool[2][1] = false;
			}
			break;
		case 13:
			//goblin
			if (levelonebool[2][2] == true)
			{
				fightstarter(2);
				levelonebool[2][2] = false;
			}
			break;
		case 14:
			//treasure
			if (levelonebool[2][3] == true)
			{
				treasure(2);
				levelonebool[2][3] = false;
			}
			break;
		case 15:
			//secret
			if (levelonebool[2][4] == true)
			{
				secret(2);
				levelonebool[2][4] = false;
			}
			break;
		case 16:
			//goblin
			if (levelonebool[3][0] == true)
			{	
				fightstarter(2);
				levelonebool[3][0] = false;
			}
			break;
		case 17:
			//treasure
			if (levelonebool[3][1] == true)
			{
				treasure(3);
				levelonebool[3][1] = false;
			}
			break;
		case 18:
			//trap
			if (levelonebool[3][2] == true)
			{
				trap(3);
				levelonebool[3][2] = false;
			}
			break;
		case 19:
			//goblin
			if (levelonebool[3][3] == true)
			{	
				fightstarter(2);
				levelonebool[3][3] = false;
			}
			break;
		case 20:
			//blank
			if (levelonebool[3][4] == true)
			{
				levelonebool[3][4] = false;
			}
			break;
		case 21:
			//trap
			if (levelonebool[4][0] == true)
			{
				trap(4);
				levelonebool[4][0] = false;
			}
			break;
		case 22:
			//EXIT
			if (levelonebool[4][1] == true)
			{
				levelonebool[4][1] = false;
			}
			sectionRead(0, 34, 39);
			cave1 = false;
			break;
		case 23:
			//ogre
			if (levelonebool[4][2] == true)
			{		
				fightstarter(3);
				levelonebool[4][2] = false;
			}
			break;
		case 24:
			//secret
			if (levelonebool[4][3] == true)
			{
				secret(3);
				levelonebool[4][3] = false;
			}
			break;
		case 25:
			//treasure
			if (levelonebool[4][4] == true)
			{
				treasure(4);
				levelonebool[4][4] = false;
			}
			break;
		}
		levelonechar[varias.Y][varias.X] = 'C';
	}
}

void cavetwo()
{
	//THIS ONE IS A FOREST
	varias.X = 0;
	varias.Y = 0;
	cave2 = true;
	cout << "Entering the forest from the north, the path out on your map is a few hours south." << endl;
	//DO SOME READING HERE, STORY IS FOR LATER THO
	while (cave2 == true)
	{
		maptwo();
		lineBreak(1);
		cout << "The forest goes quiet around you." << endl << "It seems you have a chance to move on..." << endl;
		Sleep(1000);
		cout << "1: Move south" << endl << "2: Move north" << endl << "3: Move west" << endl << "4: Move east" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			varias.Y++;
			break;
		case 2:
			varias.Y--;
		case 3:
			varias.X--;
			break;
		case 4:
			varias.X++;
			break;
		}
		if (varias.X > 5)
		{
			cout << "You've wandered off of your map! You become lost in the forest for a short while!" << endl;
			lineBreak(2);
			Sleep(2000);
			cout << "Whilst walking around in the shrubbery, you encounter an enemy!" << endl;
			fightstarter(7);
			lineBreak(1);
			cout << "After beating your enemy, you return to the path." << endl;
			varias.X = 5;
		}
		if (varias.X < 0)
		{
			cout << "You've wandered off of your map! You become lost in the forest for a short while!" << endl;
			lineBreak(2);
			Sleep(2000);
			cout << "Whilst walking around in the shrubbery, you encounter an enemy!" << endl;
			fightstarter(7);
			lineBreak(1);
			cout << "After beating your enemy, you return to the path." << endl;
			varias.X = 0;
		}
		if (varias.Y < 0)
		{
			cout << "You've wandered off of your map! You become lost in the forest for a short while!" << endl;
			lineBreak(2);
			Sleep(2000);
			cout << "Whilst walking around in the shrubbery, you encounter an enemy!" << endl;
			fightstarter(7);
			lineBreak(1);
			cout << "After beating your enemy, you return to the path." << endl;
			varias.Y = 0;
		}
		if (varias.Y > 5)
		{
			cout << "You've wandered off of your map! You become lost in the forest for a short while!" << endl;
			lineBreak(2);
			Sleep(2000);
			cout << "Whilst walking around in the shrubbery, you encounter an enemy!" << endl;
			fightstarter(7);
			lineBreak(1);
			cout << "After beating your enemy, you return to the path." << endl;
			varias.Y = 5;
		}
		//REMEMBER THAT ARRAYS= 0->4
		//F = FIGHT, T = TREASURE, B = BLOCK, S = SECRET, X = EVENT E = ENTRANCE/EXIT 0 = BLANK
		//01 02 03 04 05 06 - 0,0 0,1 0,2 0,3 0,4 0,5 - E S F B T B
		//07 08 09 10 11 12 - 1,0 1,1 1,2 1,3 1,4 1,5 - F X 0 F F 0 
		//13 14 15 16 17 18 - 2,0 2,1 2,2 2,3 2,4 2,5 - B T F F S X 
		//19 20 21 22 23 24 - 3,0 3,1 3,2 3,3 3,4 3,5 - S X F 0 F F
		//25 26 27 28 29 30 - 4,0 4,1 4,2 4,3 4,4 4,5 - F X B B F X
		//31 32 33 34 35 36 - 5,0 5,1 5,2 5,3 5,4 5,5 - T F F X E S
		if (leveltwobool[varias.Y][varias.X] == true)
		{
			switch (leveltwo[varias.Y][varias.X])
			{
			case 1:
				//ENTER
				break;
			case 2:
				//SECRET
				secret(4);
				break;
			case 3:
				//FIGHT
				fightstarter(3);
				break;
			case 4:
				//BLOCK
				block();
				break;
			case 5:
				//TREASURE
				treasure(1);
				break;
			case 6:
				//BLOCK
				block();
				break;
			case 7:
				//FIGHT
				fightstarter(3);
				break;
			case 8:
				//FIGHT
				fightstarter(2);
				break;
			case 9:
				//BLANK
				break;
			case 10:
				//FIGHT
				fightstarter(9);
				break;
			case 11:
				//FIGHT
				fightstarter(3);
				break;
			case 12:
				//BLANK
				break;
			case 13:
				//BLOCK
				block();
				break;
			case 14:
				//TREASURE
				treasure(3);
				break;
			case 15:
				//FIGHT
				fightstarter(3);
				break;
			case 16:
				//FIGHT
				fightstarter(9);
				break;
			case 17:
				//SECRET
				secret(5);
				break;
			case 18:
				//EVENT
				trap(2);
				break;
			case 19:
				//SECRET
				secret(6);
				break;
			case 20:
				//EVENT
				trap(3);
				break;
			case 21:
				//FIGHT
				fightstarter(10);
				break;
			case 22:
				//BLANK
				break;
			case 23:
				//FIGHT
				fightstarter(10);
				break;
			case 24:
				//FIGHT
				fightstarter(9);
				break;
			case 25:
				//FIGHT
				fightstarter(3);
				break;
			case 26:
				//EVENT
				trap(1);
				break;
			case 27:
				//BLOCK
				block();
				break;
			case 28:
				//BLOCK
				block();
				break;
			case 29:
				//FIGHT
				fightstarter(9);
				break;
			case 30:
				//EVENT
				trap(5);
				break;
			case 31:
				//TREASURE
				treasure(3);
				break;
			case 32:
				//FIGHT
				fightstarter(10);
				break;
			case 33:
				//FIGHT
				fightstarter(10);
				break;
			case 34:
				//EVENT
				trap(5);
				break;
			case 35:
				//EXIT
				cave2 = false;
				break;
			case 36:
				//SECRET
				secret(7);
				break;
			}
			leveltwobool[varias.Y][varias.X] = false;
			varias.PX = varias.X;
			varias.PY = varias.Y;
		}
		leveltwochar[varias.Y][varias.X] = 'C';
	}
}

void cavethree()
{
	//THIS ONE IS A CASTLE
	varias.X = 0;
	varias.Y = 6;
	cave3 = true;
	cout << "Entering the castle from the south, ." << endl;
	//DO SOME READING HERE, STORY IS FOR LATER THO
	while (cave3 == true)
	{
		mapthree();
		lineBreak(1);
		cout << "The hallway goes quiet around you." << endl << "It seems you have a chance to move on..." << endl;
		Sleep(1000);
		cout << "1: Move south" << endl << "2: Move north" << endl << "3: Move west" << endl << "4: Move east" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			varias.Y++;
			break;
		case 2:
			varias.Y--;
		case 3:
			varias.X--;
			break;
		case 4:
			varias.X++;
			break;
		}
		if (varias.X > 6)
		{
			cout << "You become lost in the twisting hallways for a short while!" << endl;
			lineBreak(2);
			Sleep(2000);
			cout << "Whilst walking around in the confusing architecture, you encounter an enemy!" << endl;
			fightstarter(7);
			lineBreak(1);
			cout << "After beating your enemy, you return to the path." << endl;
			varias.X = 6;
		}
		if (varias.X < 0)
		{
			cout << " become lost in the twisting hallways for a short while!" << endl;
			lineBreak(2);
			Sleep(2000);
			cout << "Whilst walking around in the confusing architecture, you encounter an enemy!" << endl;
			fightstarter(7);
			lineBreak(1);
			cout << "After beating your enemy, you return to the path." << endl;
			varias.X = 0;
		}
		if (varias.Y < 0)
		{
			cout << "You become lost in the the twisting hallways for a short while!" << endl;
			lineBreak(2);
			Sleep(2000);
			cout << "Whilst walking around in the confusing architecture, you encounter an enemy!" << endl;
			fightstarter(7);
			lineBreak(1);
			cout << "After beating your enemy, you return to the path." << endl;
			varias.Y = 0;
		}
		if (varias.Y > 6)
		{
			cout << "You become lost in the twisting hallways for a short while!" << endl;
			lineBreak(2);
			Sleep(2000);
			cout << "Whilst walking around in the confusing architecture, you encounter an enemy!" << endl;
			fightstarter(7);
			lineBreak(1);
			cout << "After beating your enemy, you return to the path." << endl;
			varias.Y = 6;
		}
		//REMEMBER THAT ARRAYS= 0->4
		//F = FIGHT, T = TREASURE, B = BLOCK, S = SECRET, X = EVENT/TRAP E = ENTRANCE/EXIT 0 = BLANK
		//01 02 03 04 05 06 07 - 0,0 0,1 0,2 0,3 0,4 0,5 0,6 - B S F X F T B
		//08 09 10 11 12 13 14 - 1,0 1,1 1,2 1,3 1,4 1,5 1,6 - B F 0 S F F 0
		//15 16 17 18 19 20 21 - 2,0 2,1 2,2 2,3 2,4 2,5 2,6 - F 0 S F 0 B X
		//22 23 24 25 26 27 28 - 3,0 3,1 3,2 3,3 3,4 3,5 3,6 - T F F B B F T
		//29 30 31 32 33 34 35 - 4,0 4,1 4,2 4,3 4,4 4,5 4,6 - F F X F F 0 0
		//36 37 38 39 40 41 42 - 5,0 5,1 5,2 5,3 5,4 5,5 5,6 - X F B F T B F
		//43 44 45 46 47 48 49 - 6,0 6,1 6,2 6,3 6,4 6,5 6,6 - E X F T F B S
		if (levelthreebool[varias.Y][varias.X] == true)
		{
			switch (levelthree[varias.Y][varias.X])
			{
			case 1:
				//BLOCK
				block();
				break;
			case 2:
				//SECRET
				secret(9);
				break;
			case 3:
				//FIGHT
				fightstarter(8);
				break;
			case 4:
				//EVENT - BOSS	
				fightstarter(6);
				break;
			case 5:
				//FIGHT
				fightstarter(5);
				break;
			case 6:
				//TREASURE
				treasure(3);
				break;
			case 7:
				//BLOCK
				block();
				break;
			case 8:
				//BLOCK
				block();
				break;
			case 9:
				//FIGHT
				fightstarter(5);
				break;
			case 10:
				//BLANK
				break;
			case 11:
				//SECRET - BOSS PREP
				secret(10);
				break;
			case 12:
				//FIGHT
				fightstarter(8);
				break;
			case 13:
				//FIGHT
				fightstarter(5);
				break;
			case 14:
				//BLANK
				break;
			case 15:
				//FIGHT
				fightstarter(4);
				break;
			case 16:
				//BLANK
				break;
			case 17:
				//SECRET
				secret(8);
				break;
			case 18:
				//FIGHT
				fightstarter(8);
				break;
			case 19:
				//BLANK
				break;
			case 20:
				//BLOCK
				block();
				break;
			case 21:
				//EVENT
				trap(7);
				break;
			case 22:
				//TREASURE
				treasure(2);
				break;
			case 23:
				//FIGHT
				fightstarter(3);
				break;
			case 24:
				//FIGHT
				fightstarter(4);
				break;
			case 25:
				//BLOCK
				block();
				break;
			case 26:
				//BLOCK
				block();
				break;
			case 27:
				//FIGHT
				fightstarter(5);
				break;
			case 28:
				//TREASURE
				treasure(1);
				break;
			case 29:
				//FIGHT
				fightstarter(8);
				break;
			case 30:
				//FIGHT
				fightstarter(8);
				break;
			case 31:
				//EVENT
				trap(6);
				break;
			case 32:
				//FIGHT
				fightstarter(4);
				break;
			case 33:
				//FIGHT
				fightstarter(4);
				break;
			case 34:
				//BLANK
				break;
			case 35:
				//BLANK
				break;
			case 36:
				//EVENT
				trap(2);
				break;
			case 37:
				//FIGHT
				fightstarter(5);
				break;
			case 38:
				//BLOCK
				block();
				break;
			case 39:
				//FIGHT
				fightstarter(4);
				break;
			case 40:
				//TREASURE
				treasure(3);
				break;
			case 41:
				//BLOCK
				block();
				break;
			case 42:
				//FIGHT
				fightstarter(5);
				break;
			case 43:
				//ENTER
				break;
			case 44:
				//EVENT
				trap(2);
				break;
			case 45:
				//FIGHT
				fightstarter(4);
				break;
			case 46:
				//TREASURE
				treasure(4);
				break;
			case 47:
				//FIGHT
				fightstarter(4);
				break;
			case 48:
				//BLOCK
				block();
				break;
			case 49:
				//SECRET
				secret(11);
				break;
			}
			levelthreebool[varias.Y][varias.X] = false;
			varias.PX = varias.X;
			varias.PY = varias.Y;
		}
		levelthreechar[varias.Y][varias.X] = 'C';
	}
}

void finalboss()
{
	lineBreak(1);
	cout << "You have a chance to use some items before you move on." << endl;
	Item();
	lineBreak(1);
	if (varias.lore < 11)
	{
		sectionRead(1, 38, 42);
		bossmaker();
		bossloop();
		lineBreak(1);
		sectionRead(1, 71, 74);
	}
	else if (varias.lore == 11)
	{
		sectionRead(1, 44, 50);
		bossmaker();
		bossloop();
		sectionRead(1, 60, 69);
		lineBreak(1);
		cout << "1. Spare Jarl, and let him complete his mission" << endl << "2. Kill Jarl, and finish your own mission." << endl;
		cin >> choice;
		if (choice > 2 || choice == 0)
		{
			while (choice > 2 || choice == 0)
			{
				cin >> choice;
			}
		}
		switch (choice)
		{
		case 1:
			lineBreak(1);
			sectionRead(1, 71, 74);
			break;
		case 2:
			lineBreak(1);
			sectionRead(1, 76, 83);
			break;
		}
	}
}

int main()
{
	varias.TESTER = 1;
	cout << "Sword Quest" << endl;
	lineBreak(2);
	standinhero();
	cout << "Written and Developed by Alex Marshall" << endl;
	lineBreak(2);
	cout << "To begin, please input your name." << endl;
	cin >> varias.name;
	cout << "Welcome to the game, " << varias.name << "!" << endl;
	lineBreak(1);
	sectionRead(0, 2, 10);
	lineBreak(1);
	heroMaker();
	lineBreak(1);
	sectionRead(0, 12, 22);
	lineBreak(1);
	sectionRead(0, 24, 28);
	lineBreak(1);
	caveone();
	drop();
	lineBreak(1);
	sectionRead(0, 61, 65);
	fightstarter(8);
	lineBreak(1);
	sectionRead(0, 67, 72);
	cavetwo();
	lineBreak(1);
	sectionRead(0, 74, 80);
	drop();
	lineBreak(1);
	sectionRead(0, 81, 87);
	fightstarter(11);	
	lineBreak(1);
	sectionRead(1, 2, 7);
	drop();
	cavethree();
	lineBreak(1);
	finalboss();
	lineBreak(2);
	cout << "THE END" << endl;
	collect();
    return 0;
}
