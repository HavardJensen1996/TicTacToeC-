
#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;

class Board {

public:

	char arrVertically[3][3];
	int rows = 3;
	int columns = 3;

	Board() {

		arrVertically[0][0] = '0';
		arrVertically[0][1] = '1';
		arrVertically[0][2] = '2';

		arrVertically[1][0] = '3';
		arrVertically[1][1] = '4';
		arrVertically[1][2] = '5';

		arrVertically[2][0] = '6';
		arrVertically[2][1] = '7';
		arrVertically[2][2] = '8';
	


	};

	void drawBoard() {

		for (int i = 0; i < rows; i++) // rad
		{
			cout << "\n";

			for (int j = 0; j < columns; j++) // kolonne
			{
				cout << arrVertically[i][j];

				if (j < 2) {
					cout << " ";
					cout << ":";
					cout << " ";
				}

			}
			if (i < 2) {
				cout << "\n___________";
			}

		}
	}
	


};
