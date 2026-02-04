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
for (i = 0; i < board_size; i++) {
    for (j = 0; j < board_size; j++) {
        if (board[((19 + 2) + i * (19 + 1) + j)] != color) {
            continue;
        }
        vertexi[vertices] = i;
        vertexj[vertices++] = j;
    }
}
}
