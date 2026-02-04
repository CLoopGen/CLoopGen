#include <stdint.h>
#include <stdlib.h>

int *mvbits;
int bits;
int i;
int imin;
int imax;
int max_mv_bits = 21;

static int mvbits_storage[1 << 16];

void init_vars() {
    for (int j = 0; j < (1 << 16); j++) {
        mvbits_storage[j] = 0;
    }
    mvbits = mvbits_storage + (1 << 15);
}