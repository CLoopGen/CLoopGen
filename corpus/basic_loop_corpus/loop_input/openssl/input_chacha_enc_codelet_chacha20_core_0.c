#include <inttypes.h>

typedef unsigned int u32;

u32 x[16];
int i;

void init_vars() {
    for (int j = 0; j < 16; j++) {
        x[j] = 0xdeadbeefU ^ (j * j);
    }
    i = 20;
}