#pragma once


class Chess {
private:
	char A[3][3];
	int step;
public:
	Chess();
	void show();
	void  readStep();
	void  Search();
	bool isFull();
	int Max();
	int Min();
	int status();
};