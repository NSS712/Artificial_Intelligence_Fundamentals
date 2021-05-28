#include <iostream>
using namespace std;

class Gra
{
public:
	Gra() {
		read();
		value = getValue();
		
	}
	Gra(int a[][3],int index) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				sta[i][j]=a[i][j];
			}
		}
		father = index;
	}
	~Gra() {

	}
	int spread = 0;
	int value = 9999;
	int sta[3][3];
	int father=0;	
	int getValue() {
		int a = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (sta[i][j] == 0)continue;
				if (sta[i][j] <= 4) {
					a += ((sta[i][j] - 1) / 3) > i ? ((sta[i][j] - 1) / 3 - i) : (i - (sta[i][j] - 1) / 3);
					a += ((sta[i][j] - 1) % 3) > j ? ((sta[i][j] - 1) % 3 - j) : (j - (sta[i][j] - 1) % 3);
				}
				else if (sta[i][j] >= 5) {
					a += ((sta[i][j] ) / 3) > i ? ((sta[i][j] ) / 3 - i) : (i - (sta[i][j]) / 3);
					a += ((sta[i][j]) % 3) > j ? ((sta[i][j] ) % 3 - j) : (j - (sta[i][j]) % 3);
				}
			}
		}
		return a;
	}
	void read() {
		cout << "请输入初始状态:(数字0-8,用空格分隔 eg:1 3 6 7 8 2 0 4 5)\n";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> sta[i][j];
			}
		}
	}
	void show() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout<< sta[i][j]<<" ";
			}
			cout << endl;
		}
	}
};
