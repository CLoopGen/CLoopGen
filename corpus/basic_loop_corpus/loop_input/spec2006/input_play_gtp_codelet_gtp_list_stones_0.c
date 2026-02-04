#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int board_size = 19;
Intersection board[421];
int i;
int j;
int color = 1;
int vertexi[361];
int vertexj[361];
int vertices;

void init_vars() {
    // Initialize board_size to 19 since the indexing suggests a 19x19 board with padding
    board_size = 19;
    
    // Ensure board has enough space: index used is (19+2) + i*(19+1) + j
    // Max index: (21) + 18*20 + 18 = 21 + 360 + 18 = 399 -> fits in 421
    for (int idx = 0; idx < 421; idx++) {
        board[idx] = (idx % 7 == 0) ? color : 0;  // sprinkle some color matches
    }

    // Initialize color
    color = 1;

    // Initialize vertices counter
    vertices = 0;

    // Clear vertex arrays
    for (int idx = 0; idx < 361; idx++) {
        vertexi[idx] = 0;
        vertexj[idx] = 0;
    }
}