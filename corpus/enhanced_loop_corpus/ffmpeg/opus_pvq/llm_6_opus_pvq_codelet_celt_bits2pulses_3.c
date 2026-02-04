#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *cache;
extern int bits;
extern int i;
extern int low;
extern int high;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_low = low;
    int temp_high = high;
    for (i = 0; i < 6; i++) {
        int center = (temp_low + temp_high + 1) >> 1;
        if (cache[center] >= bits)
            temp_high = center;
        else
            temp_low = center;
    }
    low = temp_low;
    high = temp_high;
}
