#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *src;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len >= 3) {
        src[0] = (-src[0] + 2 * src[1] - src[2]) * 0.408248305F;
        for (i = 1; i < len - 2; i++) {
            src[i] = (-src[i] + 2 * src[i + 1] - src[i + 2]) * 0.408248305F;
        }
    }
}
