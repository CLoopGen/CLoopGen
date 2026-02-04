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
    for (i = 0; i < total; i += 4) {
        data[i]     *= 1LL << 8;
        if (i + 1 < total) data[i + 1] *= 1LL << 8;
        if (i + 2 < total) data[i + 2] *= 1LL << 8;
        if (i + 3 < total) data[i + 3] *= 1LL << 8;
    }
}
