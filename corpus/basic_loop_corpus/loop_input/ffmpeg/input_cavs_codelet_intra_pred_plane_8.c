#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
uint8_t *left;
int x;
int ih;
int iv;

static uint8_t top_data[10];
static uint8_t left_data[10];

void init_vars() {
    top = top_data;
    left = left_data;
    ih = 0;
    iv = 0;
    x = 0;

    for (int i = 0; i < 10; i++) {
        top_data[i] = rand() % 256;
        left_data[i] = rand() % 256;
    }
}