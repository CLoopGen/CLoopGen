#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *plane;
ptrdiff_t plane_stride;
int w;
int h;
uint8_t *p;
uint8_t a;
uint8_t b;
int i;
int j;

static uint8_t *allocated_memory;

void init_vars() {
    w = 4096;
    h = 4096;
    plane_stride = w;
    size_t total_size = (size_t)w * h;

    allocated_memory = calloc(total_size, sizeof(uint8_t));
    if (!allocated_memory) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        allocated_memory[idx] = rand() & 0xFF;
    }

    plane = allocated_memory;
    p = NULL;
    a = 0;
    b = 0;
    i = 0;
    j = 0;
}