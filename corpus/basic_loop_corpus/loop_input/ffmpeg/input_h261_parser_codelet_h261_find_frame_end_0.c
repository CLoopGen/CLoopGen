#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int buf_size;
int vop_found;
int i;
int j;
uint32_t state;

void init_vars() {
    buf_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime on modern CPU
    buf = (uint8_t *)malloc(buf_size);
    if (!buf) {
        exit(1);
    }
    for (int k = 0; k < buf_size; k++) {
        buf[k] = rand() & 0xFF;
    }
    vop_found = 0;
    i = 0;
    j = 0;
    state = 0;
}