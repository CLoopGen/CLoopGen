#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *iv;
uint8_t indexbuf[8];
int i;

static uint8_t *iv_storage;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data

    iv_storage = calloc(data_size, sizeof(uint8_t));
    if (!iv_storage) {
        exit(1);
    }

    iv = iv_storage;
    for (int j = 0; j < 8; j++) {
        indexbuf[j] = (uint8_t)(j + 1);
    }
}