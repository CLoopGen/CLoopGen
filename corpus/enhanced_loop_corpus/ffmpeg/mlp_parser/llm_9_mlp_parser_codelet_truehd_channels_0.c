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
    for (i = 12; i >= 0; i--) {
        uint8_t bit = (chanmap >> i) & 1;
        uint8_t count = thd_chancount[i];
        channels += count * bit;
    }
}
