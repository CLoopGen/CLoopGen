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
    int temp_all_lively = all_lively;
    for (k = 0; k < 4; k++) {
        int index = pos + delta[k];
        if (board[index] == other && !lively[index])
            temp_all_lively = 0;
    }
    all_lively = temp_all_lively;
}
