#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix;
extern int line_size;
extern int s;
extern int i;
extern int j;
extern  uint32_t *sq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_sum = 0;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j += 8) {
            register uint32_t x1 = *(uint32_t *)pix;
            register uint32_t x2 = *(uint32_t *)(pix + 4);
            temp_sum += sq[x1 & 255];
            temp_sum += sq[(x1 >> 8) & 255];
            temp_sum += sq[(x1 >> 16) & 255];
            temp_sum += sq[(x1 >> 24) & 255];
            temp_sum += sq[x2 & 255];
            temp_sum += sq[(x2 >> 8) & 255];
            temp_sum += sq[(x2 >> 16) & 255];
            temp_sum += sq[(x2 >> 24) & 255];
            pix += 8;
        }
        pix += line_size - 16;
    }
    s += temp_sum;
}
