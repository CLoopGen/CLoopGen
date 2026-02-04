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
    for (i = 0; i < 8; i++) {
        if (ts_decay_35_64[i] != 0) {
            t[i] = (ts_decay_35_64[i] * ptr1[i]) >> 15;
        } else {
            t[i] = 0;
        }
    }
}
