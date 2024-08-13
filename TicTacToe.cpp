
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <algorithm>

using namespace std;
int sizeGameBoard = 9;
string nextPlayer;
bool winner = false;
// 2d array of char with 3 columns and 3 rows.
char arrVertically[3][3];



int rows = 3;
int columns = 3;
bool gameRunning = false;
char input;

//class Board {

// ide å lage en board classe å lage et nytt objekt for hver gang board oppdateres. Nytt objekt av "Board" klasse med oppdaterte tall.

//}

void arrayInit() {

	arrVertically[0][0] = '0';
	arrVertically[0][1] = '1';
	arrVertically[0][2] = '2';

	arrVertically[1][0] = '3';
	arrVertically[1][1] = '4';
	arrVertically[1][2] = '5';

	arrVertically[2][0] = '6';
	arrVertically[2][1] = '7';
	arrVertically[2][2] = '8';

}

char randomChar(char &machineInp) {

	char letters[] = { '0','1','2','3','4','5','6','7','8'};

	// Seed the random number generator with the current time
	srand(static_cast<unsigned>(time(nullptr)));

	char x = letters[rand() % 9];
	machineInp = x;

	return x;

}
char charInput() {
	char input;
	cin >> input;
	return input;
}

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


bool isMoveLegal(char board[3][3], char input) {

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			while (board[i][j] == input) {
				if (board[i][j] != 'X' || board[i][j] != 'O') return true;
				break;
			}
		}
	}
	return false;
}

void updateTicTacBoard(char input, char mark, char board[3][3]) {
	
	
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (board[i][j] == input) {
					board[i][j] = mark;
				}
			}
		}

		drawBoard();
		
	

}

void instructions() {

	cout << "Welcome to Tic-Tac-Toe game" << endl;
	
	
}
char firstMove() {
	
	char input;
	cout << "\n\nDo you require the first move? (y/n)";
	cin >> input;

	return input;
}
void determineFirstMove(char input) {

	if (input == 'y' || input == 'Y') {
		nextPlayer = "Player";

	}
	else if (input == 'n' || input == 'N') {
		nextPlayer = "Machine";
	}
	else { cout << "unknown"; }

}

void winnerCheck(char board[3][3]) {
	
		string playerWin = "Player wins! ";
		string machineWin = "Machine wins! ";
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++) // kolonne
			{
				// check vertically
				if (board[0][j] == 'X' && board[1][j] == 'X' && board[2][j] == 'X') {
					if (!winner) {
						cout << "\n" << playerWin << endl;
					}
					winner = true;
					
				}
				else if (board[0][j] == 'O' && board[1][j] == 'O' && board[2][j] == 'O') {
					if (!winner) {
						cout << "\n" << machineWin << endl;
					}
					winner = true;

				}

				//check horizontally
				if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') {
					if (!winner) {
						cout << "\n" << playerWin << endl;
					}
					winner = true;

				}
				else if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') {
					if (!winner) {
						cout << "\n" << machineWin << endl;
					}
					winner = true;

				}

				//check diagonally
				if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
					if (!winner) {
						cout << "\n" << playerWin << endl;
					}
					winner = true;

				}
				else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
					if (!winner) {
						cout << "\n" << machineWin << endl;
					}
					winner = true;

				}
				else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
					if (!winner) {
						cout << "\n" << playerWin << endl;
					}
					winner = true;

				}
				else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
					if (!winner) {
						cout << "\n" << machineWin << endl;
					}
					winner = true;

				}
				

			}
		}

	

}

void playerTurn() {
	cout << "\nInput your number between 0-8 which refers to which position you want to set a X/O: ";
	char playerInput = charInput();
	cout << playerInput;

	while (!isMoveLegal(arrVertically, playerInput)) {
		cout << "\nSpace is occupied. Enter new input:  ";
		playerInput = charInput();
		isMoveLegal(arrVertically, playerInput);

	}
	updateTicTacBoard(playerInput, 'X', arrVertically);
	nextPlayer = "Machine";
}

void machineTurn() {
	
	
	
	char machineInput = randomChar(machineInput);
	
	while (!isMoveLegal(arrVertically, machineInput)) {
		
		machineInput = randomChar(machineInput);
	/*	cout << "MACHINE INPUT: " << machineInput;*/
		isMoveLegal(arrVertically, machineInput);

	}
	updateTicTacBoard(machineInput, 'O', arrVertically);

	nextPlayer = "Player";
}



int main()
{
	arrayInit();
	instructions();
	drawBoard();


	//first move
	char input = firstMove();
	determineFirstMove(input);

	
	gameRunning = true;

	// GAME LOOP
	while (gameRunning && !winner) {

		cout << "\nCurrent player: " << nextPlayer;
		winnerCheck(arrVertically);

		if (nextPlayer == "Player") {
			playerTurn();
			
		}
		else if (nextPlayer == "Machine") {
			// make AI later
		
			machineTurn();

		}

		// lag enkel AI
		// fiks randomChar
		//se eksmepåel i programmin c++ bok.


	}
	


}

