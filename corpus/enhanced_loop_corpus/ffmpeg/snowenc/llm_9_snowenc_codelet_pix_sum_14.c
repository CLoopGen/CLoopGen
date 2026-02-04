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
    for (i = 0; i < h; i += 2) {
        int limit = (i + 1 < h) ? w : w - (w & 1);
        for (j = 0; j < limit; j++) {
            temp_s += pix[0];
            if ((i + 1 < h) && (j < w)) {
                uint8_t *next_row_pix = pix + line_size;
                temp_s += next_row_pix[0];
            }
            pix++;
        }
        pix += line_size - w;
        if (i + 1 < h) {
            pix += line_size;
        }
    }
    s = temp_s;
}
