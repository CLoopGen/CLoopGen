#include <inttypes.h>
#include <stdlib.h>

int16_t block[64];
int i;

void init_vars() {
    for (int j = 0; j < 64; j++) {
        block[j] = (int16_t)(j * 1000);
    }
    i = 0;
}