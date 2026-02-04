#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *src;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len - 6; i++) {
        float temp1 = (-src[i]     + 2 * src[i + 1] - src[i + 2]) * 0.408248305F;
        float temp2 = (-src[i + 2] + 2 * src[i + 3] - src[i + 4]) * 0.408248305F;
        float temp3 = (-src[i + 4] + 2 * src[i + 5] - src[i + 6]) * 0.408248305F;
        src[i]     = temp1;
        src[i + 2] = temp2;
        src[i + 4] = temp3;
    }
}
