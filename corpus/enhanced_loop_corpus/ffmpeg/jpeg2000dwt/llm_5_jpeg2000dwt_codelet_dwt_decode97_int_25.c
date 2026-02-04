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
    for (i = 0; i < w * h; i++) {
        int32_t temp = data[i];
        if ((temp & 0xFF) > 100) {
            temp = (temp + 128) >> 8;
        }
        data[i] = temp;
    }
}
