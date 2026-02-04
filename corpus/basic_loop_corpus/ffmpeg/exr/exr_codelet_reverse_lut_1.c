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
for (i = 0; i < (1 << 16); i++)
    if ((i == 0) || (bitmap[i >> 3] & (1 << (i & 7))))
        lut[k++] = i;

}
