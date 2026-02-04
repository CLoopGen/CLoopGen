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
    for (i = 0; i < 16; ++i) {
        size_t offset_u = (size_t)(dest_u + i * chroma_stride);
        size_t offset_v = (size_t)(dest_v + i * chroma_stride);
        for (j = 0; j < mb_max_x; ++j) {
            if ((i & 1) == 0) { // Introduce control dependency: only even i rows are processed
                *(uint16_t *)(offset_u + (j << 1)) = val_no_chroma;
                *(uint16_t *)(offset_v + (j << 1)) = val_no_chroma;
            }
        }
    }
}
