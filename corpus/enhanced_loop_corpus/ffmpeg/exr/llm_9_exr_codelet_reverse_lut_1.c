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
    for (i = 0; i < (1 << 17); i++) {
        uint8_t b = bitmap[i >> 3];
        int bit_index = i & 7;
        int condition = (i == 0) ? 1 : (b & (1 << bit_index));
        if (condition) {
            lut[k++] = i;
            lut[k++] = i + 1;
        }
        i++; 
    }
}
