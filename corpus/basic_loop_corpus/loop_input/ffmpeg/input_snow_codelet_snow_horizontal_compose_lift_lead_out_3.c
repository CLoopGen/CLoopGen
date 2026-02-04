#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

int i;
IDWTELEM *dst;
IDWTELEM *src;
IDWTELEM *ref;
int w;
int mul;
int add;
int shift;

void init_vars() {
    w = 65536; // Size chosen to make loop run ~0.01s (approx 131KB total data)
    mul = 3;
    add = 1;
    shift = 2;
    i = 0;

    dst = (IDWTELEM*)aligned_alloc(32, sizeof(IDWTELEM) * w);
    src = (IDWTELEM*)aligned_alloc(32, sizeof(IDWTELEM) * w);
    ref = (IDWTELEM*)aligned_alloc(32, sizeof(IDWTELEM) * (w + 1));

    for (int j = 0; j < w; j++) {
        dst[j] = 0;
        src[j] = (IDWTELEM)(j % 32768);
        ref[j] = (IDWTELEM)((j * 2) % 32768);
    }
    ref[w] = (IDWTELEM)(w * 2 % 32768); // Initialize the last needed element for ref[i+1]
}