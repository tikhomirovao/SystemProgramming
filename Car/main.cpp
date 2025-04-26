﻿#include<iostream>
using namespace std;

#define MIN_TANK_CAPACITY	 20
#define MAX_TANK_CAPACITY	120

class Tank
{
	double fuel_level;
public:
	const int CAPACITY;
	double get_fuel_level()const
	{
		return fuel_level;
	}
	Tank(int capacity) :CAPACITY
	(
		capacity < MIN_TANK_CAPACITY ? MIN_TANK_CAPACITY :
		capacity > MAX_TANK_CAPACITY ? MAX_TANK_CAPACITY :
		capacity
	),
		fuel_level(0)
	{
		cout << "Tank:";
		if (capacity < MIN_TANK_CAPACITY)cout << "Min capacity was applied" << endl;
		if (capacity > MAX_TANK_CAPACITY)cout << "Max capacity was applied" << endl;
		//this->CAPACITY = capacity;
		//this->fuel_level = 0;
		cout << "Tank is ready" << endl;
	}
	~Tank()
	{
		cout << "Tank is over" << endl;
	}
	double fill(double amount)
	{
		if (amount < 0)return fuel_level;
		fuel_level += amount;
		if (fuel_level >= CAPACITY)
		{
			fuel_level = CAPACITY;
			cout << "Full Tank" << endl;
		}
		return fuel_level;
	}
	double give_fuel(double amount)
	{
		fuel_level -= amount;
		if (fuel_level < 0)fuel_level = 0;
		return fuel_level;
	}
	void info()const
	{
		cout << "Capacity:\t" << CAPACITY << " liters.\n";
		cout << "Fuel level:\t" << fuel_level << " liters.\n";
	}
};

#define MIN_ENGINE_CONSUMPTION		 3
#define MAX_ENGINE_CONSUMPTION		25
class Engine
{
	const double CONSUPTION;	//расход на 100 км
	const double DEFAULT_CONSUMPTON_PER_SECOND;
	double consumption_per_second;
	bool is_started;
public:
	double get_consumption_per_second()const
	{
		return consumption_per_second;
	}
	Engine(double consumption) :
		CONSUPTION
		(
			consumption < MIN_ENGINE_CONSUMPTION ? MIN_ENGINE_CONSUMPTION :
			consumption > MAX_ENGINE_CONSUMPTION ? MAX_ENGINE_CONSUMPTION :
			consumption
		),
		DEFAULT_CONSUMPTON_PER_SECOND(CONSUPTION * 3e-5),
		consumption_per_second(DEFAULT_CONSUMPTON_PER_SECOND)
	{
		cout << "Engine is ready" << endl;
	}
	~Engine()
	{
		cout << "Engine is over" << endl;
	}
	void start()
	{
		is_started = true;
	}
	void stop()
	{
		is_started = false;
	}
	bool started()const
	{
		return is_started;
	}
	void info()const
	{
		cout << "Consumption: " << CONSUPTION << " liters/100km\n";
		cout << "Default Consumption: " << DEFAULT_CONSUMPTON_PER_SECOND << " liters/s\n";
		cout << "Consumption: " << consumption_per_second << " liters/s\n";
	}
};

//#define TANK_CHECK
#define ENGINE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef TANK_CHECK
	Tank tank(80);
	double fuel;
	do
	{
		cout << "На сколько заправляемся? "; cin >> fuel;
		tank.fill(fuel);
		tank.info();
	} while (true);
	tank.info();
#endif // TANK_CHECK
	
#ifdef ENGINE_CHECK
	Engine engine(10); 
	engine.info();
#endif // ENGINE_CHECK

}