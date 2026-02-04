#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

int i;
int k;
FLOAT8 max = 1.0;
FLOAT8 *wp;
FLOAT8 *wr;
FLOAT8 mmax[31];

static FLOAT8 wp_data[480];
static FLOAT8 wr_data[720];

void init_vars() {
    max = 1.0;
    for (int idx = 0; idx < 480; ++idx) {
        wp_data[idx] = (FLOAT8)(idx + 1);
    }
    for (int idx = 0; idx < 720; ++idx) {
        wr_data[idx] = 0.0;
    }
    wp = wp_data;
    wr = wr_data;
}