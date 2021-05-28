#include <iostream>
#include "gra.cpp"
#include <stack>
#include <queue>
#include <vector>

using namespace std;
vector<Gra> v1;
stack<int> s1;
bool repeat(Gra p) {
	for (int i = 0; i < v1.size(); i++) {
		int same = 1;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (p.sta[j][k] != v1[i].sta[j][k]) {
					same = 0;
					break;
				}
			}
			if (!same)break;
		}
		if (same) return 1;
	}
	return 0;
}
int main() {
	Gra g;
	cout << "³õÊ¼×´Ì¬£º\n";
	g.show();
	v1.push_back(g);
	while (1) {
		int index = 0;
		int minValue = 999;
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i].value < minValue &&v1[i].spread==0) {
				minValue = v1[i].value;
				index = i;
			}
		}
		v1[index].spread = 1;
		if (v1[index].value == 0) {
			while (1) {
				s1.push(index);
				index = v1[s1.top()].father;
				if (index == 0)break;
			}
			break;
		}
		int la[3][3];
		int x0, y0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (v1[index].sta[i][j] == 0) {
					x0 = i;
					y0 = j;
				}
				la[i][j]=v1[index].sta[i][j];
			}
		}
		if (x0 > 0) {
			Gra p = Gra(la, index);
			p.sta[x0 ][y0] = p.sta[x0-1][y0];
			p.sta[x0 - 1][y0] = 0;
			if (!repeat(p)) {
				p.value = p.getValue();
				v1.push_back(p);
			}

		}
		if (x0 < 2) {
			Gra p = Gra(la, index);
			p.sta[x0][y0] = p.sta[x0 + 1][y0];
			p.sta[x0 + 1][y0] = 0;
			if (!repeat(p)) {
				p.value = p.getValue();
				v1.push_back(p);
			}
		}
		if (y0 >0) {
			Gra p = Gra(la, index);
			p.sta[x0][y0] = p.sta[x0][y0-1];
			p.sta[x0][y0-1] = 0;
			if (!repeat(p)) {
				p.value = p.getValue();
				v1.push_back(p);
			}
		}
		if (y0 <2) {
			Gra p = Gra(la, index);
			p.sta[x0][y0] = p.sta[x0][y0 + 1];
			p.sta[x0][y0 + 1] = 0;
			if (!repeat(p)) {
				p.value = p.getValue();
				v1.push_back(p);
			}
		}
	}
	int sp = s1.size();
	for (int i = 0; i < sp; i++) {
		cout << "µÚ" << i + 1 << "²½£º\n";
		v1[(s1.top())].show();
		s1.pop();
	}
}