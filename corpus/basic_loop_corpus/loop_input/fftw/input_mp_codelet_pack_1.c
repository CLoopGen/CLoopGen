#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned short *d;
int e;
int l;
int i;

static unsigned short d_data[131072]; // 256KB of data (131072 elements * 2 bytes)

void init_vars() {
    l = 131072;
    e = l;
    for (int idx = 0; idx < l; ++idx) {
        d_data[idx] = 0;
    }
    // Set one non-zero element near the beginning to ensure loop breaks quickly but scans some elements
    d_data[l - 1000] = 1;
    d = d_data;
}