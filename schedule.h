#pragma once
#include "standardheader.h"

#define MAXNUM 10

struct date {
	string time;
	string name;
};
class schedule {
	date d[MAXNUM];
	ifstream infile;
	ofstream outfile;
	int donum = 0;

public:
	schedule();
	void show();
	void inschedile();
	void removedata();
};