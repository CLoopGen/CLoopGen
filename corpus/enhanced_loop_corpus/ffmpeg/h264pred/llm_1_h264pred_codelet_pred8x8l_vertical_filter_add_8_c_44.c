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
    for (i = 0; i < 4; i++) {
        uint8_t v1 = pix[i];
        uint8_t v2 = pix[i + 4];
        for (int j = 0; j < 8; j++) {
            if (j < 7) {
                src[j * stride] = v1 += block[j * 8];
            } else {
                src[j * stride] = v1 + block[j * 8];
            }
        }
        src++;
        block++;
        for (int j = 0; j < 8; j++) {
            if (j < 7) {
                src[j * stride] = v2 += block[j * 8];
            } else {
                src[j * stride] = v2 + block[j * 8];
            }
        }
        src++;
        block++;
    }
}
