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
    OPJ_UINT32 limit = p_nb_bytes >> 1;
    for (i = 0; i < limit; ++i) {
        OPJ_BYTE temp1 = *(l_data_ptr--);
        OPJ_BYTE temp2 = *(l_data_ptr--);
        *(p_buffer++) = temp1;
        *(p_buffer++) = temp2;
    }
    if (p_nb_bytes & 1) {
        *(p_buffer++) = *(l_data_ptr--);
    }
}
