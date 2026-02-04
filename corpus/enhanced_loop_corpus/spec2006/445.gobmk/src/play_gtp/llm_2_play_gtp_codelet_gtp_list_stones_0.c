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
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major access, traverse the board with a fixed stride
    // to create non-consecutive memory accesses. This simulates a strided pattern.
    int stride = (19 + 1);
    int base_offset = (19 + 2);
    for (i = 0; i < board_size * board_size; i++) {
        int idx = base_offset + (i / board_size) * stride + (i % board_size);
        if (board[idx] == color) {
            vertexi[vertices] = i / board_size;
            vertexj[vertices++] = i % board_size;
        }
    }
}
