#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *top;
uint16_t *left;
int i;
uint16_t v[22];

static uint16_t top_data[10];
static uint16_t left_data[10];

void init_vars() {
    for (int j = 0; j < 10; j++) {
        top_data[j] = (uint16_t)(j * 31);
        left_data[j] = (uint16_t)(j * 17);
    }

    top = top_data;
    left = left_data;

    for (int j = 0; j < 22; j++) {
        v[j] = 0;
    }

    i = 0;
}