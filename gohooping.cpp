/******************************************************
** Program: gohooping.cpp
** Author: Kaelee Duong
** Date: 1/28/2024
** Description: simulates a 2-player basketball shooting game in which each player
                gets 5 racks to shoot from with one being a "money rack" which has
                balls that are worth more points.
** Input: money rack position and shooting ability for both players, and whether the
          players would like to play again
** Output: The shooting results as well as the points per rack and total points for 
           both players, and who wins the game  
******************************************************/


#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


/*********************************************************************
** Function: collect_rack
** Description: asks the user for what rack they would like to be the "money rack"
** Parameters: an integer that determines which player's turn it is
** Pre-Conditions: current player is determined
** Post-Conditions: returns the integer of the rack the player wants as their money rack
*********************************************************************/
int collect_rack(int player) {
    int r = 0;

    cout << endl;

    /* if this is the first player, print a welcome statement */
    if (player == 1) {
        cout << "Welcome to the basketball game!" << endl;
        cout << endl;
    }

    cout << "Player " << player << " choose which rack is your money rack (1-5, inclusive): ";
    cin >> r;

    /* check to make sure user input is between 1 and 5 inclusive and reprompt user if not*/
    while (r < 1 || r > 5) {
        cout << "That is not a good value. Please enter a number between 1 and 5 inclusive: ";
        cin >> r;
    }

    /* return the rack - 1 as array indexes start from zero rather than 1*/
    return r-1;
}


/*********************************************************************
** Function: collect_shooting_ability
** Description: asks user for what their shooting ability is 
** Parameters: an integer determining which player's turn it is
** Pre-Conditions: current player has been determined
** Post-Conditions: returns an integer that is the users shooting ability
*********************************************************************/
int collect_shooting_ability(int player) {
    int s = 0; 

    cout << endl;

    cout << "Player " << player << " enter your shooting ability (1-99, inclusive): ";
    cin >> s;

    /* check to make sure user input is between 1 and 99 inclusive and reprompt user if not */
    while (s < 1 || s > 99) {
        cout << "That is not a good value. Please enter a number between 1 and 99 inclusive: ";
        cin >> s;
    } 

    cout << endl; 

    return s;   
}


/*********************************************************************
** Function: print_rack
** Description: prints the shooting results of a single rack and the total points 
                of the rack
** Parameters: an integer for which rack is being printed, the 2d string array that 
               the shooting results are stored in, and the points for the rack.
** Pre-Conditions: all balls on the current rack have already been shot
** Post-Conditions: N/A
*********************************************************************/
void print_rack(int rack, string shot[5][5], int points) {
    string row;

    /* filters through one specified row of the shooting results array and appends ]
       them to create one string */
    for (int i = 0; i < 5; i++) {
         row.append(shot[rack][i]);
         row.append(" ");
    }

    rack++;

    cout << "Rack " << rack << ": " << row << " | " << points << " pts" << endl;
    
}


/*********************************************************************
** Function: player_shots
** Description: based on user inputs, populates an array with the results from shooting, 
                prints each rack results, and the current players total points
** Parameters: a 2D string array for holding the shooting results, and integer for the 
                 player'sdesired money rack, an integer for player's shooting ability, 
                 and the address of the integer variable storing total points
** Pre-Conditions: the player's money rack and shooting ability have been collected
** Post-Conditions: the 2D array that was populated remains the same and the total points 
                    are stored.
*********************************************************************/
void player_shots(string shots[5][5], int r, int s, int &p) {
    int shot = 0;

    /* filters through each row (or rack) of the array */
    for (int i = 0; i < 5; i++) {

        int rowpoints = 0;

        /* filters through each ball on a rack */
        for (int j = 0; j < 5; j++) {
            shot = (rand() % 100) + 1;

            /* checks based on user shooting ability if the shot would be made or not */
            if (shot > s) {
                shots[i][j] = "X";
            }
            else {
                /* checks if the rack is the user's money rack or if it is the last ball on the 
                   rack to determine whether the ball is worth more points or not */
                if (i == r || j == 4) {
                   shots[i][j] = "M"; 
                   rowpoints += 2;
                }
                else {
                    shots[i][j] = "O";
                    rowpoints++;
                }
            }    
        }

        /* adds the rack points to the total points */
        p += rowpoints;

        print_rack(i, shots, rowpoints);
        
    } 

    cout << endl;

    cout << "Total Points: " << p << endl;
}


/*********************************************************************
** Function: determine_winner
** Description: determines the winner between two players and prints the winner or 
                if it is a tie game
** Parameters: two integers representing total points for player 1 and player 2
               respectively
** Pre-Conditions: both players have already shot and their total points have
                   been calculated
** Post-Conditions: N/A
*********************************************************************/
void determine_winner(int player1, int player2) {
    /* check whether player 1 or player 2 has more points or if it is a tie and print a
      message accordingly */
    if (player1 > player2) {
        cout << endl;
        cout << "Player 1 Wins!" << endl;
        cout << endl;
    }
    else if (player2 > player1) {
        cout << endl;
        cout << "Player 2 Wins!" << endl;
        cout << endl;
    }
    else {
        cout << endl;
        cout << "It is a tie game." << endl;
        cout << endl;
    }
}


/*********************************************************************
** Function: restart
** Description: collects whether or not the user would like to play again 
** Parameters: None
** Pre-Conditions: the basketball game has been completed
** Post-Conditions: returns an integer 0 if they player wants to quit and 1 otherwise
*********************************************************************/
int restart() {
    int play = 0;

    cout << "Do you want to play again? (1 - play again or 0 - quit): ";
    cin >> play;

    /* checks if the user input is either 1 or 0 and reprompt user if not */
    while (play != 1 && play != 0) {
        cout << "That is not a good value. Please enter either 1 to play again or 0 to quit: ";
        cin >> play;
    }

    if (play == 1) {
        return 1;
    }
    else {
        cout << endl;
        cout << "Thank you for playing!" << endl;
        return 0;
    }
}


/*********************************************************************
** Function: main
** Description: runs the basketball game program
** Parameters: None
** Pre-Conditions: all functions used to perform the game exist and work correctly
** Post-Conditions: the game has run and exited smoothly if user desires to.
*********************************************************************/
int main() {
    int play = 1;

    srand(time(NULL));

    /* game continues to loop until play is not 1 */
    do {
        /* declare variables */
        int player = 1;
        int player1_points = 0;
        int player2_points = 0;

        string player1shots[5][5];
        string player2shots[5][5];

        /* collect user input and allow game to be played till both players have had a turn */
        while (player <= 2) {
            int moneyrack = 0;
            int shooting_ability = 0;
            int points = 0;

            moneyrack = collect_rack(player);
            shooting_ability = collect_shooting_ability(player);

            if (player == 1) {
                player_shots(player1shots, moneyrack, shooting_ability, points);
                player1_points = points;
            } else {
                player_shots(player2shots, moneyrack, shooting_ability, points);
                player2_points = points;
            }
            
            player++;
        }
    
    /* determine the result of the game based on both player's total points */
    determine_winner(player1_points, player2_points);

    /* ask players if they want to play again and set play equal to the value returned */
    play = restart();

    } while (play == 1);
    
    return 0;
}