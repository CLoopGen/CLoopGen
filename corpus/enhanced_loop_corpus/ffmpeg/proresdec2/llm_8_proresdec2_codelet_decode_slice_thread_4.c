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
    size_t stride = chroma_stride;
    for (i = 0; i < 8; ++i) {
        size_t base_u = i * stride;
        size_t base_v = i * stride;
        for (j = 0; j < mb_max_x; ++j) {
            size_t offset = j << 1;
            *(uint16_t *)(dest_u + base_u + offset) = val_no_chroma;
            *(uint16_t *)(dest_v + base_v + offset) = val_no_chroma;
        }
    }
}
