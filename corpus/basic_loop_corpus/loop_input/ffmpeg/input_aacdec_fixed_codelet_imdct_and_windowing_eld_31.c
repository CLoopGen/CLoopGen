#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int UINTFLOAT;
typedef int INTFLOAT;

UINTFLOAT *in;
int i;
int n;
int n2;

static UINTFLOAT *in_storage;

void init_vars() {
    n = 1 << 20; // 1 million elements
    n2 = n / 2;
    in_storage = (UINTFLOAT*)aligned_alloc(32, n * sizeof(UINTFLOAT));
    if (!in_storage) {
        exit(1);
    }
    in = in_storage;

    for (int idx = 0; idx < n; ++idx) {
        in[idx] = (UINTFLOAT)(idx * 7919); // Arbitrary prime multiplier for variation
    }
}