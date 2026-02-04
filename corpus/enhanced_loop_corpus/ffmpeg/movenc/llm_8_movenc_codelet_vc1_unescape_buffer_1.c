#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = size - (size % 4); // Align to multiple of 4 for unrolled processing
    for (i = 0; i < limit; i += 4, src += 4) {
        // Unroll loop and process 4 elements per iteration to increase computational intensity
        for (int j = 0; j < 4; j++) {
            if ((i + j) >= 2 && (i + j) < size - 1 &&
                src[j] == 3 && !src[j-1] && !src[j-2] && src[j+1] < 4) {
                dst[dsize++] = src[j+1];
                j++; // Skip next element in logical sense
            } else if (j < 4) {
                dst[dsize++] = src[j];
            }
        }
    }
    // Handle remaining elements
    for (; i < size; i++, src++) {
        if (src[0] == 3 && i >= 2 && !src[-1] && !src[-2] && i < size - 1 && src[1] < 4) {
            dst[dsize++] = src[1];
            src++;
            i++;
        } else
            dst[dsize++] = *src;
    }
}
