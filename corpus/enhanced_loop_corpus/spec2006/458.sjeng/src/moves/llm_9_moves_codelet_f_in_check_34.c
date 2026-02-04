#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step;
    for (l = wking_loc + 1; board[l] == 13; l++) {
        for (step = 0; step < 3; step++) {
            board[l] += step; // Artificially increase inner computation
            board[l] -= step;
        }
    }
}
