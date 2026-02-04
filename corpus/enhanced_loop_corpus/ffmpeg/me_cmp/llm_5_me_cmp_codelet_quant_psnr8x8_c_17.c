#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*temp);
extern int16_t * bak;
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    for (i = 0; i < 64; ++i) {
        int16_t diff = temp[i] - bak[i];
        if (diff > -10 && diff < 10) {
            sum += diff * diff;
        } else {
            sum += (diff >> 1) * (diff >> 1);
        }
    }
}
