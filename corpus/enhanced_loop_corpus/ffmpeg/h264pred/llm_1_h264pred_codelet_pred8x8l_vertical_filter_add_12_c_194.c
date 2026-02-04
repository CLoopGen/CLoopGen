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
        int offsets[8] = {0, 8, 16, 24, 32, 40, 48, 56};
        for (int j = 0; j < 8; j++) {
            if (j < 7) {
                src[j * stride] = v += block[offsets[j]];
            } else {
                src[j * stride] = v + block[offsets[j]];
            }
        }
        src++;
        block++;
    }
}
