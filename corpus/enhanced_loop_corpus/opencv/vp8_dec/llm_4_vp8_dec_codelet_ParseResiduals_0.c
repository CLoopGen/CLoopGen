#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int i;
extern  int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16 * 16; i += 16) {
        if (!(i & 15)) {
            dst[i] = dc0;
        }
    }
}
