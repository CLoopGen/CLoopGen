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
    size_t total_elements = 16 * mb_max_x;
    size_t stride = chroma_stride >> 1; // Since we write uint16_t, step in units of 2 bytes
    uint16_t *du16 = (uint16_t*)dest_u;
    uint16_t *dv16 = (uint16_t*)dest_v;
    for (size_t idx = 0; idx < total_elements; ++idx) {
        size_t mb_idx = idx % mb_max_x;
        size_t row_idx = idx / mb_max_x;
        size_t offset = row_idx * stride + mb_idx;
        du16[offset] = val_no_chroma;
        dv16[offset] = val_no_chroma;
    }
}
