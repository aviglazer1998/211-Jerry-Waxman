#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int board[8][8] = { 0 }, row, col = 0, count = 1;
	board[0][0] = 1;

NC:
	col++;
	if (col == 8)
		goto print;
	row = -1;

NR:
	row++;
	if (row == 8) {
		goto Backtrack;
	}
	for (int i = 0; i < col; i++) {
		if (board[row][i] == 1) {
			goto NR;
		}
	}
	for (int i = 1; row - i >= 0 && col - i >= 0; i++) {
		if (board[row - i][col - i] == 1) {
			goto NR;
		}
	}
	for (int i = 1; row + i < 8 && col - i >= 0; i++) {
		if (board[row + i][col - i] == 1) {
			goto NR;
		}
	}

	board[row][col] = 1;
	goto NC;

Backtrack:
	col--;
	if (col == -1) {
		system("pause");
		return 0;
	}
	row = 0;

	while (board[row][col] != 1) {
		row++;
	}
	board[row][col] = 0;
	goto NR;

print:
	cout << "Solution # " << count << endl;
	for (int c = 0; c < 8; c++) {
		for (int r = 0; r < 8; r++) {
			cout << board[r][c] << " ";
		}
		cout << endl;
	}
	count++;
	goto Backtrack;
}