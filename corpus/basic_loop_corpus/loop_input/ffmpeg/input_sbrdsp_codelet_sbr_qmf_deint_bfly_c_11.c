#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float INTFLOAT;

INTFLOAT *v;
INTFLOAT *src0;
INTFLOAT *src1;
int i;

static INTFLOAT v_data[128];
static INTFLOAT src0_data[64];
static INTFLOAT src1_data[64];

void init_vars() {
    v = v_data;
    src0 = src0_data;
    src1 = src1_data;

    for (int j = 0; j < 64; j++) {
        src0[j] = (INTFLOAT)(j * 2);
        src1[j] = (INTFLOAT)(j * 3 + 1);
    }

    for (int j = 0; j < 128; j++) {
        v[j] = 0.0f;
    }
}