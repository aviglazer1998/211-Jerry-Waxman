#include<iostream>
#include<cmath>
using namespace std;

bool ok(int b[], int c) {

	int a[][5] = { 

		{-1,-1,-1,-1,-1},
		{0,-1,-1,-1,-1},
		{0,1,-1,-1,-1},
		{0,2,-1,-1,-1},
		{1,2,-1,-1,-1},
		{1,2,3,4,-1},
		{2,3,5,-1,-1},
		{4,5,6,-1,-1} 
	};

	for (int a = 0; a < c; a++)
		if (b[c] == b[a])
			return false;

	for (int i = 0; a[c][i] != -1; i++)
		if (abs(b[c] - b[a[c][i]]) == 1)
			return false;

	return true;
}

void print(int b[]) {

	static int count = 0;
	count++;

	cout << "solution#" << count << ":" << endl;

	for (int i = 0; i < 8; i++)
		cout << b[i] << " ";

	cout << endl << endl;
}

void move(int b[], int c) {

	if (c == 8) {

		print(b);
		return;
	}

	for (int n = 1; n <= 8; n++) {

		b[c] = n;

		if (ok(b, c)) {
			move(b, c + 1);
		}
	}
	return;
}

int main() {

	int b[8];
	move(b, 0);

	system("pause");
	return 0;
}