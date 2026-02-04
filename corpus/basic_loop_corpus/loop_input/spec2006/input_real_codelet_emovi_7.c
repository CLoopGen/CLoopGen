#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (128 * 1024 * 1024)

unsigned short *p;
unsigned short *q;
int i;

static unsigned short data_p[DATA_SIZE / sizeof(unsigned short)];
static unsigned short data_q[DATA_SIZE / sizeof(unsigned short)];

void init_vars() {
    p = &data_p[DATA_SIZE / sizeof(unsigned short) - 1];
    q = data_q;
    i = 0;
    memset(data_p, 0x55, DATA_SIZE);
    memset(data_q, 0, DATA_SIZE);
}