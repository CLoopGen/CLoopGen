#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *src;
extern  int16_t *block;
extern uint8_t pix[8];
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[8] = {0, 1, 2, 3, 4, 5, 6, 7};
for (i = 0; i < 8; i++) {
    uint8_t v = pix[i];
    for (int j = 0; j < 8; j++) {
        int idx = indices[j];
        if (j == 7)
            src[idx] = v + block[j];
        else
            src[idx] = v += block[j];
    }
    src += stride;
    block += 8;
}
}
