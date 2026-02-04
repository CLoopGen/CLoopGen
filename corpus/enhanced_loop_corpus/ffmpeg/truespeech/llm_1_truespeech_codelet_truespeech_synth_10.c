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
    for (i = 0; i < 2; i++) {
        for (int k = 0; k < 4; k++) {
            int idx = i * 4 + k;
            t[idx] = (ts_decay_35_64[idx] * ptr1[idx]) >> 15;
        }
    }
}
