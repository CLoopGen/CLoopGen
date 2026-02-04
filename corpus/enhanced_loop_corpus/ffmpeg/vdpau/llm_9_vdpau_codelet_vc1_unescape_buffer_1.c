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
        if (i >= 2 && src[0] == 3 && !src[-1] && !src[-2] && i < size - 1 && src[1] < 4) {
            dst[dsize++] = src[1];
            if (i + 1 < size - 1 && src[2] == 3 && !src[1] && !src[0] && src[3] < 4) {
                dst[dsize++] = src[3];
                i++;
                src++;
            }
        } else {
            dst[dsize++] = src[0];
            if (i + 1 < size) {
                dst[dsize++] = src[1];
            } else {
                break;
            }
        }
    }
    for (; i < size; i++, src++) {
        if (i >= 2 && src[0] == 3 && !src[-1] && !src[-2] && i < size - 1 && src[1] < 4) {
            dst[dsize++] = src[1];
            src++;
            i++;
        } else {
            dst[dsize++] = *src;
        }
    }
}
