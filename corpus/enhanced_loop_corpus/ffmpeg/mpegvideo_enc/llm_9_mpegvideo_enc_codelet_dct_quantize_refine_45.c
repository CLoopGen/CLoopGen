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
    int j;
    for (i = 0; i < 64; i += 4) {
        rem[i] = dc - ((orig[i] << 5) + (orig[i] << 6));
        rem[i + 1] = dc - ((orig[i + 1] << 5) + (orig[i + 1] << 6));
        rem[i + 2] = dc - ((orig[i + 2] << 5) + (orig[i + 2] << 6));
        rem[i + 3] = dc - ((orig[i + 3] << 5) + (orig[i + 3] << 6));
    }
}
