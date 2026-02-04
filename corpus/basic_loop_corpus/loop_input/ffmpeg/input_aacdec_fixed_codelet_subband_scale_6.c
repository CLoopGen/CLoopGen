#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

int *dst;
int len;
int i;

void init_vars() {
    len = 64 * 1024 * 1024 / sizeof(int);  // ~256 MB of data
    dst = (int *)aligned_alloc(32, len * sizeof(int));
    if (!dst) {
        exit(1);
    }
    for (int j = 0; j < len; j++) {
        dst[j] = -1;
    }
}