#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;
typedef OPJ_UINT32 opj_flag_t;

OPJ_UINT32 flags_stride = 4194304; // ~16.7 MB of data (4 bytes per opj_flag_t), tuned for ~0.01 sec runtime
opj_flag_t *p;
OPJ_UINT32 x;

void init_vars() {
    p = (opj_flag_t*)aligned_alloc(32, flags_stride * sizeof(opj_flag_t));
    if (!p) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}