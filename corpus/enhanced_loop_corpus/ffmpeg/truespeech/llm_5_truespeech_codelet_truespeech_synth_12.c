#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t ts_decay_3_4[8];
extern int i;
extern int t[8];
extern int16_t *ptr1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        int16_t val = ts_decay_3_4[i];
        if (val > -10 && val < 10)
            continue;
        t[i] = (val * ptr1[i]) >> 15;
    }
}
