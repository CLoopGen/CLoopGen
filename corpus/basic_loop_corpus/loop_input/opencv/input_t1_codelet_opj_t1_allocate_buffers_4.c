#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;
typedef OPJ_UINT32 opj_flag_t;

OPJ_UINT32 flags_stride;
opj_flag_t *p;
OPJ_UINT32 x;
OPJ_UINT32 v;

static opj_flag_t *buffer;

void init_vars() {
    flags_stride = 67108864; // 64M elements * 4 bytes = 256MB, target ~0.01s on modern CPU
    v = 0xDEADBEEF;
    buffer = (opj_flag_t*)aligned_alloc(32, flags_stride * sizeof(opj_flag_t));
    if (!buffer) {
        exit(1);
    }
    p = buffer;
}