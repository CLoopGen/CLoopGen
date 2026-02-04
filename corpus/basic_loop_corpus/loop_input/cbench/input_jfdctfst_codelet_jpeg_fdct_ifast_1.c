#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int DCTELEM;
typedef long INT32;

DCTELEM tmp0;
DCTELEM tmp1;
DCTELEM tmp2;
DCTELEM tmp3;
DCTELEM tmp4;
DCTELEM tmp5;
DCTELEM tmp6;
DCTELEM tmp7;
DCTELEM tmp10;
DCTELEM tmp11;
DCTELEM tmp12;
DCTELEM tmp13;
DCTELEM z1;
DCTELEM z2;
DCTELEM z3;
DCTELEM z4;
DCTELEM z5;
DCTELEM z11;
DCTELEM z13;
DCTELEM *dataptr;
int ctr;

static DCTELEM data_buffer[2097152]; // ~8MB buffer to ensure safe access

void init_vars() {
    size_t i;
    for (i = 0; i < sizeof(data_buffer)/sizeof(DCTELEM); i++) {
        data_buffer[i] = (DCTELEM)(i % 256 - 128);
    }
    dataptr = data_buffer;
}