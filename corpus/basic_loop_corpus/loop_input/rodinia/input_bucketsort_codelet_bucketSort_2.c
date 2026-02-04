#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define LOOP_SIZE (1 << 10)

unsigned int *h_offsets;
int *nullElements;
unsigned int *origOffsets;

void init_vars() {
    h_offsets = (unsigned int*)aligned_alloc(64, LOOP_SIZE * sizeof(unsigned int));
    nullElements = (int*)aligned_alloc(64, LOOP_SIZE * sizeof(int));
    origOffsets = (unsigned int*)aligned_alloc(64, (LOOP_SIZE + 1) * sizeof(unsigned int));

    if (!h_offsets || !nullElements || !origOffsets) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < LOOP_SIZE; i++) {
        h_offsets[i] = rand() % 1000;
        origOffsets[i] = rand() % 500;
    }
    origOffsets[LOOP_SIZE] = 0;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}