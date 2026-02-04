#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

int k;
FLOAT8 *wp;
FLOAT8 *wr;
FLOAT8 w;

static FLOAT8 data_in[32000000];
static FLOAT8 data_out[32000000];

void init_vars() {
    wp = data_in;
    wr = data_out;
    w = 2.5;
    for (int i = 0; i < 32000000; i++) {
        data_in[i] = (FLOAT8)(i + 1);
    }
}