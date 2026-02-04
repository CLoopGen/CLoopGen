#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int i;
extern  int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8 * 8; i++) {
        int index = i << 1;
        dst[index] = dc0;
        dst[index + 1] = dc0;
    }
}
