#include "student.h"
Student::Student(string name, string code, ifstream &infile) {//생성자 : 이름과, 학번, 이수과목이있는 텍스트 파일 받아오기
	this->name = name;//이름 저장
	this->code = code;//학번 저장
	while (!infile.eof()) {//파일이 끝날때 까지 실행
		infile >> subject[subjectnum].subjecname >> subject[subjectnum].credit >> subject[subjectnum].devision;
		//구조체 배열에 순서대로 입력(과목이름,학점,구분(전선전필교양,,,))
		//텍스트 파일에는 과목이름 학점 구분 순으로 적혀있어야 한다.
		subjectnum++;//과목배열에 추가할때마다 들은 과목수 1씩 추가
	}
	for (int i = 0; i < subjectnum; i++) {//총들은 과목수를 이용하여 포문 실행
		sumcredit = sumcredit + subject[i].credit;
		if ((subject[i].devision == "교필") || (subject[i].devision == "교선")) {
			sumliberalarts = sumliberalarts + subject[i].credit;
		}
		else if (subject[i].devision == "교직") {
			sumteachingprofession = sumteachingprofession + subject[i].credit;
		}
		else if (subject[i].devision == "전필") {
			maincredit = maincredit + subject[i].credit;
		}
		else if (subject[i].devision == "전선") {
			mainchoosecredit = mainchoosecredit + subject[i].credit;
		}
		//구조체배열을 FOR문으로 돌려 총 들은 학점을 계산하여 클래스 초기화 할때 구해놓음.
		//차후에 이수과목 추가시 학점을 늘려주는 함수제작예정
	}
}
void Student::remainCredit() {//남은 학점 계산
	cout << "-----남은 학점-------" << endl;
	cout << "남은 총 학점 : " << MAXCREDIT - sumcredit << endl;
	cout << "남은 교양 학점 : " << MAXLIBERALARTS - sumliberalarts << endl;
	cout << "남은 교직 학점 : " << MAXTEACHINGPROFESSION - sumteachingprofession << endl;
	cout << "남은 전필 학점 : " << MAXMAINCREDIT - maincredit << endl;
	cout << "남은 전선 학점 : " << MAXMAINCHOOSECREDIT - mainchoosecredit << endl;

}
void Student::PrintInfo() {//기본정보 출력 함수
	cout << "이    름 : " << name << endl;
	cout << "학    번 : " << code << endl;
	cout << "이수 과목 수 : " << subjectnum << endl;
	cout << "이수 총 학점 : " << sumcredit << endl;
}