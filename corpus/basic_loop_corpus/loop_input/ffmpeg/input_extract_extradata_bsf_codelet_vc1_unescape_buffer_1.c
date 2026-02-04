#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int size;
uint8_t *dst;
int dsize;
int i;

static uint8_t src_buffer[131072];
static uint8_t dst_buffer[131072];

void init_vars() {
    size = 65536;
    dsize = 0;
    i = 0;

    for (int idx = 0; idx < size; idx++) {
        if (idx >= 2 && idx < size - 1) {
            if (rand() % 100 == 0) {
                src_buffer[idx] = 3;
                src_buffer[idx - 1] = 0;
                src_buffer[idx - 2] = 0;
                src_buffer[idx + 1] = rand() % 4;
                idx += 1;
            } else {
                src_buffer[idx] = rand() % 256;
            }
        } else {
            src_buffer[idx] = rand() % 256;
        }
    }

    src = src_buffer;
    dst = dst_buffer;
}