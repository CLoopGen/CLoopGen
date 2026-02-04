#include <inttypes.h>
#include <stdlib.h>

int32_t coeffs[16] = {
    1, -2, 3, -4, 5, -6, 7, -8,
    9, -10, 11, -12, 13, -14, 15, -16
};

static int32_t sig_data[16] = {
    100, 200, 300, 400, 500, 600, 700, 800,
    900, 1000, 1100, 1200, 1300, 1400, 1500, 1600
};

int32_t *sig = sig_data;

int64_t e = 0;

int i = 0;

void init_vars() {
}