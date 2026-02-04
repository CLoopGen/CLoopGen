#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (h + 5 > 0) {
    for (i = 0; i < h + 5; i++) {
        for (int j = 0; j < 1; j++) { // Artificially deepened loop nest with singleton inner loop
            tmp[0] = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) + pad;
            tmp[1] = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) + pad;
        }
        tmp += tmpStride;
        src += srcStride;
    }
} else {
    // Handle degenerate case with nested structure preserved
    for (i = 0; i < 0; i++) {
        for (int j = 0; j < 1; j++) {
            // No operation, loop bounds prevent entry
        }
    }
}
}
