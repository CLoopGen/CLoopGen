#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint16_t *top;
uint16_t *filtered_top;

void init_vars() {
    size_t data_size = 1 << 20;
    top = (uint16_t*)calloc(data_size, sizeof(uint16_t));
    filtered_top = (uint16_t*)calloc(64, sizeof(uint16_t));
    if (!top || !filtered_top) {
        exit(1);
    }
    top[-1] = 100;
    top[63] = 200;
}