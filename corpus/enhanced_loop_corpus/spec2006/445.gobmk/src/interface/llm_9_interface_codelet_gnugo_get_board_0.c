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
int offset = (19 + 2);
int row_stride = (19 + 1);
int total_elements = board_size * board_size;

for (int idx = 0; idx < total_elements; idx++) {
    int i = idx / board_size;
    int j = idx % board_size;
    b[i][j] = board[offset + i * row_stride + j];
}
}
