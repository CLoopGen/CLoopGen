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
    size_t idx;
    for (i = 0; i < 16; ++i) {
        idx = i * chroma_stride;
        uint8_t *du_row = dest_u + idx;
        uint8_t *dv_row = dest_v + idx;
        for (j = 0; j < mb_max_x; ++j) {
            *(uint16_t *)(du_row + (j << 1)) = val_no_chroma;
            *(uint16_t *)(dv_row + (j << 1)) = val_no_chroma;
        }
    }
}
