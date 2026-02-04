#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ni;
int *left;
int *q;
int i;

void init_vars() {
    ni = 64 * 1024 * 1024 / sizeof(int);  // ~256 MB of total data (two arrays)
    
    left = (int*)aligned_alloc(32, ni * sizeof(int));
    q = (int*)aligned_alloc(32, ni * sizeof(int));
    
    if (!left || !q) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < ni; ++j) {
        q[j] = rand();
    }

    i = 0;
}