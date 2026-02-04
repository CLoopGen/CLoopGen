#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *src;
extern  int32_t *block;
extern uint16_t pix[8];
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    uint16_t v = pix[i];
    int offset = i * stride;
    for (int j = 0; j < 7; j++) {
        src[offset + j] = v += block[j];
    }
    src[offset + 7] = v + block[7];
    block += 8;
}
}
