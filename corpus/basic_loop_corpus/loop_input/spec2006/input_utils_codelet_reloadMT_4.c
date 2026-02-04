#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 624
#define M 397
#define ARRAY_SIZE (1 << 20)  // ~256MB of state data (adjustable)

unsigned int state[625];
unsigned int *p0;
unsigned int *p2;
unsigned int *pM;
unsigned int s0;
unsigned int s1;
int j;

static unsigned int internal_state[ARRAY_SIZE];

void init_vars() {
    // Seed the internal state with predictable but varied values
    srand(time(NULL));
    for (int i = 0; i < 625; i++) {
        state[i] = rand() ^ (rand() << 16);
    }
    
    // Fill large backing array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        internal_state[i] = rand() ^ (rand() << 16);
    }

    // Initialize pointers to ensure no out-of-bounds access
    p0 = internal_state;
    p2 = internal_state + 1;
    pM = internal_state + (N - M);

    // Ensure that during the loop, pM and p2 don't exceed bounds
    // Loop runs for (624 - 397) = 227 iterations
    // So p2 goes from +1 to +228, pM from +(624-397) to +(624-397)+227 = +454
    // We require at least 455 elements -> we have plenty (1<<20)
}