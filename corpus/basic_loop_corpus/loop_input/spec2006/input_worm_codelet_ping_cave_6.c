#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

Intersection board[421];
int pos;
int mse[400];
int other;

void init_vars() {
    // Initialize board with size 421, fill within safe bounds
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 4); // cycle through 0,1,2,3 to ensure some values are not 3
    }

    // Initialize mse array of size 400
    for (int i = 0; i < 400; i++) {
        mse[i] = 1; // set all to non-zero so condition depends on board
    }

    // Set 'other' to a valid value, e.g., 1
    other = 1;

    // Ensure pos is uninitialized as it's a loop counter
}