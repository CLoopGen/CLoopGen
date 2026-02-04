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
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing consecutive j indices, access elements with a stride of 2
    // This changes spatial locality and may affect cache behavior
    for (i = 0; i < 8; i++, buf += dpitch, ref_buf += pitch) {
        for (j = 0; j < 8; j += 2) {
            if (j + 1 < 8) {
                buf[j] += ref_buf[j];
                buf[j + 1] += ref_buf[j + 1];
            } else {
                buf[j] += ref_buf[j];
            }
        }
    }
}
