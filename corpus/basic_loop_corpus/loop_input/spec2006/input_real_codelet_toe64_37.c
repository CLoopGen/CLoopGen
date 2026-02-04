#include <stdint.h>
#include <stdlib.h>

#define DATA_SIZE (128 * 1024 * sizeof(unsigned short))

unsigned short *p;
unsigned short *q;
unsigned short i;

static unsigned short buffer_p[DATA_SIZE / sizeof(unsigned short)];
static unsigned short buffer_q[DATA_SIZE / sizeof(unsigned short)];

void init_vars() {
    p = buffer_p + (DATA_SIZE / sizeof(unsigned short)) - 1;
    q = buffer_q + (DATA_SIZE / sizeof(unsigned short)) - 1;

    for (int j = 0; j < DATA_SIZE / sizeof(unsigned short); j++) {
        buffer_p[j] = (unsigned short)(j & 0xFFFF);
        buffer_q[j] = 0;
    }
}