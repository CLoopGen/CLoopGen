#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

int ni;
int *left;
int *q;
int i;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    ni = 1 << 24; // Approximately 67 million elements for ~0.01s on modern CPU
    left = (int *)aligned_alloc(32, ni * sizeof(int));
    q = (int *)aligned_alloc(32, ni * sizeof(int));

    if (!left || !q) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < ni; ++j) {
        q[j] = j * 3 + 1;
    }

    // Warm up loop execution to stabilize timing
    for (int iter = 0; iter < 2; ++iter) {
        for (i = 0; i < ni; ++i)
            left[i] = q[i];
    }

    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

    if (elapsed > 0.02) {
        ni = (int)(ni * 0.01 / elapsed);
        free(left);
        free(q);
        left = (int *)aligned_alloc(32, ni * sizeof(int));
        q = (int *)aligned_alloc(32, ni * sizeof(int));
        for (int j = 0; j < ni; ++j) {
            q[j] = j * 3 + 1;
        }
    }
}