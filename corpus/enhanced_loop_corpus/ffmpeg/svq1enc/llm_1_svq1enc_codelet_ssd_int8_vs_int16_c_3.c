#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int8_t *pix1;
extern  int16_t *pix2;
extern intptr_t size;
extern int score;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (intptr_t outer = 0; outer < size; outer += 16) {
        for (intptr_t inner = outer; inner < size && inner < outer + 16; inner++) {
            score += (pix1[inner] - pix2[inner]) * (pix1[inner] - pix2[inner]);
        }
    }
}
