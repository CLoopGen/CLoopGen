#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float INTFLOAT;
typedef float UINTFLOAT;

INTFLOAT *dst;
INTFLOAT (*src)[2];
int n = 0;
int i = 0;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t floats_per_mb = (1 << 20) / sizeof(INTFLOAT);
    n = data_size_mb * floats_per_mb;

    src = aligned_alloc(32, n * sizeof(*src));
    dst = aligned_alloc(32, n * sizeof(*dst));

    for (int idx = 0; idx < n; idx++) {
        src[idx][0] = (UINTFLOAT)(idx % 128) * 0.01f;
        src[idx][1] = (UINTFLOAT)((idx + 1) % 128) * 0.01f;
        dst[idx] = (UINTFLOAT)1.0f;
    }
}