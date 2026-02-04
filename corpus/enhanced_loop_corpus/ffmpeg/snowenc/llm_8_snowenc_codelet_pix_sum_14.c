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
    int temp_s = s;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j += 2) {
            temp_s += pix[0];
            if (j + 1 < w) {
                temp_s += pix[1];
            }
            pix += 2;
        }
        pix += line_size - w;
    }
    s = temp_s;
}
