#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t dpitch;
extern  int16_t *ref_buf;
extern ptrdiff_t pitch;
extern int i;
extern int j;
extern  int16_t *wptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with transposed iteration order
    // Iterate over j first, then i, creating stride-dpitch and stride-pitch access patterns
    // This changes spatial locality and accesses memory with larger strides
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            int16_t *current_buf = buf + i * dpitch + j;
            int16_t *current_ref = ref_buf + i * pitch + j;
            int16_t *current_wptr = wptr + i * pitch + j;
            (*current_buf) += ((*current_ref + *current_wptr) >> 1);
        }
    }
}
