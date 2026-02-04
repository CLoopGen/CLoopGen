#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *lens;
unsigned int codes;
uint16_t *work;
unsigned int sym;
uint16_t offs[16];

void init_vars() {
    codes = 1 << 20; // 1 million symbols

    lens = (uint16_t*)calloc(codes, sizeof(uint16_t));
    work = (uint16_t*)malloc(2 * codes * sizeof(uint16_t));

    for (unsigned int i = 0; i < codes; i++) {
        lens[i] = rand() % 16; // values in [0,15]
    }

    for (int i = 0; i < 16; i++) {
        offs[i] = 0;
    }

    for (unsigned int i = 0; i < codes; i++) {
        if (lens[i] != 0) {
            offs[lens[i]]++;
        }
    }

    uint16_t sum = 0;
    for (int i = 0; i < 16; i++) {
        uint16_t temp = offs[i];
        offs[i] = sum;
        sum += temp;
    }
}