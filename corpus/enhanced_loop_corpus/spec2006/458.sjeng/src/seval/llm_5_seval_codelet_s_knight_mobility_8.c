#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern  int knight_o[8];
extern int square;
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_m = 0;
for (d = 0; d < 8; d++) {
    int index = square + knight_o[d];
    int val = board[index];
    if (val == 13) {
        temp_m++;
    }
}
m = temp_m;
}
