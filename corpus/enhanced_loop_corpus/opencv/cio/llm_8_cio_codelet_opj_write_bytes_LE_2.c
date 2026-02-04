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
    OPJ_UINT32 step = 2;
    for (i = 0; i < p_nb_bytes; i += step) {
        if (i + 0 < p_nb_bytes) {
            *(p_buffer++) = *(l_data_ptr--);
        }
        if (i + 1 < p_nb_bytes) {
            *(p_buffer++) = *(l_data_ptr--);
        }
    }
}
