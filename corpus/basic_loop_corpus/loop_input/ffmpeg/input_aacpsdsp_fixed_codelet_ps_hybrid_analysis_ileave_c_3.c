#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int INTFLOAT;

INTFLOAT (*out)[32][2];
INTFLOAT L[2][38][64];
int i;
int len;
int j;

void init_vars() {
    len = 32;
    i = 0;
    j = 0;

    // Allocate output buffer: [64][32][2]
    out = (INTFLOAT(*)[32][2])calloc(64 * 32 * 2, sizeof(INTFLOAT));
    
    // Allocate and initialize L[2][38][64]
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 38; b++) {
            for (int c = 0; c < 64; c++) {
                L[a][b][c] = rand() % 1000;
            }
        }
    }

    // Initialize output memory to zero (already done by calloc)
}