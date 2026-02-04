#include <inttypes.h>

unsigned short *x;
unsigned short bits;
int i;

static unsigned short data[65536];

void init_vars() {
    x = &data[6 + 2];
    bits = 0;
    for (int idx = 0; idx < 65536; ++idx) {
        data[idx] = 0;
    }
}