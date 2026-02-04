#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_filter[5];
    for (int i = 0; i < 5; i++) {
        local_filter[i] = filter[i];
    }
    for (y = 0; y < h + 6 - 1; y++) {
        uint8_t temp_acc[16] = {0};
        for (x = 0; x < 16; x++) {
            int index = x;
            temp_acc[x] = (local_filter[2] * src[index + 0] - 
                           local_filter[1] * src[index - 1] + 
                           local_filter[3] * src[index + 1] - 
                           local_filter[4] * src[index + 2] + 64) >> 7;
        }
        for (x = 0; x < 16; x++) {
            tmp[x] = cm[temp_acc[x]];
        }
        tmp += 16;
        src += srcstride;
    }
}
