#include <iostream>
using namespace std;

bool ok(int q[], int col){

	int mp[3][3] = { 0,2,1,
					 0,2,1,
					 1,2,0 };

	int wp[3][3] = { 2,1,0,
					 0,1,2,
					 2,0,1 };

	int nm = col;
	int nw = q[col];

	for (int i = 0; i < col; ++i) {
		int cm = i;
		int cw = q[i]; 

		if (cw == nw) 
			return false;
		if ((mp[cm][nw] < mp[cm][cw]) && (wp[nw][cm] < wp[nw][nm])) 
			return false;
		if ((mp[nm][cw] < mp[nm][nw]) && (wp[cw][nm] < wp[cw][cm])) 
			return false;
	}
	return true;
}

void backtrack(int& col){
	col--;

	if (col == -1){
		system("PAUSE");
		exit(1);
	}
}

void print(int q[]){
	static int count = 0;

	cout << "Solution number " <<  ++count << ":" << endl;
	
	for (int i = 0; i < 3; i++)
		cout << q[i] << " ";
	cout << endl << endl;
}

int main(){
	int c = 1, n = 3;

	int q[3];
	 q[0] = 0;

	bool from_backtrack = false;

	while (true) {
		while (c < n) {
			if (!from_backtrack)q[c] = -1;
				from_backtrack = true;

			while (q[c] < n){
				q[c]++;
					
				if (q[c] == n){

					from_backtrack = true;
					backtrack(c);
					break;
				}

				if (ok(q, c)){
					from_backtrack = false;
						c++;
							break;
				}
			}
		}
		print(q);
		from_backtrack = true;
		backtrack(c);
	}
}