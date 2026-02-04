#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB

static unsigned short p_data[DATA_SIZE / sizeof(unsigned short)];
static unsigned short q_data[DATA_SIZE / sizeof(unsigned short)];

unsigned short *p = p_data;
unsigned short *q = q_data + (DATA_SIZE / sizeof(unsigned short)) - 1;
int j;

void init_vars() {
    for (size_t i = 0; i < (DATA_SIZE / sizeof(unsigned short)); i++) {
        p_data[i] = (unsigned short)(i & 0xFFFF);
    }
    memset(q_data, 0, DATA_SIZE);
}