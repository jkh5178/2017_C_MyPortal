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
	cout << "������ �Է��Ͻÿ�.   ";
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
	cout << "����ݾ��� �Է��Ͻÿ�.   ";
	cin >> m;
	money -= m;
	outfile << money;
	outfile.close();

	cout << "���⳻���� �Է��Ͻÿ�.   ";
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
	cout << "�����⳻���� 100�� ���� ����մϴ�." << endl;
	while (!infile.eof()) {
		//getline(infile, temp);
		//cout << temp << endl;
		infile >> tempm >> tempc;
		cout << tempc << " \t" << tempm << "��\n";
	}
	infile.close();
}
void Money::print() {
	cout << "���� �ܾ� : " << money <<" ��"<< endl;
}