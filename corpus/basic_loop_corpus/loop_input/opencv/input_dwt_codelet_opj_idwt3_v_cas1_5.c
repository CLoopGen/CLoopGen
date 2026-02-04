#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef size_t OPJ_SIZE_T;

OPJ_INT32 *tmp;
OPJ_INT32 len;
OPJ_SIZE_T stride;
OPJ_INT32 i;
OPJ_INT32 j;
OPJ_INT32 s1;
OPJ_INT32 s2;
OPJ_INT32 dc;
OPJ_INT32 dn;
OPJ_INT32 *in_even;
OPJ_INT32 *in_odd;

void init_vars() {
    len = 1 << 24; // Approximately 16.7 million iterations, adjust for ~0.01s runtime
    stride = 1;
    tmp = (OPJ_INT32*)aligned_alloc(32, (size_t)len * sizeof(OPJ_INT32));
    in_even = (OPJ_INT32*)aligned_alloc(32, ((size_t)(len / 2) + 2) * stride * sizeof(OPJ_INT32));
    in_odd = (OPJ_INT32*)aligned_alloc(32, ((size_t)(len / 2) + 1) * stride * sizeof(OPJ_INT32));

    for (OPJ_SIZE_T idx = 0; idx < ((size_t)(len / 2) + 2) * stride; idx++) {
        in_even[idx] = idx % 256;
    }
    for (OPJ_SIZE_T idx = 0; idx < ((size_t)(len / 2) + 1) * stride; idx++) {
        in_odd[idx] = idx % 256;
    }

    i = 0;
    j = 0;
    s1 = in_even[stride];
    s2 = in_even[2 * stride];
    dc = 0;
    dn = 0;
}