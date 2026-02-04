#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int b[19][19];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i_start = 0;
int i_end = board_size;
int j_stride = 1;

for (i = i_start; i < i_end; i++) {
    for (j = 0; j < board_size; j += j_stride) {
        int index = (19 + 2) + i * (19 + 1) + j;
        b[i][j] = board[index];
    }
}
}
