/*
Problem
John participates in an annual walking competition called Walktober. The competition runs for a total of N days and tracks the daily steps of the participants for all the N days. Each participant will be assigned a unique ID ranging from 1 to M where M is the total number of registered participants. A global scoreboard is maintained tracking the daily steps of each participant.

John is determined to win Walktober this year and his goal is to score the maximum daily steps on each of the N days among all the participants. Having participated in Walktober last year as well, he wanted to know how many steps he fell short of in achieving his goal. Given the previous year scoreboard, calculate the minimum additional steps he needed over his last year score in order to achieve his goal of scoring the maximum daily steps every day.

Input
The first line of the input gives the number of test cases, T. T test cases follow.
The first line of each test case contains three integers M, N, and P denoting the total number of participants, the total number of days the competition runs, and the last year participant ID of John.
The next M lines describe the scoreboard of the previous year and contains N integers each. The j-th integer of the i-th line denotes the step count Si,j of the participant with ID i on the j-th day of the competition.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum total additional steps needed by John to achieve his goal.

Limits
Memory limit: 1 GB.
1≤T≤100.
1≤N≤31.
1≤Si,j≤60000 for all i and j.
1≤P≤M.
Test Set 1
Time limit: 20 seconds.
M=2.
Test Set 2
Time limit: 40 seconds.
2≤M≤1000.

*/

#include <iostream>
using namespace std;

int solve(int m, int n, int p, int ** scoreboard){

    int * participant = scoreboard[p];

    int maxDiff, totalDiff = 0;

    for(int i = 0; i < n; i++){// day ->scoreboard[][y]
        maxDiff = 0;
        for(int j = 0; j < m; j++){ // id -> scoreboard[x][]
            if((participant[i] > scoreboard[j][i]) && (participant[i] - scoreboard[j][i] > maxDiff)){
                maxDiff = participant[i] - scoreboard[j][i];
            }
        }
        totalDiff += maxDiff;
    }


    return totalDiff;
}

int main(){
    int cases = 0;
    cin >> cases;
    for(int i = 0; i < cases; i++){
        int m, n, p = 0;
        cin >> m;
        cin >> n;
        cin >> p; 

        int ** scoreboard = new int * [m];

        for(int j = 0; j < m; j++){
            int score = 0;
            scoreboard[j] = new int[n];
            for(int k = 0; k < n; k++){
                cin >> scoreboard[j][k];
                // cout << "scoreboard[" << j << "][" << k << "]: " << scoreboard[j][k] << "___";
            }  
            // cout << endl;
        }

        cout << "Case #" << i+1 << ": " << solve(m, n, p, scoreboard) << endl;

    }

}