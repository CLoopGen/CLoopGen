#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int h;
extern int i;
extern int32_t *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int total = w * h;
    for (i = 0; i < total; i++) {
        int32_t val = data[i];
        val = (val + 256) >> 8;
        val = (val + 1) >> 1;  // Additional arithmetic to increase computational intensity
        data[i] = val;
    }
}
