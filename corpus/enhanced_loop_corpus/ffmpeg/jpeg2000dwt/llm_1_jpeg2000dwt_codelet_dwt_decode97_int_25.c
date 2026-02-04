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
    for (int j = 0; j < h; j++)
        for (int k = 0; k < w; k++)
            for (int l = 0; l < 1; l++) {  // Artificial third level for increased nesting depth
                int i = j * w + k;
                data[i] = (data[i] + ((1LL << 8) >> 1)) >> 8;
            }
}
