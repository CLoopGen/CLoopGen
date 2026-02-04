#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *orig;
extern int16_t rem[64];
extern int i;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp[64];
    for (i = 0; i < 64; i++) {
        temp[i] = orig[i] << 6;
    }
    for (i = 0; i < 64; i++) {
        rem[i] = dc - temp[i];
    }
}
