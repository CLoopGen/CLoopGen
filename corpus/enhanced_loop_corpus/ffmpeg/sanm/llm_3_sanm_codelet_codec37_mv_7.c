#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int height;
extern int stride;
extern int pos;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed inner loop and offset adjustment
    int base_src = 0;
    for (j = 0; j < 4; j++) {
        for (i = 3; i >= 0; i--) {  // Reverse traversal
            int offset = i;
            if ((pos + offset) < 0 || (pos + offset) >= height * stride)
                dst[3 - i] = 0;  // Mirror write due to reverse read
            else
                dst[3 - i] = src[offset];
        }
        dst += stride;
        src += stride;
        pos += stride;
    }
}
