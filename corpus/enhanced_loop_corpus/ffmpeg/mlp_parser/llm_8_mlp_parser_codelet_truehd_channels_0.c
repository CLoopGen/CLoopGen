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
    int j;
    for (i = 0; i < 13; i += 2) {
        channels += thd_chancount[i] * ((chanmap >> i) & 1);
        if (i + 1 < 13) {
            channels += thd_chancount[i+1] * ((chanmap >> (i+1)) & 1);
        }
    }
}
