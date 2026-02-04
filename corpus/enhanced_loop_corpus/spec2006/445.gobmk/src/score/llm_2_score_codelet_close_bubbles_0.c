#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int gb[400];
extern int bubbles[400];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii += 2) {
        if (!(board[ii] != 3) || gb[ii])
            continue;
        if (bubbles[ii] == 1)
            gb[ii] = 1;
        if (bubbles[ii] == 2)
            gb[ii] = -1;
    }
    // Handle odd indices if necessary to maintain coverage
    for (ii = (19 + 2) + 1; ii < (19 + 1) * (19 + 1); ii += 2) {
        if (!(board[ii] != 3) || gb[ii])
            continue;
        if (bubbles[ii] == 1)
            gb[ii] = 1;
        if (bubbles[ii] == 2)
            gb[ii] = -1;
    }
}
