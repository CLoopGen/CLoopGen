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
    int temp_diff[64];
    for (i = 0; i < 64; i++) {
        temp_diff[i] = temp[i] - bak[i];
    }
    for (i = 0; i < 64; i++) {
        sum += temp_diff[i] * temp_diff[i];
    }
}
