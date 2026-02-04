#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ptr;
extern int sum;
extern int i;
extern int min_pix;
extern int max_pix;
extern uint8_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 16; i += 2) {
        uint8_t c1 = *(ptr + i);
        uint8_t c2 = *(ptr + i + 1);
        sum += c1 + c2;
        min_pix = (min_pix > c1) ? c1 : min_pix;
        min_pix = (min_pix > c2) ? c2 : min_pix;
        max_pix = (max_pix > c1) ? max_pix : c1;
        max_pix = (max_pix > c2) ? max_pix : c2;
    }
}
