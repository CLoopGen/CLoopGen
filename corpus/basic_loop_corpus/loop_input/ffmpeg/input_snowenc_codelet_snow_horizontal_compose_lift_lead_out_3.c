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
    w = 65536; // ~131KB of data per array, total ~393KB, allows loop to run ~0.01s with reasonable workload
    mul = 3;
    add = 1;
    shift = 2;

    dst = (IDWTELEM*)aligned_alloc(32, sizeof(IDWTELEM) * (w + 1));
    src = (IDWTELEM*)aligned_alloc(32, sizeof(IDWTELEM) * (w + 1));
    ref = (IDWTELEM*)aligned_alloc(32, sizeof(IDWTELEM) * (w + 2)); // +2 to allow ref[i+1] at last index

    for (int j = 0; j < w; j++) {
        src[j] = (IDWTELEM)(j % 32768);
        ref[j] = (IDWTELEM)((j * 2) % 32768);
    }
    ref[w] = (IDWTELEM)((w * 2) % 32768); // initialize last required element for ref[i+1]

    i = 0;
}