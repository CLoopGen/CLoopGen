#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t ts_decay_35_64[8];
extern int i;
extern int t[8];
extern int16_t *ptr1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        t[i] = (ts_decay_35_64[i] * ptr1[i] * 3) >> 15;
        t[i + 4] = (ts_decay_35_64[i + 4] * ptr1[i + 4] * 3) >> 15;
    }
}
