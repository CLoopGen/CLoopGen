#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned long buffer[56];
} ran3_state_t;

ran3_state_t *state;
int i;
int i1;

void init_vars() {
    // Allocate state structure
    state = (ran3_state_t*)malloc(sizeof(ran3_state_t));
    if (!state) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize x and y
    state->x = 12345;
    state->y = 67890;

    // Seed the buffer with non-zero values to ensure meaningful computation
    srand(time(NULL));
    for (int idx = 0; idx < 56; idx++) {
        state->buffer[idx] = rand() % 1000000000 + 1;
    }

    // Ensure no out-of-bounds access: loop uses (i + 30) % 55, so we need valid indices 0..55
    // Our buffer is size 56, so index 55 is safe. i ranges from 1 to 55 inclusive -> max index accessed: 1 + (55 + 30) % 55 = 1 + 30 = 31 -> well within bounds
    // Therefore, current setup is safe
}