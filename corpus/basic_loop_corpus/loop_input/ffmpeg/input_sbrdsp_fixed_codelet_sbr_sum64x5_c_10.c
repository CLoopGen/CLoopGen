#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int INTFLOAT;

INTFLOAT *z;
int k;

static INTFLOAT z_data[320]; // 256 + 64 = 320 to cover max index k + 256 when k=63

void init_vars() {
    z = z_data;
    for (int i = 0; i < 320; i++) {
        z[i] = rand() % 1000;
    }
}