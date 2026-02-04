#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

int board_size = 19;
int n;
int right_corner[19];
int top_row = 0;
char mn[400];

void init_vars() {
    // Initialize board_size to 19 as implied by usage of 19 in array indexing
    board_size = 19;

    // Initialize top_row to a valid index, assuming it's within bounds
    top_row = 0;

    // Ensure no out-of-bounds access: the expression
    // ((19 + 2) + top_row * (19 + 1) + n) must be within [0, 399] for mn[400]
    // Max index when n=board_size-1=18: 21 + 0*20 + 18 = 39 -> well within 400

    // Initialize mn with mostly zeros, but set one element to non-zero near the end of the loop range
    memset(mn, 0, sizeof(mn));
    
    // To trigger the break condition in the loop, we need mn[index] != 0
    // The loop starts at n = board_size - 1 = 18 and decrements down to 0
    // So the first checked index is:
    //   (19+2) + top_row*(19+1) + 18 = 21 + 0 + 18 = 39
    // We'll set mn[39] to 1 so that the loop body executes once and breaks
    mn[21 + top_row * 20 + (board_size - 1)] = 1;

    // Initialize right_corner array to zero
    memset(right_corner, 0, sizeof(right_corner));

    // Initialize loop counter n (used inside loop but not required to persist)
    n = 0;
}