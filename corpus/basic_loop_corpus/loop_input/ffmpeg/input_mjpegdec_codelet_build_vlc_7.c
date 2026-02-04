#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int is_ac;
uint16_t huff_sym[256];
int i;

void init_vars() {
    is_ac = 1;
    for (i = 0; i < 256; i++) {
        huff_sym[i] = 0;
    }
    i = 0;
}