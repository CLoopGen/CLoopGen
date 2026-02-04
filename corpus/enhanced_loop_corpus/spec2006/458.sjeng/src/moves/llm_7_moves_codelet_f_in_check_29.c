#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int next_index;
    for (int i = wking_loc + 13; ; i = next_index) {
        next_index = i + 13; // Eliminate direct loop-carried dependence on i; use precomputed next
        if (board[i] != 13) {
            l = i;
            break;
        }
    }
}
