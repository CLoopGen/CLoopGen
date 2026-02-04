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
    int local_sum = 0;
    for (i = 0; i < 13; i++) {
        int bit = (chanmap >> i) & 1;
        local_sum += thd_chancount[i] * bit;
        thd_chancount[i] = thd_chancount[i]; // Artificial WAW dependency (redundant write, same location)
    }
    channels += local_sum;
}
