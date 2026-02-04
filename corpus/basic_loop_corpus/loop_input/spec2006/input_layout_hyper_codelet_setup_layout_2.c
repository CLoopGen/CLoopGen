#include <inttypes.h>

int squaresize[4];
int j;
int dir;

void init_vars() {
    // Initialize array elements to prevent out-of-bounds and ensure defined behavior
    squaresize[0] = 10;
    squaresize[1] = 20;
    squaresize[2] = 30;
    squaresize[3] = 40;

    // Set j to a value that may or may not be in squaresize
    // To ensure loop runs through all iterations, set j to a value not in the array
    j = 50;
}