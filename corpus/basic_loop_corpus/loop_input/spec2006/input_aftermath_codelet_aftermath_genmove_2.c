#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned char Intersection;

Intersection board[421];
int under_control[400];
int distance[400];
int pos;

void init_vars() {
    // Initialize board: set all elements to 3 except some positions
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 17 == 0) ? 0 : 3;
    }

    // Initialize distance: set to -1 or non-negative values based on index
    for (int i = 0; i < 400; i++) {
        distance[i] = (i % 13 == 0) ? -1 : i % 5;
    }

    // Initialize under_control array to a known state (will be overwritten in loop)
    for (int i = 0; i < 400; i++) {
        under_control[i] = -1;
    }

    // Ensure pos is initialized by the loop itself, but define initial value if needed elsewhere
    pos = 0;
}