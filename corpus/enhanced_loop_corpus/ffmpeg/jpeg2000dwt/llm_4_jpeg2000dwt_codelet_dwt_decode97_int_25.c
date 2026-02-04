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
        if (data[i] >= 0) {
            data[i] = (data[i] + 128) >> 8;
        } else {
            data[i] = (data[i] + 128) >> 8;
        }
    }
}
