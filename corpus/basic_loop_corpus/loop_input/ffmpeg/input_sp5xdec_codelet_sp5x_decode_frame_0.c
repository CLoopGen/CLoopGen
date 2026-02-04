#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int buf_size;
uint8_t *recoded;
int i;
int j;

void init_vars() {
    buf_size = 64 * 1024 * 1024; // 64 MB input size for ~0.01 sec runtime on modern CPU
    buf = (uint8_t*)malloc(buf_size * sizeof(uint8_t));
    recoded = (uint8_t*)malloc((buf_size + 1024) * sizeof(uint8_t));

    if (!buf || !recoded) {
        exit(1);
    }

    for (int k = 0; k < buf_size; k++) {
        buf[k] = (uint8_t)(k & 0xFF);
    }

    i = 2;
    j = 0;
}