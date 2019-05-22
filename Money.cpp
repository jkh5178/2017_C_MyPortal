#include "Money.h"

Money::Money() {
	infile.open("totalmoney.txt");
	while (!infile.eof()) {
		infile >> money;
	}
	infile.close();
}
void Money::inmoney() {
	outfile.open("totalmoney.txt", fstream::trunc);
	int m;
	cout << "수입을 입력하시오.   ";
	cin >> m;
	money += m;
	outfile << money;
	outfile.close();
}
void Money::outmoney() {
	outfile.open("totalmoney.txt", fstream::trunc);
	int m;
	int count = 0;
	string temp[100];
	cout << "지출금액을 입력하시오.   ";
	cin >> m;
	money -= m;
	outfile << money;
	outfile.close();

	cout << "지출내용을 입력하시오.   ";
	cin >> content;
	infile.open("outmoney.txt");

	while (!infile.eof()) {
		getline(infile, temp[count]);
		count++;
	}
	infile.close();

	outfile.open("outmoney.txt", fstream::app);
	if (count > 100) {
		for (int i = 1; i < count; i++) {
			outfile << temp[i]<<" ";
		}
	}
	outfile << "\n" << m << " " << content;
	outfile.close();
}
void Money::checkoutcontent() {
	infile.open("outmoney.txt");
	string tempm, tempc;
	cout << "※지출내용은 100건 까지 기록합니다." << endl;
	while (!infile.eof()) {
		//getline(infile, temp);
		//cout << temp << endl;
		infile >> tempm >> tempc;
		cout << tempc << " \t" << tempm << "원\n";
	}
	infile.close();
}
void Money::print() {
	cout << "현재 잔액 : " << money <<" 원"<< endl;
}