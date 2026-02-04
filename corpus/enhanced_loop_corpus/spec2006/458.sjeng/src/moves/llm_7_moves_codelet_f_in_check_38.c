#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int next_index = l; // Eliminate loop-carried dependency by precomputing in independent variable
    for (int i = wking_loc + 13; board[i] == 13; i = next_index) {
        next_index = i + 13;
        l = i; // Write to l without carrying dependency to loop condition
    }
}
