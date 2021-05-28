#include <string.h>
#include <iostream>
#include "chess.h"
using namespace std;

int main() {
	Chess a; 
	int turn = 1;
	while (!a.isFull()) {
		if (turn) {
			a.readStep();
			if (a.status() == 1) { 
				cout << "��Ӯ��\n"; 
				break; 
			}
			else if (a.isFull()) {
				cout << "ƽ��!\n";
				break; 
			}
		}
		else {
			a.Search();
			if (a.status() == -1) {
				cout << "������!\n"; 
				break; 
			}
		}
		turn = 1-turn;
	}

	return 0;
}
