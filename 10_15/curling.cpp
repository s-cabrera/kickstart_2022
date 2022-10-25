/*

Problem
2022 is a year of the Winter Olympics! Curling has been one of the most popular winter sports as it requires skill, strategy, and sometimes a bit of luck.

In a curling game, two teams compete by sliding heavy granite stones on a long ice sheet. We call the teams the red team and the yellow team, as their stones are usually distinguished by the red and the yellow handle color. A curling game consists of several ends (subgames); in every end, the teams, each owning 8 stones, take turns to slide them across the long ice sheet toward a circular target area called the house. A stone may hit existing stones to change its own moving direction and other stones' position (including knocking them out of play). Roughly speaking, the goal for a team is to make their stones as close to the center of the house as possible.

Geometrically, a house and a stone can be modeled as a circle and a disk (the region bounded by a circle), respectively, and the scoring rules at the conclusion of each end are formally summarized as follows.

Each stone can be viewed as a disk of radius Rs on a 2-dimensional plane.
The house is a circle of radius Rh centered at (0,0).
Only stones in the house are considered in the scoring. A stone is in the house if any portion of the stone lies on or within the circle representing the house. Tangency also counts.
A team is awarded 1 point for each of their own stones in the house such that no opponent's stone is closer (in Euclidean distance) to the center than it. We assume in this problem that no two stones are equally close to the center (0,0).
Two teams are playing and have just delivered all their stones. The red team has N stones remaining on the curling sheet, centered at (X1,Y1),(X2,Y2),…,(XN,YN), while the yellow team has M stones remaining, centered at (Z1,W1),(Z2,W2),…,(ZM,WM). Now you are asked to figure out the scores of both teams.

Input
The first line of the input gives the number of test cases, T. T test cases follow.

Each test case begins with a line containing the two space-separated integers Rs and Rh.

The next line contains the integer N. Then N lines follow, the i-th line of which containing the two space-separated integers Xi and Yi.

After that, similarly, the next line contains the integer M. In the next M lines, the i-th line contains the two space-separated integers Zi and Wi.

Output
For each test case, output one line containing Case #x: y z, where x is the test case number (starting from 1), y is the score of the red team, and z is the score of the yellow team.

Limits
Time limit: 20 seconds.
Memory limit: 1 GB.
1≤T≤100.
1≤Rs<Rh≤104.
0≤N≤8.
−2×104≤Xi≤2×104, for all i.
−2×104≤Yi≤2×104, for all i.
−2×104≤Zi≤2×104, for all i.
−2×104≤Wi≤2×104, for all i.
The distances between the center of each stone and the center of the house (0,0) are distinct, i.e., no two stones are equally close to the center of the house.
No two stones overlap (but two stones can be tangent).
Test Set 1
M=0.
Test Set 2
0≤M≤8.

*/

#include <iostream>
#include <cmath>

using namespace std;

//Using LinkedList because I want the ability to 'push' the x and y cordinates into a data structure
// Vectors do not allow you to push array types

//Node object for LinkedList
class Node{
    public:
    char color;
    float distance;
    Node * next;

    Node(){
        color: '.';
        distance: 0; 
        next: NULL;
    }

    Node(char color, float distance){
        this->color = color;
        this->distance = distance;  
        this-> next = NULL;
    }
};

// LinkedList object to save the coordinates of each disk
class LinkedList {
    
    Node * head;
    
    public: 

    //LinkedList constructor
    LinkedList() { head = NULL; }

    void insertNode(char color, float distance){

        Node* node = new Node(color, distance);

        if(head == NULL){
            //List is empty. The new node is now the head;
            head = node;
        }         

        else{
            //Insert Sort it in
            Node * temp = head;

            if(distance < temp->distance){
                //If the value is less than the head value, make the new node the head node and point the pointers accoringly
                head = node;
                head -> next = temp;
                return;
            }

            if((temp->next == NULL) && (distance > temp->distance)){
                // if we're at the tail and distance is greater than temp-> distance
                temp->next = node;
                return;
            }

            Node * prev = head;
            while(temp->next != NULL){
                temp = temp -> next;
                if(distance > temp->distance){
                    if(temp-> next == NULL){
                        //This is the tail
                        temp-> next = node;
                        break;
                    }    
                    else{
                        prev = temp;
                    }
                }
                else if(distance > prev-> distance && distance < temp -> distance){
                    prev -> next = node;
                    node-> next = temp;
                    return;
                }
            }            
        }
    }  

    void printList(){
        Node * temp = head;

        if(head == NULL){
            cout << "Empty" << endl;
            return;
        }
        while(temp != NULL){
            if(temp ->color == 'r'){
                cout << "RED -> " << "distance: " << temp->distance << endl;
            }
            else if(temp ->color == 'y'){
                cout << "Yellow -> " << "distance: " << temp->distance << endl;
            }
            else{
                cout << endl;
            }
            temp = temp -> next;
        }
    }

    Node * getHead(){
        return head;
    }


};

float calcDistance(int x, int y, int Rs){
    // This calculates the distance of the closest point of a disk to (0,0)
    float midPoint = sqrt( (x * x) + (y * y));
    return (midPoint >= Rs) ? midPoint-Rs: midPoint;
};

void calculateScores(LinkedList disks, int * scores){
    // This will check the ordered linked list and stop once the list ends 
        //or we find a different color than the color of the first disk
    
    //Counter variables
    int redScore = 0;
    int yellowScore = 0;

    Node * temp = disks.getHead();
    if(temp == NULL){
        // cout  << "List is empty" << endl;
        return;
    }

    char color = temp->color;
    // cout << "Closest color: " << color << endl;
    
    while((temp != NULL) && (temp->color == color)){
        (color == 'r')? redScore ++ : yellowScore++;
        temp = temp -> next;
    }

    *scores = redScore;
    *(scores + 1) = yellowScore;

    // cout << "Reds: "<< *scores << "; Yellows: " << *(scores + 1) << endl;
}

void solve(int * scores){

    int Rs, Rh = 0;
    //Set Rs and Rh values
    cin >> Rs;
    cin >> Rh;
 
    //Initialize the Red team's Disks in house
    int N = 0;
    cin >> N;

    LinkedList inBoundDisks;

    for(int i = 0; i < N; i++){
        
        int x, y = 0;
        cin >> x;
        cin >> y;
        float distance = calcDistance(x, y, Rs);
        if(distance <=  Rh){
            inBoundDisks.insertNode('r', distance);
        }
    }

    //Initialize the Yellow team's Disks in house

    int M = 0;
    cin >> M;

//    LinkedList yellowDisks;

    for(int i = 0; i < M; i++){
        int x, y = 0;
        cin >> x;
        cin >> y;
        float distance = calcDistance(x, y, Rs);
        if(distance <= Rh){
            inBoundDisks.insertNode('y', distance);
        }
    }

    // inBoundDisks.printList(); 

    //Calculate scores
    calculateScores(inBoundDisks, scores); 

}

int main(){
    //#Step One: Loop through n cases
    int cases = 0;
    cin >> cases;
    for(int i = 0; i < cases; i++){
        //Allocate memory for the scores
        int scores[2] = {0, 0};
        solve(scores);
        cout << "Case #" << i+1 << ": " << scores[0] << " " << scores[1] << endl;

    }

}