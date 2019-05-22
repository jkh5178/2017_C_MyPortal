#include "schedule.h"

schedule::schedule() {
	infile.open("db2.txt");
	while (!infile.eof())
	{
		infile >> d[donum].name >> d[donum].time;
		donum++;
	}

	infile.close();
}

void schedule::show() {
	cout << "��������(yyyy/mm/dd) : " << "����� " << endl;
	for (int i = 0; i < donum; i++) {
		cout << "���� : " << d[i].time << "\t����� : " << d[i].name << endl;
	}
}
void schedule::inschedile() {
	outfile.open("db2.txt", fstream::app);
	string inname, intime;
	cout << "--�������� �߰�--\n";
	cout << "����(�����)�� �Է��Ͻÿ�.   ";
	cin >> inname;
	cout << "������ �Է��Ͻÿ�.(����:yyyymmdd  ex)20170512 )   ";
	cin >> intime;

	cout << inname << intime;
	outfile << "\n" << inname << " " << intime;
	outfile.close();
	infile.open("db2.txt");
	donum = 0;
	while (!infile.eof())
	{
		infile >> d[donum].name >> d[donum].time;
		donum++;
	}
	infile.close();
}
void schedule::removedata() {
	int removeline;
	schedule::show();
	cout << "--�������� ����--\n";
	cout << "���° �����͸� ����ڽ��ϱ�?";
	cin >> removeline;
	outfile.open("db2.txt");
	for (int i = removeline; i < donum; i++) {
		d[i - 1].name = d[i].name;
		d[i - 1].time = d[i].time;
	}
	donum--;
	for (int i = 0; i < donum; i++) {
		outfile << "\n" << d[i].name << " " << d[i].time;
	}
	outfile.close();
}