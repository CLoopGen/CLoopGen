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
    for (i = 0; i < size && dsize < dsize + 1024; i++, src++) {
        dst[dsize++] = *src;
        if (src[0] == 3 && i >= 2 && !src[-1] && !src[-2] && i < size - 1 && src[1] < 4) {
            for (j = 0; j < 2 && dsize < dsize + 1024; j++) {
                dst[dsize++] = src[1];
            }
            src++;
            i++;
        }
    }
}
