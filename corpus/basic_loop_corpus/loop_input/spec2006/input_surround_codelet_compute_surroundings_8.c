#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Intersection;

Intersection board[421];
int *surround_size;
char mn[400];
int pos;

void init_vars() {
    // Allocate and initialize surround_size pointer
    static int internal_surround_size;
    surround_size = &internal_surround_size;
    internal_surround_size = 0;

    // Initialize board array with size 421
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 4); // Values 0 to 3 to ensure some are not 3
    }

    // Initialize mn array with size 400
    for (int i = 0; i < 400; i++) {
        mn[i] = (i % 2); // Alternating 0 and 1 to ensure some are 1
    }

    // Ensure loop bounds: pos from (19+2)=21 to (19+1)*(19+1)-1 = 399
    // So we're accessing board[pos] and mn[pos] for pos in [21, 399]
    // Our arrays of size 421 and 400 respectively are sufficient
}