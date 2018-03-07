#pragma once

#include "stdafx.h"
#include "Header.h"

void VendingMashine::giveOutGoods(int n, Storage &Storage1, User &User1, ShowCase &ShowCase1)
{
	bool flag = Storage1.checkGoods(n);
	bool flag2 = false;
	if (flag == true) flag2 = User1.checkCash(ShowCase1.getPrice(n));
	if (flag2 == true) Pay(ShowCase1.getPrice(n), User1);
	if ((flag == true) && (flag2 == true)) Storage1.giveOutGoods(n);
}

void VendingMashine::Pay(int c, User &User1)
{
	int p = User1.Buy(c);
	balance += c;
	giveChange(c, p, User1);
}

void VendingMashine::giveChange(int c, int p, User &User1)
{
	balance -= p - c;
	User1.pickupChange(p - c);
}

void VendingMashine::setDurability(int n)
{
	durability = n;
}

void VendingMashine::setworkingcapacity(bool n)
{
	workingcapacity = n;
}

int VendingMashine::getMoney()
{
	if ((balance - 10) < 0) return 0;
	else
	{
		int n = balance - 10;
		balance = 10;
		return n;
	}
}

bool const VendingMashine::returnWorcingcapacity()
{
	return workingcapacity;
}

int User::Buy(int p)
{
	if (p % 10 > 0) p = p + (10 - p % 10);
	cash -= p;
	cout << "The transaction was successful, the goods were issued" << endl;
	return p;
}

bool const User::checkCash(int p)
{
	if ((p + (10 - p % 10)) > cash)
	{
		cout << "I can not buy it, I do not have enough money" << endl;
		return 0;
	}
	else return 1;
}

void User::pickupChange(int ch)
{
	cash += ch;
}

void const User::getCash()
{
	cout << "You have " << cash << " UAH" << endl;
}

void Storage::fillStorage(int n, int q, string na)
{
	goodsquantity[n] = q;
	goodsname[n] = na;
}

void Storage::fillStorage(int n, int q)
{
	goodsquantity[n] = q;
}

void Storage::giveOutGoods(int n)
{
	goodsquantity[n] -= 1;
}

bool const Storage::checkGoods(int n)
{
	if (goodsquantity[n] == 0)
	{
		cout << "The product is out of stock" << endl;
		return 0;
	}
	else return 1;
}

void const Storage::checkStorage(int n)
{
	cout << goodsname[n] << "  " << goodsquantity[n] << " pieces" << endl;
}

int const Storage::checkQuantityGoods(int n)
{
	return goodsquantity[n];
}

void ShowCase::fillTheShowCase(int n, string na, int p)
{
	goodsname[n] = na;
	goodsprice[n] = p;
}

int const ShowCase::getPrice(int n)
{
	return goodsprice[n];
}

int const Goods::getCost()
{
	return cost;
}

string const Goods::getName()
{
	return name;
}


void Technician::Refill(int n, Storage &Storage1)
{
	Storage1.fillStorage(n, 10);
}

void Technician::Repair(VendingMashine &VendingMashine1)
{
	VendingMashine1.setworkingcapacity(1);
}

void Technician::setCash(int n)
{
	cash += n;
}

void Owner::colectMoney(VendingMashine &VendingMashine1)
{
	cash += VendingMashine1.getMoney();
}

void Owner::payForRepairs(Technician &Technician1, VendingMashine &VendingMashine1)
{
	cash -= 20;
	Technician1.setCash(10);
	Technician1.Repair(VendingMashine1);
}

void Owner::payForReffils(Technician &Technician1, Storage &Storage1, int c, int n)
{
	cash -= (c-5) * 10;
	Technician1.setCash(10);
	Technician1.Refill(n, Storage1);
}