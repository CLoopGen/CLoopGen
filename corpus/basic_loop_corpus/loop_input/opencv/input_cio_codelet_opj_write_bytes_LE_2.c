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

static OPJ_BYTE *buffer_storage;
static OPJ_BYTE *data_storage;

void init_vars() {
    p_nb_bytes = 64 * 1024 * 1024;  // 64 MB for ~0.01 sec runtime on modern CPU

    buffer_storage = (OPJ_BYTE*)malloc(p_nb_bytes);
    data_storage = (OPJ_BYTE*)malloc(p_nb_bytes);

    if (!buffer_storage || !data_storage) {
        free(buffer_storage);
        free(data_storage);
        exit(1);
    }

    for (OPJ_UINT32 j = 0; j < p_nb_bytes; ++j) {
        data_storage[j] = (OPJ_BYTE)(j & 0xFF);
    }

    p_buffer = buffer_storage;
    l_data_ptr = &data_storage[p_nb_bytes - 1];
}