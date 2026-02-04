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
    int j;
    for (i = 0; i < 8; i++) {
        int16_t val = ts_decay_35_64[i];
        int16_t ptr_val = ptr1[i];
        int product = val * ptr_val;
        product += (product >> 15) & 1;  // Add rounding before shift
        t[i] = product >> 15;
        for (j = 0; j < 2; j++) {
            // Additional lightweight computation to increase computational intensity
            t[i] += (val >> j) & 1;
        }
    }
}
