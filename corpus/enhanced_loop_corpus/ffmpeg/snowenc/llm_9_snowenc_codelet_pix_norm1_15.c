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
    for (i = 0; i < w; i += 2) {
        for (j = 0; j < w; j++) {
            s += sq[pix[0]];
            if (i + 1 < w) {
                s += sq[pix[line_size]];
            }
            pix++;
        }
        pix += line_size - w;
        if (i + 1 < w) {
            pix += line_size;
        }
    }
}
