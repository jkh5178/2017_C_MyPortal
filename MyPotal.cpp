/*
   추가사항
1. 전공, 교양 학점을 따로 나누어 남은 학점을 계산하였다.
2. 교직이수를 진행 함으로 교직이수또한 남은 학점을 계산하였다.
3. 클래스의 기본사항인 이름, 학번 출력을 추가 하였다.
4. 기본출력에 현재까지의 이수과목수와 이수학점을 추가하였다.
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
	cout << "          메      뉴          \n";
	cout << endl;
	cout << "  1. 학  점   관  리\n";
	cout << "  2. 스케줄러(보고서)\n";
	cout << "  3. 가     계     부\n";
	cout << "  4. 프로그램   정 보\n";
	cout << "  5. 종           료\n";
	cout << "------------------------------\n";
	cout << "매뉴를 선택하세요.  ";
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
		cout << "프로그램을 종료합니다.\n";
		cout << "-------------------\n";
		return false;

	}
}

bool menustuendt() {
	ifstream fi("db1.txt");
	Student s1("전광호", "201401989", fi);
	int check;
	cout << endl;
	cout << "-------------------------------\n";
	cout << "          학 점 관 리          \n";
	cout << endl;
	cout << "  1. 학 생  정 보\n";
	cout << "  2. 잔여필요학점\n";
	cout << "  3. 이        전\n";
	cout << "------------------------------\n";
	cout << "매뉴를 선택하세요.  ";
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
	cout << "          보고서 관리          \n";
	cout << endl;
	cout << "  1. 내용  보기\n";
	cout << "  2. 보고서추가\n";
	cout << "  3. 보고서삭제\n";
	cout << "  4. 이      전\n";
	cout << "------------------------------\n";
	cout << "매뉴를 선택하세요.  ";
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
	cout << "        가    계   부          \n";
	cout << endl;
	cout << "  1. 수 입  입 력\n";
	cout << "  2. 지 출  입 력\n";
	cout << "  3. 지출내용확인\n";
	cout << "  4. 잔 액  확 인\n";
	cout << "  5. 이        전\n";
	cout << "------------------------------\n";
	cout << "매뉴를 선택하세요.  ";
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
	cout << "------프로그램 정보-------\n";
	cout << "프로그램 버젼 1.3\n";
	cout << "학점관리 및 보고서 스케쥴 관리를 순차적으로 추가 하였으며,\n";
	cout << "용돈기입장을 가계부로 바꾸워 좀더 포괄적인 의미를 부여.\n";
	cout << "만든이 : 전광호   Update 일시 : 2017.12.18\n";

}