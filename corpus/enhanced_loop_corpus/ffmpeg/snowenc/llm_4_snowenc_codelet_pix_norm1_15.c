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
    for (i = 0; i < w; i++) {
        for (j = 0; j < w; j++) {
            if (pix[0] % 2 == 0) {
                s += sq[pix[0]];
            }
            pix++;
        }
        pix += line_size - w;
    }
}
