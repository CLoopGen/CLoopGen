#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *lsfq;
int lsfq_min_distance;
int lsfq_min;
int lp_order;
int i;

void init_vars() {
    lp_order = 65536; // Size to achieve ~0.01 sec runtime on modern CPU
    lsfq_min_distance = 10;
    lsfq_min = 500;

    lsfq = aligned_alloc(32, lp_order * sizeof(int16_t));
    if (!lsfq) {
        exit(1);
    }

    for (int j = 0; j < lp_order; j++) {
        lsfq[j] = 400 + (j % 200); // Initialize with values near lsfq_min
    }
}