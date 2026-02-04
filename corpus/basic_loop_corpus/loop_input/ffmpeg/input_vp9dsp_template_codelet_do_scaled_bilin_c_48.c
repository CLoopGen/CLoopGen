#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w;
int dx;
uint8_t *tmp_ptr;
uint8_t *src;
int x;
int imx;
int ioff;

static uint8_t *src_buffer;
static uint8_t *tmp_buffer;

void init_vars() {
    w = 16777216;  // ~16M iterations to target ~0.01 sec on modern CPU

    dx = 3;
    imx = 12;
    ioff = 0;

    size_t src_size = w * 2 + 16;  // Ensure enough room for ioff access: ioff + 1 max
    size_t tmp_size = w;

    src_buffer = (uint8_t*)calloc(src_size, sizeof(uint8_t));
    tmp_buffer = (uint8_t*)calloc(tmp_size, sizeof(uint8_t));

    if (!src_buffer || !tmp_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }

    tmp_ptr = tmp_buffer;
    src = src_buffer;
}

// Reset pointers and variables if needed in future calls
void loop();