#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;
typedef JLONG DCTELEM;

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

static DCTELEM data_buffer[8 * 32768];

void init_vars() {
    for (int i = 0; i < 8 * 32768; i++) {
        data_buffer[i] = (DCTELEM)(i * 71 % 1000);
    }
    dataptr = data_buffer;
}