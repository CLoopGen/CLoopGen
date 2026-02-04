#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char OPJ_BYTE;

typedef uint32_t OPJ_UINT32;

extern OPJ_BYTE *p_buffer;
extern OPJ_UINT32 p_nb_bytes;
extern  OPJ_BYTE *l_data_ptr;
extern OPJ_UINT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access, processing every 4th byte (unrolled pattern with stride)
    // Assumes p_nb_bytes is a multiple of 4 for simplicity and correctness
    OPJ_UINT32 stride = 4;
    OPJ_UINT32 unroll_factor = 4;
    OPJ_UINT32 limit = (p_nb_bytes / unroll_factor) * unroll_factor;

    for (i = 0; i < limit; i += unroll_factor) {
        p_buffer[i + 0] = l_data_ptr[p_nb_bytes - 1 - i - 0];
        p_buffer[i + 1] = l_data_ptr[p_nb_bytes - 1 - i - 1];
        p_buffer[i + 2] = l_data_ptr[p_nb_bytes - 1 - i - 2];
        p_buffer[i + 3] = l_data_ptr[p_nb_bytes - 1 - i - 3];
    }

    // Handle remaining bytes if p_nb_bytes is not a multiple of 4
    for (; i < p_nb_bytes; ++i) {
        p_buffer[i] = l_data_ptr[p_nb_bytes - 1 - i];
    }
}
