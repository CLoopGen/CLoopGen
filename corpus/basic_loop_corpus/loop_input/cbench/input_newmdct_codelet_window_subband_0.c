#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef double FLOAT8;

short *xk;
FLOAT8 *in;
int i;
FLOAT8 s;
FLOAT8 t;
FLOAT8 *wp;

#define Xk_SIZE (512)
#define In_SIZE (31)
#define Wp_SIZE (14 * 14)

static short xk_data[512];
static FLOAT8 in_data[31];
static FLOAT8 wp_data[196];

void init_vars() {
    xk = xk_data;
    in = in_data;
    wp = wp_data;

    for (int idx = 0; idx < Xk_SIZE; ++idx) {
        xk_data[idx] = (short)(idx % 30000);
    }

    for (int idx = 0; idx < In_SIZE; ++idx) {
        in_data[idx] = (FLOAT8)(idx + 1) * 0.5;
    }

    for (int idx = 0; idx < Wp_SIZE; ++idx) {
        wp_data[idx] = (FLOAT8)(idx + 1) * 0.1;
    }

    i = 14;
    s = 0.0;
    t = 0.0;
}