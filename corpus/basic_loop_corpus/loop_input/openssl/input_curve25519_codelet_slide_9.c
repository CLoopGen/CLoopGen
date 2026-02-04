#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

signed char *r;
int i;
int b;
int k;

static signed char r_data[1024 * 256]; // 256KB of data

void init_vars() {
    r = r_data;
    i = 0;
    b = 0;
    k = 0;

    // Initialize r with a non-trivial pattern to ensure meaningful computation
    for (int idx = 0; idx < sizeof(r_data); ++idx) {
        r[idx] = (signed char)((idx * 71) % 31 - 15); // values in [-15, 15]
    }
}