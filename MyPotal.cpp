/*
   �߰�����
1. ����, ���� ������ ���� ������ ���� ������ ����Ͽ���.
2. �����̼��� ���� ������ �����̼����� ���� ������ ����Ͽ���.
3. Ŭ������ �⺻������ �̸�, �й� ����� �߰� �Ͽ���.
4. �⺻��¿� ��������� �̼�������� �̼������� �߰��Ͽ���.
*/

#include "student.h"
#include "standardheader.h"
#include "schedule.h"
#include "Money.h"

int menu();
bool check();
bool menustuendt();
bool menuschdule();
bool menumoney();
void help();

void main() {

	while (check());
	
}

int menu() {
	int mnum;
	cout << endl;
	cout << "------------------------------\n";
	cout << "          ��      ��          \n";
	cout << endl;
	cout << "  1. ��  ��   ��  ��\n";
	cout << "  2. �����ٷ�(����)\n";
	cout << "  3. ��     ��     ��\n";
	cout << "  4. ���α׷�   �� ��\n";
	cout << "  5. ��           ��\n";
	cout << "------------------------------\n";
	cout << "�Ŵ��� �����ϼ���.  ";
	cin >> mnum;

	return mnum;
}

bool check() {
	switch (menu()) {
	case 1:
		system("cls");
		while(menustuendt());
		system("cls");
		return true;
	case 2:
		system("cls");
		while (menuschdule());
		system("cls");
		return true;
	case 3:
		system("cls");
		while(menumoney());
		system("cls");
		return true;
	case 4:
		system("cls");
			help();
		return true;
	case 5:
		cout << "-------------------\n";
		cout << "���α׷��� �����մϴ�.\n";
		cout << "-------------------\n";
		return false;

	}
}

bool menustuendt() {
	ifstream fi("db1.txt");
	Student s1("����ȣ", "201401989", fi);
	int check;
	cout << endl;
	cout << "-------------------------------\n";
	cout << "          �� �� �� ��          \n";
	cout << endl;
	cout << "  1. �� ��  �� ��\n";
	cout << "  2. �ܿ��ʿ�����\n";
	cout << "  3. ��        ��\n";
	cout << "------------------------------\n";
	cout << "�Ŵ��� �����ϼ���.  ";
	cin >> check;
	switch (check) {
	case 1:
		system("cls");
		cout << endl;
		s1.PrintInfo();
		return true;

	case 2:
		system("cls");
		cout << endl;
		s1.remainCredit();
		return true;

	case 3:
		return false;

	}
	

}

bool menuschdule() {
	schedule sc1;
	int check;
	cout << endl;
	cout << "-------------------------------\n";
	cout << "          ���� ����          \n";
	cout << endl;
	cout << "  1. ����  ����\n";
	cout << "  2. �����߰�\n";
	cout << "  3. ��������\n";
	cout << "  4. ��      ��\n";
	cout << "------------------------------\n";
	cout << "�Ŵ��� �����ϼ���.  ";
	cin >> check;
	switch (check) {
	case 1:
		system("cls");
		cout << endl;
		sc1.show();
		return true;

	case 2:
		system("cls");
		cout << endl;
		sc1.inschedile();
		return true;
	case 3:
		system("cls");
		cout << endl;
		sc1.removedata();
		return true;
	case 4:
		return false;

	}


}

bool menumoney() {
	Money m1;
	int check;
	cout << endl;
	cout << "-------------------------------\n";
	cout << "        ��    ��   ��          \n";
	cout << endl;
	cout << "  1. �� ��  �� ��\n";
	cout << "  2. �� ��  �� ��\n";
	cout << "  3. ���⳻��Ȯ��\n";
	cout << "  4. �� ��  Ȯ ��\n";
	cout << "  5. ��        ��\n";
	cout << "------------------------------\n";
	cout << "�Ŵ��� �����ϼ���.  ";
	cin >> check;
	switch (check) {
	case 1:
		system("cls");
		cout << endl;
		m1.inmoney();
		return true;

	case 2:
		system("cls");
		cout << endl;
		m1.outmoney();
		return true;
	case 3:
		system("cls");
		cout << endl;
		m1.checkoutcontent();
		return true;
	case 4:
		system("cls");
		cout << endl;
		m1.print();
		return true;
	case 5:
		return false;

	}
}

void help() {
	cout << "------���α׷� ����-------\n";
	cout << "���α׷� ���� 1.3\n";
	cout << "�������� �� ���� ������ ������ ���������� �߰� �Ͽ�����,\n";
	cout << "�뵷�������� ����η� �ٲٿ� ���� �������� �ǹ̸� �ο�.\n";
	cout << "������ : ����ȣ   Update �Ͻ� : 2017.12.18\n";

}