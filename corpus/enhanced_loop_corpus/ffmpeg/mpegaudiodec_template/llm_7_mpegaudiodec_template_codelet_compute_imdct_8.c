#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *sb_samples;
extern int *out_ptr;
extern int *buf;
extern int i;
extern int j;
extern int sblimit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = sblimit; j < 32; j++) {
        int base_index = j;
        int stride = 32;
        int limit = 18;
        int conditional_offset = (j & 3) != 3 ? 1 : (4 * 18 - 3);
        for (i = 0; i < limit; i++) {
            int buf_index = 4 * i;
            int* sample_ptr = sb_samples + base_index + i * stride;
            *sample_ptr = buf[buf_index];
            buf[buf_index] = 0;
        }
        buf += conditional_offset;
    }
}
