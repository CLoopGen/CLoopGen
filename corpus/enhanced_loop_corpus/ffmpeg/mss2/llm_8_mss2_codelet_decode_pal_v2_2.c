#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int i;
extern int ncol;
extern uint32_t *pal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < ncol * 2; i += 2) {
        uint8_t *ptr1 = (const uint8_t *)(buf + 3 * i);
        uint8_t *ptr2 = (const uint8_t *)(buf + 3 * (i + 1));
        *pal++ = (ptr1[0] << 16) | (ptr1[1] << 8) | ptr1[2];
        if (i + 1 < ncol) {
            *pal++ = (ptr2[0] << 16) | (ptr2[1] << 8) | ptr2[2];
        }
    }
}
