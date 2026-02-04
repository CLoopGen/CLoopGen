#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *lens;
unsigned int codes;
unsigned int sym;
uint16_t count[16];

void init_vars() {
    codes = 65536; // ~64kB of input data: 65536 * sizeof(uint16_t) = 131072 bytes
    lens = (uint16_t*)malloc(codes * sizeof(uint16_t));
    if (!lens) {
        exit(1);
    }

    for (unsigned int i = 0; i < codes; i++) {
        lens[i] = rand() % 16; // values in [0,15] to match count array bounds
    }

    for (int i = 0; i < 16; i++) {
        count[i] = 0;
    }
}