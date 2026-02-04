#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char OPJ_BYTE;
typedef uint32_t OPJ_UINT32;

OPJ_BYTE *p_buffer;
OPJ_UINT32 p_nb_bytes;
OPJ_BYTE *l_data_ptr;
OPJ_UINT32 i;

static OPJ_BYTE *buffer_pool = NULL;
static size_t total_size = 0;

void init_vars() {
    total_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    buffer_pool = (OPJ_BYTE*)calloc(total_size + 1, sizeof(OPJ_BYTE));
    if (!buffer_pool) exit(1);

    p_buffer = buffer_pool;
    p_nb_bytes = total_size;

    l_data_ptr = &buffer_pool[total_size - 1];
}