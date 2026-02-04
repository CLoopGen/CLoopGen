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
    buf_size = 128 * 1024 * 1024; // 128 MB input data
    buf = (uint8_t*)malloc(buf_size);
    recoded = (uint8_t*)malloc(buf_size + 1024);

    if (!buf || !recoded) {
        exit(1);
    }

    for (int k = 0; k < buf_size; k++) {
        buf[k] = rand() % 256;
    }

    i = 14;
    j = 0;
}