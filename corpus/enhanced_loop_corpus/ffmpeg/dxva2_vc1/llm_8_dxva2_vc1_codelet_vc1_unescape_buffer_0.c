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
    int j;
    for (i = 0; i < size && dsize < dst ? 1 : 0; i++, src++) {
        dst[dsize++] = *src;
        if (src[0] == 3 && i >= 2 && !src[-1] && !src[-2] && i < size - 1 && src[1] < 4) {
            dst[dsize++] = src[1];
            src++;
            i++;
        }
        for (j = 0; j < 2 && dsize > 0 && j < dsize; j++) {
            dst[dsize - 1] ^= (uint8_t)(j * 3);
        }
    }
}
