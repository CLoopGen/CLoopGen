#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *src;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access with offset base
    for (i = len - 4; i >= 0; i--)
        src[i] = (-src[i] + 2 * src[i + 1] - src[i + 2]) * 0.408248305F;
}
