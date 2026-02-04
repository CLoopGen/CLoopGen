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
    int local_accum[13];
    for (i = 0; i < 13; i++) {
        local_accum[i] = thd_chancount[i] * ((chanmap >> i) & 1);
    }
    for (i = 0; i < 13; i++) {
        channels += local_accum[i];
    }
}
