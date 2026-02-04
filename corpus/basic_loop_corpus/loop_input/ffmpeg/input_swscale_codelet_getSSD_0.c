#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src1;
uint8_t *src2;
int stride1;
int stride2;
int w = 1024;
int h = 1024;
int x;
int y;
uint64_t ssd;

static uint8_t buffer1[1024 * 1024];
static uint8_t buffer2[1024 * 1024];

void init_vars() {
    stride1 = 1024;
    stride2 = 1024;

    src1 = buffer1;
    src2 = buffer2;

    for (int i = 0; i < 1024 * 1024; i++) {
        buffer1[i] = rand() % 256;
        buffer2[i] = rand() % 256;
    }

    ssd = 0;
}