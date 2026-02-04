#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int chroma_stride;
extern uint8_t *dest_u;
extern uint8_t *dest_v;
extern uint16_t val_no_chroma;
extern size_t mb_max_x;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i += 2) {
        for (j = 0; j < mb_max_x; ++j) {
            size_t idx = (i * chroma_stride) + (j << 1);
            uint16_t* ptr_u = (uint16_t*)(dest_u + idx);
            uint16_t* ptr_v = (uint16_t*)(dest_v + idx);
            *ptr_u = val_no_chroma;
            *ptr_v = val_no_chroma;
            *ptr_u = val_no_chroma; // Extra operation to increase computational intensity
        }
    }
}
