/*
Name: Record Breaker
Problem
Isyana is given the number of visitors at her local theme park on N consecutive days. The number of visitors on the i-th day is Vi. A day is record breaking if it satisfies both of the following conditions:

Either it is the first day, or the number of visitors on the day is strictly larger than the number of visitors on each of the previous days.
Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day.
Note that the very first day could be a record breaking day!
Please help Isyana find out the number of record breaking days.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the integer N. The second line contains N integers. The i-th integer is Vi and represents the number of visitors on the i-th day.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of record breaking days.

Limits
Time limit: 20 seconds.
Memory limit: 1 GB.
1≤T≤100.
0≤Vi≤2×105, for all i.
Test Set 1
1≤N≤1000.
Test Set 2
1≤N≤2×105, for at most 10 test cases.
For the remaining cases, 1≤N≤1000.

*/

//== MY SOLUTION   ==//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// #define NIL -1
// #define MAX 200000

// long int storage[MAX];

int solve()
{
    unsigned int days, value;
    cin >> days;

    vector<int> visitors ;

    for (int i = 0; i < days; i++)
    {
        cin >> value;
        visitors.push_back(value);
    }

    int result = 0;
    int max = -1;    
    for (int i = 0; i < visitors.size()-1; i++)
    {   
        cout << "i: " << i << "; max: " << max << "; result: " << result << endl;
        if(i == 0 && visitors.at(i) > visitors.at(i + 1)){
            max = visitors.at(i);
            result++;
        }
        else if(visitors.at(i) > visitors[i+1] && visitors[i] > max){
            max = visitors.at(i);
            result++;
        }
        else if(i == visitors.size()-2 && visitors.at(i+1) > max){
            max = visitors.at(i+1);
            result++;
        }
    }

    return result;
}

int main()
{
    unsigned int cases = 0;

    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        cout << "Case #" << i+1 << ": " << solve() <<endl;
    }

    return 0;
}
