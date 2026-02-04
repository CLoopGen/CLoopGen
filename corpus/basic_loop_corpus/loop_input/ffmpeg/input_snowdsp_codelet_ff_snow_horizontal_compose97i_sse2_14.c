#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;
typedef int x86_reg;

IDWTELEM *b;
IDWTELEM *temp;
int w_r;
int i;
IDWTELEM *src;

#define DATA_SIZE (128 << 20) // 128 MB of data

void init_vars() {
    w_r = DATA_SIZE / sizeof(IDWTELEM);
    b = (IDWTELEM*)aligned_alloc(32, w_r * 2 * sizeof(IDWTELEM)); // extra space for b[i+1]
    temp = (IDWTELEM*)aligned_alloc(32, w_r * sizeof(IDWTELEM));
    src = (IDWTELEM*)aligned_alloc(32, w_r * sizeof(IDWTELEM));

    if (!b || !temp || !src) {
        exit(1);
    }

    for (int j = 0; j < w_r; j++) {
        src[j] = (IDWTELEM)(j & 0xFF);
        b[j] = (IDWTELEM)((j + 1) & 0xFF);
    }
    // Ensure b[i+1] is safe by initializing one extra element
    b[w_r] = 1;

    i = 0;
}