#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int stride;
int width;
int height;
int i;
int code;
int filled;
int p;

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t data_buffer[DATA_SIZE];

void init_vars() {
    width = 1920;
    height = 1080;
    stride = width + 32; // Add padding to simulate image stride
    code = (width * height) - 1;
    filled = 0;
    p = 42;

    dst = data_buffer + (DATA_SIZE - (stride * height)); // Point to beginning of image area
}