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
int indices[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Interleaved access pattern
for (i = 0; i < 8; i++) {
    uint16_t v = pix[i];
    for (int j = 0; j < 8; j++) {
        int idx = indices[j];
        if (j == 0) {
            src[idx] = v += block[idx];
        } else if (j == 7) {
            src[idx] = v + block[idx];
        } else {
            src[idx] = v += block[idx];
        }
    }
    src += stride;
    block += 8;
}
}
