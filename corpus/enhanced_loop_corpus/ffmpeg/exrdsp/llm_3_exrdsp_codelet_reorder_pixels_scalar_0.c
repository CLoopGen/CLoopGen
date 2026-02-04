#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *t1;
extern int half_size;
extern  uint8_t *t2;
extern uint8_t *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every 4th element in chunks (unrolled stride pattern)
    // This variant assumes half_size is a multiple of 4 for simplicity and performance
    int stride = 4;
    for (i = 0; i < half_size; i += stride) {
        // Process four iterations at once with strided writes to s
        int base_s = 2 * i;
        s[base_s]           = t1[i];
        s[base_s + 1]       = t2[i];
        if (i + 1 < half_size) {
            s[base_s + 2]   = t1[i + 1];
            s[base_s + 3]   = t2[i + 1];
        }
        if (i + 2 < half_size) {
            s[base_s + 4]   = t1[i + 2];
            s[base_s + 5]   = t2[i + 2];
        }
        if (i + 3 < half_size) {
            s[base_s + 6]   = t1[i + 3];
            s[base_s + 7]   = t2[i + 3];
        }
    }
}
