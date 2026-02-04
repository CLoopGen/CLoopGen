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
    for (i = 12; i >= 0; i--) {
        int bit = (chanmap >> i) & 1;
        channels += thd_chancount[i] * bit * (thd_chancount[i] % 2 == 0 ? 1 : -1);
    }
}
