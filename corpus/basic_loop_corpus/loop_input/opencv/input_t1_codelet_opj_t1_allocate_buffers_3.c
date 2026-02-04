#include <stdint.h>

typedef uint32_t OPJ_UINT32;
typedef OPJ_UINT32 opj_flag_t;

OPJ_UINT32 flags_stride = 2097152; // ~8MB of data (2M * 4 bytes), target ~0.01 sec runtime
opj_flag_t *p;
OPJ_UINT32 x = 0;

static opj_flag_t p_storage[2097152];

void init_vars() {
    p = p_storage;
}