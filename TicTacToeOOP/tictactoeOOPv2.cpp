#include <bits/stdc++.h>
using namespace std;
// Original code from: https://github.com/Hrittik16/TicTacToe.git

/*
 *	Structure of the game
 *	Class TicTacToe : 
 *		f1 - BuildGrid
 *		f2 - PrintGrid
 *		f3 - CheckValid
 *		f4 - Update
 *		f5 - Choice
 *		f6 - Check
 */

class TicTacToe {
public:
	static int count;
	char choice;
	char win;
	bool isTrue;
	char grid[3][3];
	void BuildGrid();
	void PrintGrid();
	bool CheckValid(char);
	void Update(char, int);
	void Choice();
	char Check();

};

// BuildGrid function builds the grid with number from 1 to 9
void TicTacToe::BuildGrid() {
	int k = 1;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			grid[i][j] = (char)k + '0';
			k++;
		}
	}
}

// PrintGrid function prints the grid as a 3x3 matrix
void TicTacToe::PrintGrid() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cout << " " << grid[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

// CheckValid function takes a character as argument and checks whether it is 
// valid or invalid. A valid choice is made when the number chosen is between
// 1 and 9 and this choice has not been make before
bool TicTacToe::CheckValid(char choice) {
	int temp_count = 0;
	if(choice < '1' || choice > '9') return false;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			temp_count++;
			if((char)temp_count+'0' == choice) {
				if(grid[i][j] != 'x' && grid[i][j] != '0')
					return true;
				else return false;
			}
		}
	}
	return false;
}

// Update function updates the grid with the valid choice made by the user
void TicTacToe::Update(char choice, int player) {
	int temp_count = 0, flag = 0;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			temp_count++;
			if((char)temp_count+'0' == choice) {
				if(player == 1) grid[i][j] = 'x';
				else grid[i][j] = '0';
				flag = 1;
				break;
			}
		}
		if(flag == 1) break;
	}
}

// Choice function takes user input from two players on alternate basis
void TicTacToe::Choice() {
	if(count%2 == 0) {
		cout << "Player 1 : ";
		cin >> choice;
		isTrue = CheckValid(choice);
		//cout << "isTrue = " << isTrue << "\n";
		if(isTrue == true) {
			Update(choice, 1);
			count++;
		}
		else Choice();
	}
	else {
		cout << "Player 2 : ";
		cin >> choice;
		isTrue = CheckValid(choice);
		//cout << "isTrue = " << isTrue << "\n";
		if(isTrue == true) {
			Update(choice, 2);
			count++;
		}
		else Choice();
	}
}

// Check function checks whether any player won the game or the
// game is a draw
char TicTacToe::Check() {
	win = 'c';
	// player 1 (horizontal)
	if(grid[0][0] == 'x' && grid[0][1] == 'x' && grid[0][2] == 'x') 
		win = '1';
	else if(grid[1][0] == 'x' && grid[1][1] == 'x' && grid[1][2] == 'x')
		win = '1';
	else if(grid[2][0] == 'x' && grid[2][1] == 'x' && grid[2][2] == 'x')
		win = '1';
	// player 1 (vertical)
	if(grid[0][0] == 'x' && grid[1][0] == 'x' && grid[2][0] == 'x')
                win = '1';
        else if(grid[0][1] == 'x' && grid[1][1] == 'x' && grid[2][1] == 'x')
                win = '1';
        else if(grid[0][2] == 'x' && grid[1][2] == 'x' && grid[2][2] == 'x')
                win = '1';
	// player 1 (left diagonal) 
	if(grid[0][0] == 'x' && grid[1][1] == 'x' && grid[2][2] == 'x')
		win = '1';
	// player 1 (right diagonal) 
	if(grid[0][2] == 'x' && grid[1][1] == 'x' && grid[2][0] == 'x')
		win = '1';

	// player 2 (horizontal)
        if(grid[0][0] == '0' && grid[0][1] == '0' && grid[0][2] == '0')
                win = '2';
        else if(grid[1][0] == '0' && grid[1][1] == '0' && grid[1][2] == '0')
                win = '2';
        else if(grid[2][0] == '0' && grid[2][1] == '0' && grid[2][2] == '0')
                win = '2';
        // player 1 (vertical)
        if(grid[0][0] == '0' && grid[1][0] == '0' && grid[2][0] == '0')
                win = '2';
        else if(grid[0][1] == '0' && grid[1][1] == '0' && grid[2][1] == '0')
                win = '2';
        else if(grid[0][2] == '0' && grid[1][2] == '0' && grid[2][2] == '0')
                win = '2';
        // player 1 (left diagonal) 
        if(grid[0][0] == '0' && grid[1][1] == '0' && grid[2][2] == '0')
                win = '2';
        // player 1 (right diagonal) 
        if(grid[0][2] == '0' && grid[1][1] == '0' && grid[2][0] == '0')
                win = '2';

	int count_non_digit = 0;
	if(win == 'c') {
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(grid[i][j] >= '1' && grid[i][j] <= '9') {}
				else count_non_digit++;
			}
		}
	}
	if(count_non_digit == 9) win = 'd';
	return win;
}

int TicTacToe::count = 0;

int main() { 
	TicTacToe t1;
	t1.BuildGrid();
	t1.PrintGrid();
	while(1) {
		t1.Choice();
		char win = t1.Check();
		cout << "\n";
		t1.PrintGrid();
		if(win == 'd') {
			cout << "Match Draw\n";
			cout << "\n";
			break;
		}
		else if(win == '1') {
			cout << "Player 1 wins\n";
			cout << "\n";
			break;
		}
		else if(win == '2') {
			cout << "Player 2 wins\n";
			cout << "\n";
			break;
		}
	}
    cin.ignore();           // cin.ignore() and cin.get() serves as a process where user types something but nothing happens, this gives user a sense of transition
    cin.get();
	return 0;

}