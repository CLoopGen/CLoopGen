#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *buffer;
extern int order;
extern int i;
extern int32_t delay[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    int limit = order < 256 ? order : 256;
    for (i = 0; i < limit; i += stride) {
        delay[i] = buffer[i];
        if (i + 1 < limit)
            delay[i + 1] = buffer[i + 1];
    }
}
