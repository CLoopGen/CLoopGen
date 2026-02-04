#include <stdint.h>
#include <string.h>

#define DATA_SIZE (1 << 20) // 1MB of data

unsigned short *p;
unsigned short *q;
unsigned short i;

static unsigned short buffer_p[DATA_SIZE / sizeof(unsigned short)];
static unsigned short buffer_q[DATA_SIZE / sizeof(unsigned short)];

void init_vars() {
    p = buffer_p;
    q = buffer_q;
    i = 0;

    memset(buffer_p, 0x55, DATA_SIZE);
    memset(buffer_q, 0x00, DATA_SIZE);
}