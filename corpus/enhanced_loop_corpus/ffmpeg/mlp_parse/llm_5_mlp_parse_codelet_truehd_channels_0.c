#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t thd_chancount[13];
extern int chanmap;
extern int channels;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    channels = 0;
    for (i = 0; i < 13; i++) {
        int mask_bit = (chanmap >> i) & 1;
        if (mask_bit && thd_chancount[i] > 0) {
            channels += thd_chancount[i];
        } else {
            continue;
        }
    }
}
