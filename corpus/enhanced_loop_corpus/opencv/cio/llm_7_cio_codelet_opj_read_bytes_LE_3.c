#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char OPJ_BYTE;

typedef uint32_t OPJ_UINT32;

extern  OPJ_BYTE *p_buffer;
extern OPJ_UINT32 p_nb_bytes;
extern OPJ_BYTE *l_data_ptr;
extern OPJ_UINT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_BYTE temp[8];
    OPJ_UINT32 chunk_size = 8;
    OPJ_UINT32 remaining = p_nb_bytes % chunk_size;
    OPJ_UINT32 limit = p_nb_bytes - remaining;

    for (i = 0; i < limit; i += chunk_size) {
        for (OPJ_UINT32 k = 0; k < chunk_size; ++k) {
            temp[k] = p_buffer[i + k];
        }
        for (OPJ_UINT32 k = 0; k < chunk_size; ++k) {
            *(l_data_ptr--) = temp[chunk_size - 1 - k];
        }
    }

    for (; i < p_nb_bytes; ++i) {
        *(l_data_ptr--) = *(p_buffer++);
    }
}
