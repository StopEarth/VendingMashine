#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;
class VendingMashine;
class Storage;
class ShowCase;
class User;
class Technician;
class Owner;
class Goods;

class VendingMashine
{
private:
	int balance,
		durability;
	bool workingcapacity;
public:
	VendingMashine()
	{}
	VendingMashine(int b, int d, bool w)
	{
		balance = b;
		durability = d;
		workingcapacity = w;
	}
	void giveOutGoods(int, Storage&, User&, ShowCase&);
	void Pay(int, User&);
	void giveChange(int, int, User&);
	void setDurability(int n);
	void setworkingcapacity(bool n);
	int getMoney();
	bool const returnWorcingcapacity();
	friend User;
};

class Storage
{
private:
	int goodsquantity[10];
	string goodsname[10];
	int quantity;
public:
	Storage()
	{}
	Storage(int n)
	{
		quantity = n;
	}
	void fillStorage(int, int, string);
	void fillStorage(int, int);
	void giveOutGoods(int);
	bool const checkGoods(int);
	void const checkStorage(int);
	int const checkQuantityGoods(int);
	friend Technician;
};

class User
{
protected:
	int cash;
public:
	User(int c)
	{
		cash = c;
	}
	int Buy(int);
	bool const checkCash(int);
	void pickupChange(int);
	void const getCash();
};

class Owner : public User
{
private:
	int cash;
public:
	Owner(int c) : User(c)
	{}
	void colectMoney(VendingMashine&);
	void payForRepairs(Technician&, VendingMashine&);
	void payForReffils(Technician&, Storage&, int, int);
	friend Goods;
};

class ShowCase
{
private:
	int goodsprice[10];
	string goodsname[10];
	int quantity;
public:
	ShowCase()
	{}
	void fillTheShowCase(int, string, int);
	int const getPrice(int);
};

class Technician : public User
{
private:
	int cash;
public:
	Technician(int c) : User(c)
	{}
	void Repair(VendingMashine&);
	void Refill(int, Storage&);
	void setCash(int);
};

class Goods
{
private:
	int cost;
	string name;
public:
	Goods(int c, string n)
	{
		cost = c;
		name = n;
	}
	string const getName();
	int const getCost();
};