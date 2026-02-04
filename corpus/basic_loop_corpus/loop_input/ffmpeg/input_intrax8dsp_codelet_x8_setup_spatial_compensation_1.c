#include <stdint.h>
#include <stdlib.h>

uint8_t *ptr;
int sum;
int i;
int min_pix;
int max_pix;
uint8_t c;

static uint8_t data[1 << 20]; // 1MB of data

void init_vars() {
    ptr = data;
    sum = 0;
    i = 0;
    min_pix = 255;
    max_pix = 0;
    c = 0;

    for (int j = 0; j < (1 << 20); j++) {
        data[j] = rand() & 0xFF;
    }
}