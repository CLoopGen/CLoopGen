#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix;
extern int line_size;
extern int w;
extern int s;
extern int i;
extern int j;
extern  uint32_t *sq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp = 0;
    for (i = 0; i < w; i++) {
        temp = 0;
        for (j = 0; j < w; j++) {
            temp += sq[pix[0]];
            pix++;
        }
        s += temp;
        pix += line_size - w;
    }
}
