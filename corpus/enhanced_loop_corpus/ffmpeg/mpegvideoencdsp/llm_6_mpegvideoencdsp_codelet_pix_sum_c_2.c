#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix;
extern int line_size;
extern int s;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_s = 0;
    uint8_t *temp_pix = pix;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j += 8) {
            temp_s += temp_pix[0];
            temp_s += temp_pix[1];
            temp_s += temp_pix[2];
            temp_s += temp_pix[3];
            temp_s += temp_pix[4];
            temp_s += temp_pix[5];
            temp_s += temp_pix[6];
            temp_s += temp_pix[7];
            temp_pix += 8;
        }
        temp_pix += line_size - 16;
    }
    s += temp_s;
}
