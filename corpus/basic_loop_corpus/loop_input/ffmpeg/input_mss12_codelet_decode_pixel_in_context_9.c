#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t neighbours[4] = {1, 2, 3, 4};

uint8_t* ref_pix = NULL;
int nlen = 0;

int i = 0;
int j = 0;

void init_vars() {
    size_t data_size = 1 << 20; // ~1MB of data
    ref_pix = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!ref_pix) {
        exit(1);
    }
    nlen = 0;
    for (int k = 0; k < 4; k++) {
        ref_pix[k] = k + 5;
        nlen++;
    }
}