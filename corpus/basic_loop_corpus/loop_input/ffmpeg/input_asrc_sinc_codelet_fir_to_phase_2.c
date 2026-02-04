#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *len;
int i;
int work_len;

static int len_storage;

void init_vars() {
    // Allocate and initialize len to point to len_storage
    len = &len_storage;
    
    // Set initial value for len_storage to ensure loop runs sufficiently long
    // The loop: i = *len, then i >>= 1 until i <= 1
    // Each iteration: work_len doubles, i halves
    // To get around 0.01 seconds runtime, we need enough iterations.
    // On modern CPUs, each iteration is very fast (a few cycles).
    // Aim for several million iterations -> set initial i to ~2^24 (~16M)
    len_storage = 1 << 24;  // Approximately 16 million iterations of the outer loop logic
}