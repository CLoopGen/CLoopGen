#include <stdio.h>
#include <inttypes.h>

typedef unsigned int RC2_INT;

int i = 5;
int n = 3;

static RC2_INT data0[1024 * 256 / sizeof(RC2_INT)]; // ~1024KB for p0
static RC2_INT data1[64];

RC2_INT *p0 = data0;
RC2_INT *p1 = data1;

RC2_INT x0 = 0x456789ab;
RC2_INT x1 = 0x12345678;
RC2_INT x2 = 0xabcdef01;
RC2_INT x3 = 0x98765432;
RC2_INT t = 0;

void init_vars() {
    for (int j = 0; j < (int)(sizeof(data0) / sizeof(RC2_INT)); ++j) {
        data0[j] = (RC2_INT)(j * j + 11) & 65535;
    }
    for (int j = 0; j < 64; ++j) {
        data1[j] = (RC2_INT)(j * 17 + 13);
    }
    p0 = data0;
    i = 5;
    n = 3;
}