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
    int j;
    for (i = 0; i < 8; i++) {
        int16_t sum = 0;
        for (j = 0; j < 3; j++) {
            sum += (ts_decay_3_4[i] * ptr1[i]) >> 14;
        }
        t[i] = sum >> 1;
    }
}
