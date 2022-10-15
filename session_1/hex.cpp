/*
HEX

Problem
----------------------------------------------------------------------
This problem was inspired by a board game called Hex, designed independently by Piet Hein and John Nash. It has a similar idea, but does not assume you have played Hex.

This game is played on an N×N board, where each cell is a hexagon. There are two players: Red side (using red stones) and Blue side (using blue stones). The board starts empty, and the two players take turns placing a stone of their color on a single cell within the overall playing board. Each player can place their stone on any cell not occupied by another stone of any color. There is no requirement that a stone must be placed beside another stone of the same color. The player to start first is determined randomly (with equal probability among the two players).

The upper side and lower sides of the board are marked as red, and the other two sides are marked as blue. For each player, the goal of the game is to connect the two sides marked with their color by forming a connected path using stones of their color. The first player to achieve this wins. Note that the four corners are considered connected to both colors.

The game ends immediately when one player wins.

Given a game state, help someone new to the game determine the status of a game board. Say one of the following:

Impossible: If it was impossible for two players to follow the rules and to have arrived at that game state.
Red wins: If the player playing the red stones has won.
Blue wins: If the player playing the blue stones has won.
Nobody wins: If nobody has yet won the game. Note that a game of Hex cannot end without a winner!
Note that in any impossible state, the only correct answer is Impossible, even if red or blue has formed a connected path of stones linking the opposing sides of the board marked by their colors.

Here is a an example game on a 6×6 gameboard where blue won. Blue was the first player to move, and placed a blue stone at cell marked as 1. Then Red placed at cell 2, then blue at cell 3, etc. After the 11-th stone is placed, blue wins.


Input
-----------------------------------
The first line of input gives the number of test cases, T. T test cases follow. Each test case start with the size of the side of the board, N. This is followed by a board of N rows and N columns consisting of only B, R, and . characters. B indicates a cell occupied by blue stone, R indicates a cell occupied by red stone, and . indicates an empty cell.

Output
-----------------------------------
For each test case, output one line containing Case #x: y, where x is the case number (starting from 1) and y is the status of the game board. It can be "Impossible", "Blue wins", "Red wins", or "Nobody wins" (excluding the quotes). Note that the judge is case-sensitive, so answers of "impossible", "blue wins", "red wins", and "nobody wins" will be judged incorrect.

Limits
------------------------------
Time limit: 30 seconds.

Memory limit: 1 GB.
1≤T≤100.

Test Set 1
1≤N≤10.

Test Set 2
1≤N≤100.

*/


/*  This is the N^4 time complexity solution */

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// int Directions [6][2] = {(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0)}; 

// // void deepcopy(vector<string> & og_board, int N, vector<string> board){
// //     for(int i = 0; i < N; i++){
// //         board.push_back(og_board.at(i));
// //     }
// // }

// char** deepcopy(char ** og_board, int N, char ** new_board){
    
//     for(int i = 0; i < N; i++){
//         new_board[i] = new char[N];
//         for(int j = 0; j < N; j++){
//             new_board[i][j] = og_board[i][j];
//         }
//     }

//     return new_board;
// }

// void flood(char **board, int row, int col, int n, char color ){
//     board[row][col] = tolower(color);
//     for(int i = 0; i < 6; i++){
//         int new_row = row + Directions[i][0];
//         int new_col = col + Directions[i][1];
//         if((new_col >= 0 && new_col < n) && (new_row >= 0 && new_row < n)){
//             if(board[new_row][new_col] == color){
//                    flood(board, new_row, new_col, n, color);
//             }    
//         }
//     }
// }

// char check_winning(char ** board, int N){
//     for(int i = 0; i < N; i++){
//         if(board[i][0] == 'B'){
//             flood(board, i, 0, N,'B');
//         }
//         if(board[0][i] == 'R'){
//             flood(board, 0, i, N, 'R');
//         }
//     }

//     for(int i = 0; i < N; i++){
//         if(board[i][N-1] == 'b'){
//             return 'B';
//         }
//         if(board[N-1][i] == 'r'){
//             return 'R';
//         }
//     }
    
//     return '.';
// }

// string solve(int N){
//     // vector <string> og_board;
//     string row;

//     char** og_board = new char*[N];
//     for(int i = 0; i < N; i++){     
//         cin >> row;
//         og_board[i] = new char[N];
//         for(int j = 0; j < N; j++){
//             og_board[i][j] = row[j];
//             // cout << og_board[i][j] << " ";
//         }
//         // cout << endl;
//     }


//     int b = 0; 
//     int r = 0;

//     // for(int i = 0; i < N; i++){
//     //     cin >> row;
//     //     og_board.push_back(row);
//     //     cout << row <<endl;
//     // }


//     //If the number of b's and r's have a difference greater than 1, impossible
//     for(int i = 0; i < N; i++){
//         for(int j = 0; j < N; j++){
//             if(og_board[i][j] == 'B'){ b++;}
//             else if(og_board[i][j] == 'R'){r++;}
//         }
//     }
    
//     // cout << "countBlues: " << b << "; countReds: " << r << endl;
//     if(abs(b-r) > 1){
//         //if the difference of BLUES and REDS, they did not take proper turns while playing the game 
//         return "Impossible";
//     }
    
//     // vector<string>board;
//     char** board = new char*[N];
//     board = deepcopy(og_board, N, board);
//     char winner = check_winning(board, N);

//     if(winner == '.'){return "Nobody wins";}

//     if((winner == 'B' && b < r) || (winner == 'R' && r < b)){
//         return "Impossible";
//     }

//     for (int i  = 0; i < N; i++){
//         for(int j = 0; j < N; j++){
//             if(og_board[i][j] == winner){
//                 // vector<string> new_board;
//                 // deepcopy(og_board, N, new_board);
                
//                 char ** new_board = new char*[N];
//                 new_board = deepcopy(og_board, N, new_board);
//                 new_board[i][j] = '.';
//                 if(check_winning(new_board, N) == '.'){
//                     if(winner == 'B'){
//                         return "Blue wins";
//                     }
//                     if(winner == 'R'){
//                         return "Red wins";
//                     }
//                 }
//             }
//         }
//     }  

//     return "Impossible";
// }

// int main (){
//     int cases, n;
//     cin >> cases;
//     for(int i = 0; i < cases; i++){
//         cin >> n;
//         cout << "Case #" << i+1 << ": " << solve(n) << endl;
//     }
//     return 0;
// }









#include <iostream>
#include <string>
#include <set>

using namespace std;

void padBoard(char ** og_board, char ** padded_board, int n, char color){
    
    char** padded_board = new char*[n+2];

    for(int i = 0; i < n+2; i++){
        padded_board[i] = new char[n+2];
        for(int j = 0; j < n+2; j++){
            if(i == 0 || i == n+1){
                if(j == 0 || j == n + 1){
                padded_board[i][j] = color;
                }
                else{
                    padded_board[i][j] = 'R';
                }
            }
            else if(i > 0 || i < n+1){
                if(j == 0 || j == n + 1){
                    padded_board[i][j] = 'B';
                }
            }
            else{
                padded_board[i][j] = og_board[i-1][j-1];
            }
        }
    }
}

int Directions [6][2] = {{0, 1}, {-1,1}, {-1,0}, {0,-1}, {1,-1}, {1,0}};

void colorCount(int blueCount, int redCount, int n, char ** board){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'B'){ blueCount++;}
            else if (board[i][j] == 'R'){redCount++;}
        }
    }
}


void step(char ** board, int left [], int right [], char color, int ** results){
    int * nextHex = new int [2];
    int right_dir[2] = {left[0] - right[0], left[1] - right[1]}; 

    for(int i = 0; i < 6; i++){
        if(right_dir[0] == Directions[i][0] && right_dir[1] == Directions[i][1]){
            int * nextDir = Directions[(i+1) % 6];
            nextHex[0] = left[0] + nextDir[0];
            nextHex[1] = left[1] + nextDir[1];
        }
    }
    
    if(board[nextHex[0]][nextHex[1]] == color){
        results[0] = new int[2]; 
        results[0][0] = nextHex[0]; 
        results[0][1] = nextHex[1];
        results[1] = new int[2]; 
        results[1][0] = right[0]; 
        results[1][1] = right[1];
    }
    else{
        results[0] = new int[2]; 
        results[0][0] = right[0]; 
        results[0][1] = right[1];
        results[1] = new int[2]; 
        results[1][0] = nextHex[0]; 
        results[1][1] = nextHex[1];
    }

}

std:: set <int [2]> bluePathFinder(char ** board, int m){
 int right [2] = {m - 1, 0};
 int left [2] = {m - 1, 1};
 
 set <int [2]> path;

 while(left[1] < m - 1){
   // While we haven't reached the right side keep taking steps
   path.insert(left);
   int ** results = new int * [2];
   step(board, left, right, 'B', results);
   left[0] = results[0][0];
   left[1] = results[0][1];
   right[0] = results[1][0];
   right[1] = results[1][1];
   if(right[0] == 0){break;}
 }

 return path;
}


string solve(char ** og_board, int n){
    
    int blueCount, redCount = 0;
    colorCount(blueCount, redCount, n, og_board);
    if(abs(blueCount - redCount > 1)){
        return "Impossible";
    }

    char ** padded_board;
    padBoard(og_board, padded_board,n, 'B');
    

    set <int [2]> bluePath = bluePathFinder(padded_board, n+2);
    set <int [2]> redPath = redPath(padd)

    return "";
}


int main (){
    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++){
        int n = 0;
        cin >> n;
        char** og_board = new char*[n];
        for(int j = 0; j < n; j++){
          string row;
          og_board[j] = new char [n];
          for(int k = 0; k < n; k++){
            og_board[j][k] = row[k];
          }
        }
        cout << "Case #" << i + 1 << ": " << solve(og_board, n) << endl;
    }

    return 0;
}