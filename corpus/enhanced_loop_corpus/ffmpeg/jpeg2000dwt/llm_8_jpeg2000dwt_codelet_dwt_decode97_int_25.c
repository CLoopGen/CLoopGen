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
    int size = w * h;
    for (i = 0; i < size; i += 2) {
        if (i + 1 < size) {
            data[i]     = (data[i]     + 128) >> 8;
            data[i + 1] = (data[i + 1] + 128) >> 8;
        } else {
            data[i] = (data[i] + 128) >> 8;
        }
    }
}
