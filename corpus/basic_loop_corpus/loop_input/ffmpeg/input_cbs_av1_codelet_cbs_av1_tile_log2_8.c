#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int blksize;
int target;
int k;

void init_vars() {
    blksize = 1;
    target = 1 << 24;  // Approximately 16.7 million iterations, tuned for ~0.01s on modern CPU
    k = 0;
}