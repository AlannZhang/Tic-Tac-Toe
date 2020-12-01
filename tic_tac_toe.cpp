//  Project: Tic Tac Toe Game
//  Purpose: To let two players play tic tac toe

//
/* The test scenarios that were tested
 1. Getting player 1/2 to fill out an entire row to win
 2. Getting player 1/2 to fill out an entire column to win
 3. Getting player 1/2 to fill out the entire left diagonal section to win
 4. Getting player 1/2 to fill out the entire right diagonal section to win
*/

#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

void board_of_game(string game_board[4][4]);
//Purpose: To create a board for the tic tac toe game
//Input: game_board - array numbers that the users will choose
//Output: the game_board array numbers to display the tic tac toe numbers and board

void game_configuration(string (&game_board)[4][4], int &p1_score, int &p2_score, int &num_ties);
//Purpose: To change the number chosen by an X or and O depending on the player
//Input: player (player 1 and 2), user_entry (number chosen, user enters it), i (to check winner), mark (to mark the board with an 'X' or an 'O')
//Output: To ask player which number they want to choose, to say if it's a valid move, and to say who wins or if it's a draw.

bool row_win(string game_board[4][4]);
//Purpose: To check if a player has filled out an entire row
//Input: Array of the game board
//Output: A boolean value of true or false, if the player has filled out the row or not filled out the row

bool column_win(string game_board[4][4]);
//Purpose: To check if a player has filled out an entire column
//Input: Array of the game board
//Output: A boolean value of true or false, if the player has filled out the column or not filled out the column

bool diag_left_win(string game_board[4][4]);
//Purpose: To check if a player has filled out the left diagonal
//Input: Array of the game board
//Output: A boolean value of true or false, if the player has filled out the diagonal or not filled out the diagonal

bool diag_right_win(string game_board[4][4]);
//Purpose: To check if a player has filled out the right diagonal
//Input: Array of the game board
//Output: A boolean value of true or false, if the player has filled out the diagonal or not filled out the diagonal

bool check_win(string game_board[4][4]);
//Purpose: To check if a player has won a game
//Input: Array of the game board, row_win, column_win, diag_left_win and diag_right_win
//Output: A boolean value of true or false, if the player has won the game through one of the 3 methods

bool check_fill(string game_board[4][4]);
//Purpose: To check if the gameboard has been completely filled
//Input: Array of the game board
//Output: A boolean value of true or false

bool check_if_tie(string game_board[4][4]);
//Purpose: To check if the game is a tie
//Input: Array of the game board, check_win and check_fill
//Output: A boolean value of true or false, if the game ends up being a tie

void reset_board(string (&game_board)[4][4]);
//Purpose: To reset the game board to original state if players want to replay
//Input: Array of the game board
//Output: Pass by reference to the game_board array

void board_of_game(string game_board[4][4]) {
//All of this is for the format of the table, so that the numbers are organized when being displayed
    cout << endl << endl << "\tTic Tac Toe" << endl << endl;

    cout << "Player 1 (uses 'X') - Player 2 (uses 'O')" << endl << endl;
    cout << endl;

    cout << "     |     |     |     " << endl;
    cout << "  " << game_board[0][0] << "  |   " << game_board[0][1] << " |   " << game_board[0][2] << " |   " << game_board[0][3] << endl;

    cout << "_____|_____|_____|_____" << endl;
    cout << "     |     |     |     " << endl;

    cout << "  " << game_board[1][0] << "  |   " << game_board[1][1] << " |   " << game_board[1][2] << " |   " << game_board[1][3] << endl;

    cout << "_____|_____|_____|_____" << endl;
    cout << "     |     |     |     " << endl;

    cout << "  " << game_board[2][0] << "  |   " << game_board[2][1] << "|  " << game_board[2][2] << " |  " << game_board[2][3] << endl;
    
    cout << "_____|_____|_____|_____" << endl;
    cout << "     |     |     |     " << endl;
    
    cout << "  " << game_board[3][0] << " |  " << game_board[3][1] << " |  " << game_board[3][2] << " |  " << game_board[3][3] << endl;

    cout << "     |     |     |     " << endl << endl;
}

void game_configuration(string (&game_board)[4][4], int &p1_score, int &p2_score, int&num_ties) {
    //declare and initialize variables
    int player = 1;
    int user_entry;
    char continue_game = '\0';
    string mark;
    
    //do-while loop to check what the number the user enters corresponds to in the table and to change the mark to a 'X' or 'O'
    do {
        player = (player % 2) ? 1 : 2;
        
        cout << "Player " << player << ", enter your desired location:  ";
        cin >> user_entry;
        
        //The mark is 'X' or 'O' depending on the player
        mark = (player == 1) ? "X" : "O";
        
        //when the user entry matches a number in the board of the game, mark it with 'X' or 'O'
        if (user_entry == 1 && strcmp(game_board[0][0].c_str(), "1") == 0)
            game_board[0][0] = mark;

        else if (user_entry == 2 && strcmp(game_board[0][1].c_str(), "2") == 0)
            game_board[0][1] = mark;
    
        else if (user_entry == 3 && strcmp(game_board[0][2].c_str(), "3") == 0)
            game_board[0][2] = mark;
    
        else if (user_entry == 4 && strcmp(game_board[0][3].c_str(), "4") == 0)
            game_board[0][3] = mark;
    
        else if (user_entry == 5 && strcmp(game_board[1][0].c_str(), "5") == 0)
            game_board[1][0] = mark;
    
        else if (user_entry == 6 && strcmp(game_board[1][1].c_str(), "6") == 0)
            game_board[1][1] = mark;
    
        else if (user_entry == 7 && strcmp(game_board[1][2].c_str(), "7") == 0)
            game_board[1][2] = mark;
    
        else if (user_entry == 8 && strcmp(game_board[1][3].c_str(), "8") == 0)
            game_board[1][3] = mark;
    
        else if (user_entry == 9 && strcmp(game_board[2][0].c_str(), "9") == 0)
            game_board[2][0] = mark;
    
        else if (user_entry == 10 && strcmp(game_board[2][1].c_str(), "10") == 0)
            game_board[2][1] = mark;
    
        else if (user_entry == 11 && strcmp(game_board[2][2].c_str(), "11") == 0)
            game_board[2][2] = mark;
    
        else if (user_entry == 12 && strcmp(game_board[2][3].c_str(), "12") == 0)
            game_board[2][3] = mark;
    
        else if (user_entry == 13 && strcmp(game_board[3][0].c_str(), "13") == 0)
            game_board[3][0] = mark;
    
        else if (user_entry == 14 && strcmp(game_board[3][1].c_str(), "14") == 0)
            game_board[3][1] = mark;
        
        else if (user_entry == 15 && strcmp(game_board[3][2].c_str(), "15") == 0)
            game_board[3][2] = mark;
        
        else if (user_entry == 16 && strcmp(game_board[3][3].c_str(), "16") == 0)
            game_board[3][3] = mark;
    
        //if their entered value doesn't correspond to a value in the board, or if it's already taken, output that it's an invalid move. (may have to press enter for it to ask again)
        else {
            cout << "That is an invalid move \n";
            //decrement player so it may choose again
            player--;
            cin.ignore();
            cin.get();
        }
        
        board_of_game(game_board);
        
        //checks whether a player win has won from the check_win function
        if(check_win(game_board) == true) {
            cout<<"Player "<< player <<" wins." << "\n";
            
            if (player == 1) {
                p1_score++;
                printf("Player 1 has %i wins. \n", p1_score);
                printf("Player 2 has %i wins. \n", p2_score);
                printf("The number of ties is %i. \n", num_ties);
            }
            else if (player == 2) {
                p2_score++;
                printf("Player 1 has %i wins. \n", p1_score);
                printf("Player 2 has %i wins. \n", p2_score);
                printf("The number of ties is %i. \n", num_ties);
            }
            
            do {
                cout<<"Do you want to play again? Enter Y for yes and N for no: ";
                cin >> continue_game;
            }
            while (continue_game != 'N' && continue_game != 'Y');
        }
        
        //checks if the game is a tie from the check tie function
        if (check_if_tie(game_board) == true) {
            num_ties++;
            printf("The game is a draw \n");
            printf("Player 1 has %i wins. \n", p1_score);
            printf("Player 2 has %i wins. \n", p2_score);
            printf("The number of ties is %i. \n", num_ties);
            
            do {
                cout<<"Do you want to play again? Enter Y for yes and N for no: ";
                cin >> continue_game;
            }
            while (continue_game != 'N' && continue_game != 'Y');
        }

        if (continue_game == 'N') {
            exit(0);
        }
        else if (continue_game == 'Y') {
            reset_board(game_board);
            continue_game = 'A';
            board_of_game(game_board);
        }

        player++;
    } while (check_win(game_board) != true);
    
    //the player's order switches after each game
    if (continue_game == 'Y' && player == 1) {
        player = 2;
    }
    else if (continue_game == 'Y' && player == 2) {
        player = 1;
    }
    if (continue_game == 'Y' && player == 1 && check_if_tie(game_board) == true) {
        player = 2;
    }
    else if (continue_game == 'Y' && player == 2 && check_if_tie(game_board) == true) {
        player = 1; 
    }
}

bool row_win(string game_board[4][4]) {
    bool win = true;
    string temp_row;
    
    //Nested for loop to check if subsequent elements in a row are the same to a temporary value set to the first element of each row
    for (int pos = 0; pos < 4; pos++) {
        temp_row = game_board[pos][0];
        
        for (int pos1 = 1; pos1 < 4; pos1++) {
            if (temp_row != game_board[pos][pos1]) {
                win = false;
                break;
            }
        }
        if (win == true || pos == 3) {
            break;
        }
        
        win = true;
    }
    return win;
}

bool column_win(string game_board[4][4]) {
    bool win = true;
    string temp_column;
    
    //Nested for loop to check if subsequent elements in a column are the same to a temporary value set to the first element of each column
    for (int pos = 0; pos < 4; pos++) {
        temp_column = game_board[0][pos];
        
        for (int pos1 = 1; pos1 < 4; pos1++) {
            if (temp_column != game_board[pos1][pos]) {
                win = false;
                break;
            }
        }
        if (win == true || pos == 3) {
            break;
        }
        
        win = true;
    }
    return win;
}

bool diag_left_win(string game_board[4][4]) {
    bool win = true;
    string temp_diag = game_board[0][0];
    
    //for loop to check if elements in the diagonal starting from the top left are the same
    for (int pos = 1; pos < 4; pos++) {
        if (temp_diag != game_board[pos][pos]) {
            win = false;
            break;
        }
    }
    return win;
}

bool diag_right_win(string game_board[4][4]) {
    bool win = true;
    int pos1 = 2;
    string temp_diag = game_board[0][3];
    
    //for loop to check if elements in the diagonal starting from the top right are true, compares against th first element in the diagonal
    for (int pos = 1; pos < 4; pos++) {
        if (temp_diag != game_board[pos][pos1]) {
            win = false;
            break;
        }
        
        pos1--;
    }
        
    return win;
}

bool check_win(string game_board[4][4]) {
    //returns a true or false value from the row, column, and diagonal function to indicate whether or not a player has won
    return row_win(game_board) || column_win(game_board) || diag_left_win(game_board) || diag_right_win(game_board);
}

bool check_fill(string game_board[4][4]) {
    //nested for loop to check whether or not there is a X or O in each location
    for (int pos = 0; pos < 4; pos++) {
        for (int pos1 = 0; pos1 < 4; pos1++) {
            if (game_board[pos][pos1] != "X" && game_board[pos][pos1] != "O") {
                return false;
            }
        }
    }
    return true;
}

bool check_if_tie(string game_board[4][4]) {
    //returns a true value if check win is false and check_fill is true, returns a false value if check win is true
    return !check_win(game_board) && check_fill(game_board);
}

void reset_board(string (&game_board)[4][4]) {
    int n = 1;
    
    //nested for loop to fill the original board array with original elements through pass by reference
    for (int pos = 0; pos < 4; pos++) {
        for (int pos1 = 0; pos1 < 4; pos1++) {
            game_board[pos][pos1] = to_string(n);
            n++;
        }
    }
}

int main() {
    //creating an array that stores the values in the board for the game
    string game_board[4][4] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"};
    //local score tracking variables
    int p1_score = 0;
    int p2_score = 0;
    int num_ties = 0;
    
    //function declarations and pass through from gameboard, and variables
    board_of_game(game_board);
    game_configuration(game_board, p1_score, p2_score, num_ties);
    check_win(game_board);
}
