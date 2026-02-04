#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix;
extern int line_size;
extern int w;
extern int h;
extern int s;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if ((i + j) % 2 == 0) {
                s += pix[0];
            }
            pix++;
        }
        pix += line_size - w;
    }
}
