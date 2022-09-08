/*

H-Index

Problem
Jorge is a physicist who has published many research papers and wants to know how much impact they have had in the academic community. To measure impact, he has developed a metric, H-index, to score each of his papers based on the number of times it has been cited by other papers. Specifically, the H-index score of a researcher is the largest integer H such that the researcher has H papers with at least H citations each.

Jorge has written N papers in his lifetime. The i-th paper has Ci citations. Each paper was written sequentially in the order provided, and the number of citations that each paper has will never change. Please help Jorge determine his H-index score after each paper he wrote.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing N, the number of papers Jorge wrote. The second line contains N integers. The i-th integer is Ci, the number of citations that the i-th paper has.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is a space-separated list of N integers. The i-th integer is Jorge's H-index score after writing his i-th paper.

Limits
Time limit: 50 seconds.
Memory limit: 1 GB.

1≤T≤100

1≤Ci≤10^5

Test Set 1
1≤N≤1000

Test Set 2
1≤N≤105.

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> solve (int papers, vector <int> citations){

    vector <int> result;
    priority_queue<int, vector<int>, greater<int> > queue;
    int h_index = 0;

    for(int i = 1; i <= papers; i++){
        if(citations[i-1] > h_index){
            //add to the queue
            queue.push(citations[i-1]);
            if(queue.size() >= h_index+1){
                //check if added element is h_index                
                h_index++;
                
                while (queue.size() > 0 && queue.top() <= h_index){
                    queue.pop();
                }
                
            }
        }
        result.push_back(h_index);
    }

    return result;
}

int main (){
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++){
        int papers;
        int citation;
        cin >> papers;
        const int numPapers = papers;
        vector <int> citations;

        for(int j = 0; j < papers; j++ ){
            cin >> citation;
            citations.push_back(citation);
        }    
        vector <int> result = solve(papers, citations);
        cout << "Case #" << i+1 << ": ";
        for(int j = 0; j < papers; j++){
            (j < papers-1) ? cout << result[j] << " " : cout << result[j];
        }
        
        cout << endl; 
    }
    return 0;
}