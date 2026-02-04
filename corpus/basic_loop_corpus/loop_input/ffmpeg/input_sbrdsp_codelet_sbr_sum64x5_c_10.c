#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float INTFLOAT;

INTFLOAT *z;
int k;

static INTFLOAT z_data[320]; // 256 + 64 to cover max access at k=63: 63+256 = 319

void init_vars() {
    z = z_data;
    for (int i = 0; i < 320; i++) {
        z[i] = (INTFLOAT)(i % 128);
    }
}