#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int tmp[16];

static int d0_vals[] = {1, -2, 3, -1};
static int d1_vals[] = {2, 1, -1, 4};
static int d2_vals[] = {-1, 3, 2, -2};
static int d3_vals[] = {0, 1, -3, 2};

void init_vars() {
    i = 0;

    for (int idx = 0; idx < 4; idx++) {
        const int d0 = d0_vals[idx];
        const int d1 = d1_vals[idx];
        const int d2 = d2_vals[idx];
        const int d3 = d3_vals[idx];
        const int a0 = (d0 + d3);
        const int a1 = (d1 + d2);
        const int a2 = (d1 - d2);
        const int a3 = (d0 - d3);
        tmp[0 + idx * 4] = (a0 + a1) * 8;
        tmp[1 + idx * 4] = (a2 * 2217 + a3 * 5352 + 1812) >> 9;
        tmp[2 + idx * 4] = (a0 - a1) * 8;
        tmp[3 + idx * 4] = (a3 * 2217 - a2 * 5352 + 937) >> 9;
    }
}