#pragma once
#include "standardheader.h"
#include "subject.h"
#include "���.h"


class Student {//�л�Ŭ���� ����
	string name;//�̸�
	string code;//�й�
	Subject subject[MAXSUBJECTNUM];//���� ����ü �迭�� ����
	int subjectnum = 0;//���ݱ��� ���� �����(�迭 �о���� �Ҷ� �ʿ�, �� ����� -1�� ����ɰ��̴�.)
	int sumcredit = 0;//���ݱ����� �� ����
	int sumliberalarts = 0;
	int sumteachingprofession = 0;
	int maincredit = 0;
	int mainchoosecredit = 0;

public:
	Student(string name, string code, ifstream &infile);
	void remainCredit();
	void PrintInfo();
};