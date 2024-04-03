Welcome to the basketball game!
-
This program simulates a basketball shooting game between 2 players,
with each player attempting to score as many points are possible by 
making shots from 5 fixed positions.

At each rack there is a rack of 5 basketballs. Out of the 5 balls,
the first 4 are regular balls worth 1 point each. The 5th ball,
often nicknamed the "money ball", iw worth 2 points.

Of those 5 positions, the player can choose a position to have a rack 
consisting only of money balls which are all worth 2 points. This
position is called the money ball rack.

The goal of the game is to score as many points are possible. The player
with the highest score at the end of the game is the winner. If the 
two players have the same score then it is a tie game.

-------------------------------------------------------------------------

NOTE: this program was compiled using the g++ compiler. If you would like to compile with a different
compiler, you would need to do the compilation yourself with your knowledge.

Instructions:

1) Compile the program with:

        g++ gohooping.cpp -o hooping

2) Run the program with:

        ./hooping
3) The program will first ask which rack the first player would like to
   be the money ball rack, therefore being an integer between 1-5 inclusive.
   If you enter an integer outside this range it will reprompt you for a valid
   input.

   Next, the program will ask the first player what their shooting ability is,
   which is a number between 1-99 inclusive. This number will be the percentage
   that the player makes shots. If you enter an integer outside this range it
   will reprompt you for a valid input.

   After this, the player's results will be printed in this format:
   
        Rack 1: O O O O X  | 4 pts
        Rack 2: O O O O X  | 4 pts
        Rack 3: O O X O M  | 5 pts
        Rack 4: M M M M M  | 10 pts
        Rack 5: O X X O M  | 4 pts
   
        Total Points: 27

   The program will then prompt the second player to go through this entire
   process.

   At the end, the winner or a tie game will be announced.

   The program will then ask you if you would like to play again.
   You will be given the choice between 1 to play again and 0 to quit.
   If you input a number other than these two, the program will reprompt
   you for a valid input.

4) Limitations:
   - only 2 players can play and no more.
   - the program is not equipped with error handling for non integer data types.
   
