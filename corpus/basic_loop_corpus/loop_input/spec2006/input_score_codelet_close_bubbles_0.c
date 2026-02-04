#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned char Intersection;

Intersection board[421];
int gb[400];
int bubbles[400];
int ii;

void init_vars() {
    // Initialize board with size 421, only indices 0..399 are accessed in loop
    for (int i = 0; i < 400; i++) {
        board[i] = (i % 7) == 0 ? 3 : (i % 4);  // Some values equal to 3 to trigger condition
    }
    // Ensure no out-of-bounds access: ii goes from 21 to 360 (since (19+1)^2 = 400)
    // So we only need valid data up to index 399

    // Initialize gb and bubbles arrays
    for (int i = 0; i < 400; i++) {
        gb[i] = (i % 13) == 0 ? 1 : 0;
        bubbles[i] = (i % 3);  // produces 0, 1, or 2
    }

    // Set initial value of ii to be used in loop
    ii = 0;
}