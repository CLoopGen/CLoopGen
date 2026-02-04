#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int i;
uint8_t map4to8[16];

static uint8_t *internal_buf;

void init_vars() {
    internal_buf = (uint8_t *)malloc(16);
    if (!internal_buf) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int j = 0; j < 16; j++) {
        internal_buf[j] = (uint8_t)(j * 0x11);
    }
    buf = internal_buf;
    i = 0;
}