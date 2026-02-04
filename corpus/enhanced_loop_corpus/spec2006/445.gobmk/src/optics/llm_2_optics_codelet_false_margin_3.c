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
    // Variant 1: Strided memory access with increased stride (simulating a different access pattern)
    // Instead of accessing delta[0] to delta[3] sequentially, use a fixed offset pattern on delta array
    for (k = 0; k < 4; k++) {
        int index = pos + delta[k * 2 % 8];  // Strided access into delta (using modulo to stay in bounds)
        if (board[index] == other && !lively[index])
            all_lively = 0;
    }
}
