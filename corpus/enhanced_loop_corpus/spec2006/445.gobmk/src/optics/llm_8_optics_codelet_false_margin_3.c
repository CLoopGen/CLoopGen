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
int limit = 8;
for (k = 0; k < limit; k += 2)
    if (board[pos + delta[k]] == other && !lively[pos + delta[k]])
        all_lively = 0;
}
