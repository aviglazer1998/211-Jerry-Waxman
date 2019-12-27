#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c, int n){
	int row = 0, col = 0;
	int row1 = q[c] / n;           
	int col1 = q[c] % n;           

	for (int i = 0; i < c; i++){
		row = q[i] / n;                  
		col = q[i] % n;                  

		if (abs(row1 - row) == abs(col1 - col))
			return false;
	}
	return true;
}

int main(){

	int n = 0, k = 0;

	cout << "Enter a value of n: ";
	cin >> n;                               

	int num = 0;                             

	while (n != -1){                         

		cout << "Enter a value of k: ";      
		cin >> k;

		int* q = new int[k], c = 0;        
		q[c] = 0;                          

		c++;

		while (c >= 0){                    
			if (c >= k) {                  
				num++;

				c--;                       
			}

			else
				q[c] = q[c - 1];               

			while (c >= 0 && c < k){

				q[c]++;                

				if (q[c] == (n * n))           
					c--;

				else
					if (ok(q, c, n)) {    

						c++;
						break;
					}
			}
		}

		cout << "Number of solutions: " << num;    

		num = 0;                                   

		delete q;                                  
		cout << endl<<  "Enter value of n: ";         
		cin >> n;
	}
}