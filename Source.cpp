#include <iostream>
#include <cmath>
using namespace std;


int main() {

	int col = 0, board[8], count = 1;
	board[0] = 0;

NC:
	col++;
	if (col == 8)
		goto print;
	board[col] = -1;
NR:
	board[col] ++;
	if (board[col] == 8)
		goto Backtrack;
	for (int i = 0; i < col; i++)
		if (board[i] == board[col] || ((col - i) == abs(board[col] - board[i])))
			goto NR;
	goto NC;

	board[col] = 1;
	goto NR;

Backtrack:
	col--;
	if (col == -1) {
		system("pause");
		return 0;
	}
	goto NR;

print:
	cout << "Solution # " << count << endl;
	for (int r = 0; r < 8; r++) {
		cout << board[r] << " ";
	}

	cout << endl;

	count++;
	goto Backtrack;
}