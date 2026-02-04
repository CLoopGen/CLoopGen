#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int i;
extern int j;
extern int color;
extern int vertexi[361];
extern int vertexj[361];
extern int vertices;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int total_elements = board_size * board_size;
for (i = 0; i < total_elements; i++) {
    int row = i / board_size;
    int col = i % board_size;
    if (board[((19 + 2) + row * (19 + 1) + col)] == color) {
        vertexi[vertices] = row;
        vertexj[vertices++] = col;
    }
}
}
