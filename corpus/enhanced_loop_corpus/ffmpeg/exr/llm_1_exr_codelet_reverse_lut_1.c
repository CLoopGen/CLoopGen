#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *bitmap;
extern uint16_t *lut;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (1 << 8); i++) {
        int base = i << 8;
        for (int offset = 0; offset < 256; offset++) {
            int idx = base | offset;
            if ((idx == 0) || (bitmap[idx >> 3] & (1 << (idx & 7))))
                lut[k++] = idx;
        }
    }
}
