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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed traversal
    // Access pattern modified to stride by 2 and traverse backwards to increase data access distance and alter cache behavior.
    for (i = 0; i < 8; i++, buf += dpitch, ref_buf += pitch) {
        for (j = 6; j >= 0; j -= 2) {  // Reverse order, stride of 2
            buf[j]     = (ref_buf[j] + ref_buf[j + 1]) >> 1;
            buf[j + 1] = (ref_buf[j + 1] + ref_buf[j + 2]) >> 1;
        }
    }
}
