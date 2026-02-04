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
    for (i = 0; i < size;) { // Flattened structure: removed increment from for-loop header, managed inside body
        if (src[0] == 3 && i >= 2 && !src[-1] && !src[-2] && i < size - 1 && src[1] < 4) {
            dst[dsize++] = src[1];
            src += 2; // Advance source pointer by two
            i += 2;   // Skip two indices
        } else {
            dst[dsize++] = *src;
            src++;
            i++;
        }
    }
}
