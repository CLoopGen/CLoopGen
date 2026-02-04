#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

OPJ_INT32 *restrict datap;
OPJ_UINT32 cblk_w;
OPJ_UINT32 cblk_h;
OPJ_UINT32 i;
OPJ_UINT32 j;

static OPJ_INT32 *data_buffer;

void init_vars() {
    cblk_w = 8192;
    cblk_h = 8192;
    size_t total_size = (size_t)cblk_w * cblk_h;

    data_buffer = (OPJ_INT32*)calloc(total_size, sizeof(OPJ_INT32));
    if (!data_buffer) {
        exit(1);
    }

    datap = data_buffer;
}