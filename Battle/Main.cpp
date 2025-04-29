#include <iostream>
#include <algorithm>
#include <stdlib.h>  
#include <time.h> 

class Character {
public:
	Character(std::string name) 
	{
		Name = name;
		SetHealth(rand()%100+1);
		Damage = rand() % 30 + 10;
		Defense = rand() % 10;
	}
	void DisplayInformation() 
	{
		std::cout << "Name: " << Name<<std::endl;
		std::cout << "Health: " << Health << std::endl;
		std::cout << "Attack: " << Damage << std::endl;
		std::cout << "Defense: " << Defense << std::endl;
		std::cout << std::endl;
	}

	void SetHealth(int newhealth) 
	{
		Health = newhealth;
		if (Health < 0) 
		{
			Health = 0;
		}
	}
	std::string GetName()
	{
		return Name;
	}
	int GetHealth() 
	{
		return Health;
	}
	int GetDamage() 
	{
		return Damage;
	}

	int GetDefense() 
	{
		return Defense;
	}
	
private:
	std::string Name;
	int Health;
	int Damage;	
	int Defense;
};

class Battle 
{
public:
	void InitiateBattle(Character &A, Character &B) 
	{
		
		std::cout << "--InitialState--" << std::endl;
		A.DisplayInformation();
		B.DisplayInformation();
		std::cout << "--Combat--" << std::endl;
		Fight(A, B);
		Fight(B, A);

	}
	
	void ShowFinalBattleStats(Character &A, Character &B) 
	{
		std::cout << "--Final State--" << std::endl;
		A.DisplayInformation();
		B.DisplayInformation();
	}
protected:
	void Fight(Character &A, Character &B)
	{
		std::cout << A.GetName() << " attacks " << B.GetName() << "!" << std::endl;
		std::cout << B.GetName() << " Receives  " << A.GetDamage() - B.GetDefense() << " of damage!" << std::endl;
		B.SetHealth(B.GetHealth() - (A.GetDamage() - B.GetDefense()));
	}


};

int main() 
{
	std::srand(std::time(NULL));

	std::string fighter1, fighter2;
	
	std::cout << "Welcome to the battle Simulator Bonanza" << std::endl;
	std::cout << "Please introduce the first name of your fighter" << std::endl;
	std::cin >> fighter1;
	std::cout << "Please introduce the second name of your fighter" << std::endl;
	std::cin >> fighter2;

	Character CharacterA(fighter1), CharacterB(fighter2);

	Battle Arena;

	Arena.InitiateBattle(CharacterA,CharacterB);

	Arena.ShowFinalBattleStats(CharacterA, CharacterB);

	return 0;
}
