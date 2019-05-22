#pragma once
#include "standardheader.h"

class Money {
	int money;
	string content;
	ifstream infile;
	ofstream outfile;
public:
	Money();
	void inmoney();
	void outmoney();
	void checkoutcontent();
	void print();
};