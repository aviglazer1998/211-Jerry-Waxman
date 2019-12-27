#include<iostream>
#include<cmath>
using namespace std;

bool ok(int q[], int c) {

	int mp[3][3] = {
		
		{0,2,1},
		{0,2,1},
		{1,2,0} 
	};

	int wp[3][3] = { 
		
		{2,1,0},
		{0,1,2},
		{2,0,1} 
	};

	for (int i = 0; i < c; i++) {
		if (q[i] == q[c])
			return false;

		if ((mp[i][q[c]] < mp[i][q[i]]) && (wp[q[c]][i] < wp[q[c]][c]))
			return false;

		if ((mp[c][q[i]] < mp[c][q[c]]) && (wp[q[i]][c] < wp[q[i]][i]))
			return false;
	}
	return true;
}

void print(int q[]) {

	static int count = 0;
	count++;

	cout << "solution #" << count << ":" << endl << "Man Women" << endl;

	for (int i = 0; i < 3; i++) {
		cout << " " << i << "    " << q[i] << endl;
	}
	cout << endl;
}

void move(int q[], int c) {

	if (c == 3) {
		print(q);
		return;
	}

	for (int j = 0; j < 3; j++) {
		q[c] = j;

		if (ok(q, c)) {
			move(q, c + 1);
		}
	}
	return;
}

int main() {

	int q[8];
	move(q, 0);

	system ("pause");
	return 0;
}