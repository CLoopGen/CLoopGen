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
    OPJ_UINT32 j;
    for (i = 0; i < p_nb_bytes; ++i) {
        j = p_nb_bytes - 1 - i;
        p_buffer[i] = l_data_ptr[j];
    }
}
