#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int size;
uint8_t *p;
unsigned int a;
unsigned int b;

static uint8_t *buffer;

void init_vars() {
    const size_t data_size = 16777216; // 16 MB, tuned for ~0.01 sec on modern CPU

    buffer = (uint8_t*)malloc(data_size);
    if (!buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        buffer[i] = (uint8_t)(i & 0xFF);
    }

    size = (unsigned int)data_size;
    p = buffer;
    a = 0;
    b = 0;
}