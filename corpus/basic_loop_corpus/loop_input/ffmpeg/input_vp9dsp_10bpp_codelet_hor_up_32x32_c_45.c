#include <stdint.h>
#include <stdlib.h>

uint16_t *left;
int i;
uint16_t v[62];

static uint16_t left_data[32];

void init_vars() {
    left = left_data;
    for (int j = 0; j < 32; j++) {
        left[j] = (uint16_t)(j * 789);
    }
    for (int j = 0; j < 62; j++) {
        v[j] = 0;
    }
    i = 0;
}