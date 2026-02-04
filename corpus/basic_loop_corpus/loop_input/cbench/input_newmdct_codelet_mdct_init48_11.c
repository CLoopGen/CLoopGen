#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

int k;
FLOAT8 max;
FLOAT8 *wp;
FLOAT8 *wr;

static FLOAT8 data_in[32000000];    // ~256 MB of input data
static FLOAT8 data_out[32000000];   // ~256 MB of output space

void init_vars() {
    max = 123.456;
    for (int i = 0; i < 32000000; i++) {
        data_in[i] = (FLOAT8)(i + 1);
    }
    wp = data_in;
    wr = data_out;
}