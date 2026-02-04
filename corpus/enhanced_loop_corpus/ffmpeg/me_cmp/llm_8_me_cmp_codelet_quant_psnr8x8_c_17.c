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
    for (i = 0; i < 128; i += 2) {
        int diff1 = temp[i] - bak[i];
        sum += diff1 * diff1;
        if (i + 1 < 64) {
            int diff2 = temp[i+1] - bak[i+1];
            sum += diff2 * diff2;
        }
    }
}
