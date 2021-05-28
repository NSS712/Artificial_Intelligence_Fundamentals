#include <iostream>
#include "chess.h"
using namespace std;


Chess::Chess() {
	memset(A, 0, sizeof(A));
	step = 0;
	this->show();
}
void Chess::show() {
	for (int i = 0; i < 3; i++) {
		char a1 = A[i][0] ? A[i][0] : ' ';
		char a2 = A[i][1] ? A[i][1] : ' ';
		char a3 = A[i][2] ? A[i][2] : ' ';
		cout <<a1 << "|" << a2 << "|" << a3<< "\n";
		if(i<2)
			cout << "------\n";
	}

}
void Chess::readStep() {
	int x, y;
	cout << "第" << ++step << "步 请输入2个 1至3的数字，用空格分隔 ";
	cin >> x >> y;
	x--; y--;
	while (A[x][y] || x > 2 || x < 0 || y>2 || y < 0) {
		cout << "键入格式错误，请输入2个 1至3的数字，用空格分隔 ";
		cin >> x >> y;
		x--;
		y--;
	}
	A[x][y] = 'O';
	this->show();
	cout << endl;
}
void Chess::Search() {
	int x, y, score = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (!A[i][j]) {
				A[i][j] = 'X';
				int temp = Max();
				if (score > temp) x = i, y = j, score = temp;
				A[i][j] = 0;
			}
		}
	}
	A[x][y] = 'X';
	this->show();
}
int Chess::Max() {
	int ret = -1, sta = status();
	if (sta) return sta;
	if (isFull()) return 0;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
		if (!A[i][j]) A[i][j] = 'O', ret = max(ret, Min()), A[i][j] = 0;
	return ret;
}
int Chess::Min() { 
	int ret = 1, sta = status();
	if (sta) return sta;
	if (isFull()) return 0;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
		if (!A[i][j]) A[i][j] = 'X', ret = min(ret, Max()), A[i][j] = 0;
	return ret;
}
bool Chess::isFull() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (!A[i][j]) return false;
	return true;
}

int Chess::status() {
	for (int i = 0; i < 3; i++) 
		if (A[i][0] == 'O' && A[i][1] == 'O' && A[i][2] == 'O') 
			return 1;
	for (int i = 0; i < 3; i++)
		if (A[0][i] == 'O' && A[1][i] == 'O' && A[2][i] == 'O') 
			return 1;
	for (int i = 0; i < 3; i++)  
		if (A[i][0] == 'X' && A[i][1] == 'X' && A[i][2] == 'X') 
			return -1;
	for (int i = 0; i < 3; i++) 
		if (A[0][i] == 'X' && A[1][i] == 'X' && A[2][i] == 'X') 
		return -1;
	if (A[0][0] == 'O' && A[1][1] == 'O' && A[2][2] == 'O') return 1;
	if (A[2][0] == 'O' && A[1][1] == 'O' && A[0][2] == 'O') return 1;
	if (A[0][0] == 'X' && A[1][1] == 'X' && A[2][2] == 'X') return -1;
	if (A[2][0] == 'X' && A[1][1] == 'X' && A[0][2] == 'X') return -1;
	return 0;
}