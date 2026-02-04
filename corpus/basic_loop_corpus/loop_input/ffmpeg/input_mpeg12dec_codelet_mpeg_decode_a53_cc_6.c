#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *p;
int buf_size;
int cc_count;
int i;

static uint8_t *buffer_storage;

void init_vars() {
    buf_size = 64 * 1024 * 1024; // 64 MB to ensure ~0.01 sec runtime on modern CPU
    buffer_storage = (uint8_t *)calloc(buf_size, sizeof(uint8_t));
    if (!buffer_storage) {
        exit(1);
    }
    p = buffer_storage;

    for (int j = 0; j < buf_size; j += 6) {
        if (j + 5 < buf_size) {
            p[j] = 254; 
        } else {
            break;
        }
    }

    cc_count = 0;
    i = 0;
}