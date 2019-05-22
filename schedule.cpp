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
	cout << "기한형식(yyyy/mm/dd) : " << "과목명 " << endl;
	for (int i = 0; i < donum; i++) {
		cout << "기한 : " << d[i].time << "\t과목명 : " << d[i].name << endl;
	}
}
void schedule::inschedile() {
	outfile.open("db2.txt", fstream::app);
	string inname, intime;
	cout << "--보고서제출 추가--\n";
	cout << "제목(과목명)을 입력하시오.   ";
	cin >> inname;
	cout << "기한을 입력하시오.(형식:yyyymmdd  ex)20170512 )   ";
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
	cout << "--보고서제출 삭제--\n";
	cout << "몇번째 데이터를 지우겠습니까?";
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