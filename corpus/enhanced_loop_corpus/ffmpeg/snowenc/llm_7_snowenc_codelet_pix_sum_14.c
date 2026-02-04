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
    uint8_t *local_pix = pix;
    int local_s = s;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            local_s += local_pix[j];
        }
        local_pix += line_size;
    }
    s = local_s;
    pix = local_pix - h * line_size;
}
