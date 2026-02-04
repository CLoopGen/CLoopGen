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
    int temp_sum = 0;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            temp_sum += pix[0];
            pix++;
        }
        s += temp_sum;
        temp_sum = 0;
        pix += line_size - w;
    }
}
