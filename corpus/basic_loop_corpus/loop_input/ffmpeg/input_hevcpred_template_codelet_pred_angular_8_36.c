#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int size;
int x;
int y;
uint8_t *src;
int angle;
uint8_t *ref;

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * 1024 * 1024)

static uint8_t src_buffer[ARRAY_SIZE];
static uint8_t ref_buffer[ARRAY_SIZE + 128]; // Extra padding to prevent out-of-bounds

void init_vars() {
    size = 4096;
    while (size * size > ARRAY_SIZE) {
        size -= 1;
    }
    stride = size;
    angle = 16; 
    src = src_buffer;
    ref = ref_buffer;
    x = 0;
    y = 0;
}