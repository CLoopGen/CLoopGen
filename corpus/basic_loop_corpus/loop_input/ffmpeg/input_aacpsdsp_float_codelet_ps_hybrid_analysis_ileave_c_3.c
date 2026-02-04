#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef float INTFLOAT;

INTFLOAT (*out)[32][2];
INTFLOAT L[2][38][64];
int i;
int len;
int j;

void init_vars() {
    len = 32;

    size_t out_size = 64 * 32 * 2 * sizeof(INTFLOAT);
    out = aligned_alloc(32, out_size);
    if (!out) exit(1);
    memset(out, 0, out_size);

    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 38; b++)
            for (int c = 0; c < 64; c++) {
                L[a][b][c] = (INTFLOAT)(a * 10000 + b * 100 + c);
            }

    i = 0;
    j = 0;
}