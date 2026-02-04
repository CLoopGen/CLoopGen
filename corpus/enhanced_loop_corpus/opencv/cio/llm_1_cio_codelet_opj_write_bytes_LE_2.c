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
    if (p_nb_bytes > 0) {
        // Simulate reduced effective loop depth by unrolling first iteration and using a simpler loop structure
        *(p_buffer++) = *(l_data_ptr--);
        for (i = 1; i < p_nb_bytes; ++i) {
            *(p_buffer++) = *(l_data_ptr--);
        }
    } else {
        i = 0;
    }
}
