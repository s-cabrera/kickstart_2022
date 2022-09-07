/*
CENTAURI PRIME

Problem
--------------------------------------------------
Alice and Bob are playing the game called Centauri Prime. Centauri Prime represents a planet which is split into several independent kingdoms. Before they start playing the game, they have to choose rulers for each kingdom. Alice and Bob mutually decided to distribute kingdoms based on the letter the kingdom's name ended with. Alice loves vowels and decided to rule kingdoms whose names ended in a vowel. Bob loves consonants and decided to rule kingdoms whose names ended in a consonant. Both of them do not like the letter 'y'(case insensitive) and thus, all kingdoms whose names ended in the letter 'y' are left without a ruler. Can you write a program that will determine the rulers of several kingdoms, given the kingdoms' names?

Input
The first line of the input gives the number of test cases, T. T lines follow, each one containing the name of one kingdom. Kingdom names will consist of only lower case English letters, starting with a capital letter. There will be no other characters on any line, and no empty lines.
List of vowels for this problem is ['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'].

Output
For each test case, output one line containing Case #x: K is ruled by Y., where x is the case number (starting from 1), K is the kingdom name, and Y is either Alice, Bob or nobody.

Be careful with capitalization and the terminating period. Your output must be in exactly this format. See the examples below.

Limits
Time limit: 30 seconds.
Memory limit: 1 GB.
1≤T≤300.
Test Set 1
Each kingdom name will have between 3 and 20 letters.

Test Set 2
Each kingdom name will have at most 100 letters.

*/

#include <iostream>
#include <string>
using namespace std;

string solve(string kingdom){
    char end = kingdom.back();
    string vowels = "AEIOUaeiou";
    string y = "yY";

    if(y.find(end) != string::npos){
        return kingdom + " is ruled by nobody.";
    }
    else if(vowels.find(end) != string::npos){
        return kingdom + " is ruled by Alice.";
    }
    else{
        return kingdom + " is ruled by Bob.";
    }
    
    return "";
}

int main (){

    int cases;
    string kingdom;
    cin >> cases;

    for(int i = 0; i < cases; i++){
        cin >> kingdom;
        cout << "Case #" << i+1 << ": " << solve(kingdom) << endl;
    }


    return 0;
}
