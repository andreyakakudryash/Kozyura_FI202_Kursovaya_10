#include <iostream>
#include <vector>
#include <string>
#include "view.h"
#include "operations.h"

using namespace std;

class controller {

private:
	int state;
	main_operations current_order;

public:

	controller() {

	}

	~controller() {

	}



	void execute() {
		int run = 1;
		while (run) {
			menu();
			int var;
			cin >> var;
			while (var < 1 || var > 8) {
				cout << "��� ����� �����,������� �� ������ � �������� ��������������� ������. ����������, ���������� ��� ���!\n";
				cin >> var;
			}

			if (var == 1) {
				current_order.print();
			}

			if (var == 2) {
				run = 0;
			}

			if (var == 3) {
				current_order.addOrder();
			}

			if (var == 4) {
				current_order.print();
				cout << "�������� ����� ������, ������� ������ ������� ";
				int index;
				cin >> index;
				current_order.deleteOrder(index);
				cout << "��������� ����� ������� �����" << endl;
			}

			if (var == 5) {
				current_order.print();
				cout << "�������� �����, ������� ���������� ��������������� ";
				int index;
				cin >> index;
				current_order.editOrder(index);
			}

			if (var == 6) {
				current_order.saveToFile();
				cout << "������ ���� ������� ��������� � ����" << endl;
			}

			if (var == 7) {
				current_order.deleteFromFile();
				cout << "���������� ����� ������� �������" << endl;
			}

			if (var == 8) {
				current_order.loadFromFile();
				cout << "����� �� ����� ��������" << endl;

			}


		}
	}


};



