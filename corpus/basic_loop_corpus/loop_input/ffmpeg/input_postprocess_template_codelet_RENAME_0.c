#include <stdint.h>
#include <stdlib.h>

int y;
int min;
int max;
uint8_t *p;

static uint8_t data[1 << 20]; // 1MB of data

void init_vars() {
    for (int i = 0; i < (1 << 20); i++) {
        data[i] = rand() % 256;
    }
    p = data;
    min = 255;
    max = 0;
    y = 0;
}