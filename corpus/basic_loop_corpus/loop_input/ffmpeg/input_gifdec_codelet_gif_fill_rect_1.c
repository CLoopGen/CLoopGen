#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t color = 0xFFAABBCC;
int l = 16;
int w = 1024;
int linesize = 2048;

static uint32_t *py_buffer;
static uint32_t *pb_buffer;
uint32_t *py;
uint32_t *pr;
uint32_t *pb;
uint32_t *px;

void init_vars() {
    size_t total_size = 16 * 1024 * 1024;
    size_t num_elements = total_size / sizeof(uint32_t);

    py_buffer = aligned_alloc(32, total_size);
    pb_buffer = py_buffer + num_elements;

    if (!py_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < num_elements; i++) {
        py_buffer[i] = 0;
    }

    py = py_buffer;
    pb = pb_buffer;
}