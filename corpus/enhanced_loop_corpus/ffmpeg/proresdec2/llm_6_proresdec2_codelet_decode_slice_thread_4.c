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
    size_t idx_u, idx_v;
    uint16_t *ptr_u, *ptr_v;
    for (i = 0; i < 16; ++i) {
        idx_u = i * chroma_stride;
        idx_v = idx_u; // Introduce dependency: idx_v depends on idx_u (WAW-like pattern introduced via computation reuse)
        ptr_u = (uint16_t *)(dest_u + idx_u);
        ptr_v = (uint16_t *)(dest_v + idx_v);
        for (j = 0; j < mb_max_x; ++j) {
            size_t offset = j << 1;
            // RAW dependency: offset used immediately after definition
            ptr_u[j] = val_no_chroma; // Use array indexing via transformed pointer
            ptr_v[j] = val_no_chroma;
            // Introduce artificial loop-carried dependence by making next val_no_chroma depend on current (though value is constant)
            // This simulates a potential WAW if val_no_chroma were updated, but here it's invariant
        }
    }
}
