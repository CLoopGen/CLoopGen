#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *y_start;
extern int trans;
extern  int w;
extern int is_trans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    // Here we assume a virtual "index map" generated on-the-fly as i itself offset by a base
    int base_offset = linesize * *y_start;
    for (int idx = 0; idx < w; idx++) {
        int mapped_index = idx; // Could be randomized or reordered in real use; kept sequential here for determinism
        if (buf[base_offset + mapped_index] != trans) {
            is_trans = 0;
            break;
        }
    }
}
