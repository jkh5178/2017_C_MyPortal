#include "student.h"
Student::Student(string name, string code, ifstream &infile) {//������ : �̸���, �й�, �̼��������ִ� �ؽ�Ʈ ���� �޾ƿ���
	this->name = name;//�̸� ����
	this->code = code;//�й� ����
	while (!infile.eof()) {//������ ������ ���� ����
		infile >> subject[subjectnum].subjecname >> subject[subjectnum].credit >> subject[subjectnum].devision;
		//����ü �迭�� ������� �Է�(�����̸�,����,����(�������ʱ���,,,))
		//�ؽ�Ʈ ���Ͽ��� �����̸� ���� ���� ������ �����־�� �Ѵ�.
		subjectnum++;//����迭�� �߰��Ҷ����� ���� ����� 1�� �߰�
	}
	for (int i = 0; i < subjectnum; i++) {//�ѵ��� ������� �̿��Ͽ� ���� ����
		sumcredit = sumcredit + subject[i].credit;
		if ((subject[i].devision == "����") || (subject[i].devision == "����")) {
			sumliberalarts = sumliberalarts + subject[i].credit;
		}
		else if (subject[i].devision == "����") {
			sumteachingprofession = sumteachingprofession + subject[i].credit;
		}
		else if (subject[i].devision == "����") {
			maincredit = maincredit + subject[i].credit;
		}
		else if (subject[i].devision == "����") {
			mainchoosecredit = mainchoosecredit + subject[i].credit;
		}
		//����ü�迭�� FOR������ ���� �� ���� ������ ����Ͽ� Ŭ���� �ʱ�ȭ �Ҷ� ���س���.
		//���Ŀ� �̼����� �߰��� ������ �÷��ִ� �Լ����ۿ���
	}
}
void Student::remainCredit() {//���� ���� ���
	cout << "-----���� ����-------" << endl;
	cout << "���� �� ���� : " << MAXCREDIT - sumcredit << endl;
	cout << "���� ���� ���� : " << MAXLIBERALARTS - sumliberalarts << endl;
	cout << "���� ���� ���� : " << MAXTEACHINGPROFESSION - sumteachingprofession << endl;
	cout << "���� ���� ���� : " << MAXMAINCREDIT - maincredit << endl;
	cout << "���� ���� ���� : " << MAXMAINCHOOSECREDIT - mainchoosecredit << endl;

}
void Student::PrintInfo() {//�⺻���� ��� �Լ�
	cout << "��    �� : " << name << endl;
	cout << "��    �� : " << code << endl;
	cout << "�̼� ���� �� : " << subjectnum << endl;
	cout << "�̼� �� ���� : " << sumcredit << endl;
}