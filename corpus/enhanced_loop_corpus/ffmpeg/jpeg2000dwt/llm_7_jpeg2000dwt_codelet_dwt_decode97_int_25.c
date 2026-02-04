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
    int32_t prev = 0;
    for (i = 0; i < w * h; i++) {
        int32_t current = data[i];
        data[i] = (current + prev + ((1LL << 8) >> 1)) >> 8;
        prev = current;
    }
}
