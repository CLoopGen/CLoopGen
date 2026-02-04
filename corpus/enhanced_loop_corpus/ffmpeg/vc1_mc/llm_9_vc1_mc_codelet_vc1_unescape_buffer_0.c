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
    for (i = 0; i < size - (size % 4); i += 2, src += 2) {
        if (i + 2 < size && src[0] == 3 && i >= 2 && !src[-1] && !src[-2] && src[1] < 4) {
            dst[dsize++] = src[1];
            i++;
            src++;
        } else {
            dst[dsize++] = *src;
            if (i + 1 < size) {
                dst[dsize++] = src[1];
            }
        }
    }
    // Handle remaining elements
    for (; i < size; i++, src++) {
        dst[dsize++] = *src;
    }
}
