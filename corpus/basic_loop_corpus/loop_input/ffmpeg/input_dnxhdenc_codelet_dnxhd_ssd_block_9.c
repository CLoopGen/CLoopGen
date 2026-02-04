#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *qblock;
int16_t *block;
int score;
int i;

#define DATA_SIZE (1 << 20)  // 1MB of data: 512K int16_t elements per array

static int16_t block_data[DATA_SIZE / sizeof(int16_t)];
static int16_t qblock_data[DATA_SIZE / sizeof(int16_t)];

void init_vars() {
    for (int j = 0; j < (int)(DATA_SIZE / sizeof(int16_t)); j++) {
        block_data[j] = rand() % 1024 - 512;
        qblock_data[j] = rand() % 1024 - 512;
    }
    block = block_data;
    qblock = qblock_data;
    score = 0;
    i = 0;
}