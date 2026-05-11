#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

// Global variable to count moves
int g = 0;


// Print Puzzle
void Print(int puzzle[]) {

    for(int i = 0; i < 9; i++) {

        if(i % 3 == 0)
            cout << "\n";

        if(puzzle[i] == -1)
            cout << "_ ";
        else
            cout << puzzle[i] << " ";
    }

    cout << "\n";
}


// Move Blank Left
void moveLeft(int start[], int position) {

    swap(start[position], start[position - 1]);
}


// Move Blank Right
void moveRight(int start[], int position) {

    swap(start[position], start[position + 1]);
}


// Move Blank Up
void moveUp(int start[], int position) {

    swap(start[position], start[position - 3]);
}


// Move Blank Down
void moveDown(int start[], int position) {

    swap(start[position], start[position + 3]);
}


// Copy Array
void Copy(int temp[], int real[]) {

    for(int i = 0; i < 9; i++) {

        temp[i] = real[i];
    }
}


// Heuristic Function (Manhattan Distance)
int heuristic(int start[], int goal[]) {

    int h = 0;

    for(int i = 0; i < 9; i++) {

        for(int j = 0; j < 9; j++) {

            if(start[i] == goal[j] && start[i] != -1) {

                h += abs(i / 3 - j / 3) + abs(i % 3 - j % 3);
            }
        }
    }

    return h + g;
}


// Generate and Select Best Move
void moveTile(int start[], int goal[]) {

    int emptyAt = 0;

    // Find blank tile position
    for(int i = 0; i < 9; i++) {

        if(start[i] == -1) {

            emptyAt = i;
            break;
        }
    }

    int row = emptyAt / 3;
    int col = emptyAt % 3;

    // Temporary boards
    int t1[9], t2[9], t3[9], t4[9];

    Copy(t1, start);
    Copy(t2, start);
    Copy(t3, start);
    Copy(t4, start);

    // Heuristic values
    int f1 = INT_MAX;
    int f2 = INT_MAX;
    int f3 = INT_MAX;
    int f4 = INT_MAX;


    // LEFT MOVE
    if(col - 1 >= 0) {

        moveLeft(t1, emptyAt);

        f1 = heuristic(t1, goal);
    }


    // RIGHT MOVE
    if(col + 1 < 3) {

        moveRight(t2, emptyAt);

        f2 = heuristic(t2, goal);
    }


    // DOWN MOVE
    if(row + 1 < 3) {

        moveDown(t3, emptyAt);

        f3 = heuristic(t3, goal);
    }


    // UP MOVE
    if(row - 1 >= 0) {

        moveUp(t4, emptyAt);

        f4 = heuristic(t4, goal);
    }


    // Find minimum heuristic
    int minimum = min(min(f1, f2), min(f3, f4));


    // Perform best move
    if(f1 == minimum) {

        moveLeft(start, emptyAt);
    }

    else if(f2 == minimum) {

        moveRight(start, emptyAt);
    }

    else if(f3 == minimum) {

        moveDown(start, emptyAt);
    }

    else {

        moveUp(start, emptyAt);
    }
}


// Solve Puzzle
void solveEight(int start[], int goal[]) {

    g++;

    moveTile(start, goal);

    Print(start);

    int f = heuristic(start, goal);

    // Goal reached
    if(f == g) {

        cout << "\nSolved in " << f << " moves\n";

        return;
    }

    // Recursive call
    solveEight(start, goal);
}


// Check Solvability
bool solvable(int start[]) {

    int invrs = 0;

    for(int i = 0; i < 9; i++) {

        if(start[i] == -1)
            continue;

        for(int j = i + 1; j < 9; j++) {

            if(start[j] == -1)
                continue;

            if(start[i] > start[j])
                invrs++;
        }
    }

    // Even inversions -> solvable
    return invrs % 2 == 0;
}


// Main Function
int main() {

    int start[9];
    int goal[9];

    cout << "Enter Start State (-1 for blank):\n";

    for(int i = 0; i < 9; i++) {

        cin >> start[i];
    }

    cout << "Enter Goal State (-1 for blank):\n";

    for(int i = 0; i < 9; i++) {

        cin >> goal[i];
    }

    Print(start);

    // Check solvability
    if(solvable(start)) {

        solveEight(start, goal);
    }

    else {

        cout << "\nNot Possible To Solve\n";
    }

    return 0;
}


/*

TEST CASE

Start State:

1
2
3
-1
4
6
7
5
8


Goal State:

1
2
3
4
5
6
7
8
-1

*/
