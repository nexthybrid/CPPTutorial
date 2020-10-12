#include <iostream>     // required for file input/output
using namespace std;    // related to how the names of things are processed

// Original code from http://www.cppforschool.com/project/tic-tac-toe-project.html

// character array definition, for game board values.
// variables defined outside any function are global variables.
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

// placeholders for functions with integer output / no output.

int checkwin();
void board();

// main function definition
int main()
{
	int player = 1,i,choice;   // define player in {1,2}, iterator i, and choice, the keyboard keyin variable.

    char mark;
    do
    {
        board();
        player=(player%2)?1:2;                                  // if condition, variable = Condition ? ResultForYes : ResultForNo

        cout << "Player " << player << ", enter a number:  ";   // print instructions
        cin >> choice;                                          // receive keyin

        mark=(player == 1) ? 'X' : 'O';                         // if condition

        if (choice == 1 && square[1] == '1')                    // logic operators come in double signs, AND &&, EQUAL ==, OR ||.　Code logic: if block is not taken, replace it with player mark.

            square[1] = mark;
        else if (choice == 2 && square[2] == '2')

            square[2] = mark;
        else if (choice == 3 && square[3] == '3')

            square[3] = mark;
        else if (choice == 4 && square[4] == '4')

            square[4] = mark;
        else if (choice == 5 && square[5] == '5')

            square[5] = mark;
        else if (choice == 6 && square[6] == '6')

            square[6] = mark;
        else if (choice == 7 && square[7] == '7')

            square[7] = mark;
        else if (choice == 8 && square[8] == '8')

            square[8] = mark;
        else if (choice == 9 && square[9] == '9')

            square[9] = mark;
        else
        {
            cout<<"Invalid move ";  // anything else is considered invalid.

            player--;       // mitigate the player++ command below if move is invalid, let current player reselect choice.
            cin.ignore();   // clear one or more characters from the input buffer.
            cin.get();      // not sure why cin.get() is needed here.
        }
        i=checkwin();       // check game status.

        player++;           // rotate player.
    }while(i==-1);
    board();
    if(i==1)

        cout<<"==>\aPlayer "<<--player<<" win ";
    else
        cout<<"==>\aGame draw";

    cin.ignore();           // cin.ignore() and cin.get() serves as a process where user types something but nothing happens, this gives user a sense of transition
    cin.get();
    return 0;
}

/*********************************************
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
    Required variables: square
**********************************************/

// game status checking function, returns 1 or -1 or 0
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}


/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
     Required variables: square
********************************************************************/


void board()
{
    system("cls");      // clears the terminal for the next drawing
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}

/*******************************************************************
                END OF PROJECT
********************************************************************/