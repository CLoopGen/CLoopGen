#include <stdint.h>

typedef unsigned short uint16;

uint16 rm[256];
uint16 gm[256];
uint16 bm[256];
int i;

void init_vars() {
    for (int idx = 0; idx < 256; ++idx) {
        rm[idx] = idx;
        gm[idx] = 255 - idx;
        bm[idx] = (idx * 17) % 256;
    }
    i = 0;
}