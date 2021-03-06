// ConsoleApplication10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Header.h"

int main()
{
	int n = 4; //количество товаров в автомате ;
	Owner Owner1(100);
	Technician Technician1(0);
	VendingMashine VendingMashine1(0, 100, 1);
	ShowCase ShowCase1;
	User User1(200);
	Storage Storage1;
	Goods Sprite(12, "sprite");
	Goods Milka(15, "milka");
	Goods Tuc(7, "Tuc");
	Goods Artek(5, "Artek");
	ShowCase1.fillTheShowCase(1, Sprite.getName(), Sprite.getCost());
	ShowCase1.fillTheShowCase(2, Milka.getName(), Milka.getCost());
	ShowCase1.fillTheShowCase(3, Tuc.getName(), Tuc.getCost());
	ShowCase1.fillTheShowCase(4, Artek.getName(), Artek.getCost());
	Storage1.fillStorage(1, 10, Sprite.getName());
	Storage1.fillStorage(2, 10, Milka.getName());
	Storage1.fillStorage(3, 10, Tuc.getName());
	Storage1.fillStorage(4, 10, Artek.getName());
	bool flag = VendingMashine1.returnWorcingcapacity();
	while (flag)
	{
		string answer;
		char elem[50];
		cout << endl;
		cout << "Menu : " << endl << endl;
		cout << "Enter 1. Buy " << Sprite.getName() << " for " << Sprite.getCost() << " UAH" << endl;
		cout << "Enter 2. Buy " << Milka.getName() << " for " << Milka.getCost() << " UAH" << endl;
		cout << "Enter 3. Buy " << Tuc.getName() << " for " << Tuc.getCost() << " UAH" << endl;
		cout << "Enter 4. Buy " << Artek.getName() << " for " << Artek.getCost() << " UAH" << endl;
		cout << "Enter 5. Check cash" << endl;
		cout << "Enter 6. Check storage " << endl;
		cout << "Enter 7. Exit." << endl << endl;
		int q;
		do
		{
			cin >> elem;
			q = atoi(elem);
			if ((q <= 0) || (q > 7))
			{
				cout << "Error, try again" << endl;
			}
			else break;
		} while (1);
		switch (q)
		{
		case(1):
		{
			VendingMashine1.giveOutGoods(1, Storage1, User1, ShowCase1);
			cout << "something else ?" << endl;
			if (Storage1.checkQuantityGoods(1) == 0)
			{
				cout << "(For owner) Do you want to fill the storage?" << endl;
				cin >> answer;
				if ((answer == "Yes") || (answer == "yes"))
				{
					Owner1.payForReffils(Technician1, Storage1, ShowCase1.getPrice(1), 1);
				}
			}
			srand(time(0));
			if ((1 + rand() % 100) > 95) flag = false;
			if (flag == false)
			{
				cout << "Wendingmashine is out of order" << endl;
				VendingMashine1.setworkingcapacity(0);
				cout << "(For owner) Do you want to repair the machine?" << endl;
				cin >> answer;
				if ((answer == "Yes") || (answer == "yes"))
				{
					Owner1.payForRepairs(Technician1, VendingMashine1);
					flag = true;
				}
			}
			break;
		}
		case(2):
		{
			VendingMashine1.giveOutGoods(2, Storage1, User1, ShowCase1);
			cout << "something else ?" << endl;
			if (Storage1.checkQuantityGoods(2) == 0)
			{
				cout << "(For owner) Do you want to fill the storage?" << endl;
				cin >> answer;
				if ((answer == "Yes") || (answer == "yes"))
				{
					Owner1.payForReffils(Technician1, Storage1, ShowCase1.getPrice(2), 2);
				}
			}
			srand(time(0));
			if ((1 + rand() % 100) > 95) flag = false;
			if (flag == false)
			{
				cout << "Wendingmashine is out of order" << endl;
				VendingMashine1.setworkingcapacity(0);
				cout << "(For owner) Do you want to repair the machine?" << endl;
				cin >> answer;
				if ((answer == "Yes") || (answer == "yes"))
				{
					Owner1.payForRepairs(Technician1, VendingMashine1);
					flag = true;
				}
			}
			break;
		}
		case(3):
		{
			VendingMashine1.giveOutGoods(3, Storage1, User1, ShowCase1);
			cout << "something else ?" << endl;
			if (Storage1.checkQuantityGoods(3) == 0)
			{
				cout << "(For owner) Do you want to fill the storage?" << endl;
				cin >> answer;
				if ((answer == "Yes") || (answer == "yes"))
				{
					Owner1.payForReffils(Technician1, Storage1, ShowCase1.getPrice(3), 3);
				}
			}
			srand(time(0));
			if ((1 + rand() % 100) > 95) flag = false;
			if (flag == false)
			{
				cout << "Wendingmashine is out of order" << endl;
				VendingMashine1.setworkingcapacity(0);
				cout << "(For owner) Do you want to repair the machine?" << endl;
				cin >> answer;
				if ((answer == "Yes") || (answer == "yes"))
				{
					Owner1.payForRepairs(Technician1, VendingMashine1);
					flag = true;
				}
			}
			break;
		}
		case(4):
		{
			VendingMashine1.giveOutGoods(4, Storage1, User1, ShowCase1);
			cout << "something else ?" << endl;
			if (Storage1.checkQuantityGoods(4) == 0)
			{
				cout << "(For owner) Do you want to fill the storage?" << endl;
				cin >> answer;
				if ((answer == "Yes") || (answer == "yes"))
				{
					Owner1.payForReffils(Technician1, Storage1, ShowCase1.getPrice(4), 4);
				}
			}
			srand(time(0));
			if ((1 + rand() % 100) > 95) flag = false;
			if (flag == false)
			{
				cout << "Wendingmashine is out of order" << endl;
				VendingMashine1.setworkingcapacity(0);
				cout << "(For owner) Do you want to repair the machine?" << endl;
				cin >> answer;
				if ((answer == "Yes") || (answer == "yes"))
				{
					Owner1.payForRepairs(Technician1, VendingMashine1);
					flag = true;
				}
			}
			break;
		}
		case(5):
		{
			User1.getCash();
			cout << "something else ?" << endl;
			break;
		}
		case(6):
		{
			for (int i = 1; i <= 4; i++)
			{
				Storage1.checkStorage(i);
			}
			cout << "something else ?" << endl;
			break;
		}
		case(7):
		{
			flag = false;
			break;
		}
		}
	}
    return 0;
}