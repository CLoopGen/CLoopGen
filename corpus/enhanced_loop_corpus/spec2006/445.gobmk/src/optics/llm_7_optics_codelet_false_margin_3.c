#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int pos;
extern int lively[400];
extern int other;
extern int k;
extern int all_lively;
extern int delta[8];
extern Intersection board[421];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_lively = all_lively;
    for (k = 3; k >= 0; k--) {
        int neighbor = pos + delta[k];
        int condition = (board[neighbor] == other) & (!lively[neighbor]);
        local_lively &= (condition ^ 1);  // Equivalent to: if condition is true, result becomes 0
    }
    all_lively = (local_lively == 0) ? 0 : all_lively;
}
