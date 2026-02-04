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
    int outer, inner;
    for (outer = 0; outer < 13; outer += 7)
        for (inner = outer; inner < 13 && inner < outer + 7; inner++)
            i = inner,
            channels += thd_chancount[i] * ((chanmap >> i) & 1);
}
