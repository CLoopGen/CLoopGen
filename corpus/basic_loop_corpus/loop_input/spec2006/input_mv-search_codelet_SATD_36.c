#include <inttypes.h>

int k;
int satd;
int dd;
int d[16];

void init_vars() {
    k = 0;
    satd = 0;
    dd = 0;

    for (int i = 0; i < 16; ++i) {
        d[i] = (i % 2 == 0) ? (i * 1000000) : -(i * 1000000);
    }
}