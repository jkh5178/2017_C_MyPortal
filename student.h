#pragma once
#include "standardheader.h"
#include "subject.h"
#include "상수.h"


class Student {//학생클래스 정의
	string name;//이름
	string code;//학번
	Subject subject[MAXSUBJECTNUM];//과목 구조체 배열로 생성
	int subjectnum = 0;//지금까지 들은 과목수(배열 읽어오기 할때 필요, 총 과목수 -1이 저장될것이다.)
	int sumcredit = 0;//지금까지의 총 학점
	int sumliberalarts = 0;
	int sumteachingprofession = 0;
	int maincredit = 0;
	int mainchoosecredit = 0;

public:
	Student(string name, string code, ifstream &infile);
	void remainCredit();
	void PrintInfo();
};