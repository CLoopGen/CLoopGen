#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int n = 1 << 24; // Approximately 256MB of data (64M elements for int32_t)
int32_t *smp;

void init_vars() {
    smp = aligned_alloc(32, n * sizeof(int32_t));
    if (!smp) {
        exit(1);
    }
    for (int j = 0; j < n; j++) {
        smp[j] = (j == 0) ? 42 : 43;
    }
}