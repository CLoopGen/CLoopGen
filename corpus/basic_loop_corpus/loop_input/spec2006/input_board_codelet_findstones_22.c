#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int next_stone[400];
int maxstones;
int *stones;
int size;
int pos;
int k;

void init_vars() {
    size = 1000000; // Approximately 4MB of data for stones array
    maxstones = 1000; // Less than size and within safe bounds
    pos = 0;

    // Ensure maxstones does not exceed size or the fixed next_stone array size
    if (maxstones > 400) maxstones = 400;

    // Allocate memory for stones array
    stones = (int*)malloc(size * sizeof(int));

    // Initialize next_stone array to form a valid sequence within bounds
    for (int i = 0; i < 399; i++) {
        next_stone[i] = i + 1;
    }
    next_stone[399] = 0; // Wrap around to create a valid cycle

    // Initialize stones array to zero
    for (int i = 0; i < size; i++) {
        stones[i] = 0;
    }
}