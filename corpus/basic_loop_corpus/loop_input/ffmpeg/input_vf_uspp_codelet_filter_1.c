#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
int height;
uint8_t *qp_store;
int qp_stride;
int x;
int y;
int qpsum;

void init_vars() {
    width = 4096;
    height = 4096;
    qp_stride = width >> 4;
    size_t alloc_size = ((height >> 4) * qp_stride);
    qp_store = (uint8_t*)calloc(alloc_size, sizeof(uint8_t));
    if (!qp_store) {
        exit(1);
    }
    for (size_t i = 0; i < alloc_size; i++) {
        qp_store[i] = rand() & 0xFF;
    }
    x = 0;
    y = 0;
    qpsum = 0;
}