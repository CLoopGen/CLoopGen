#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *src;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len - 2; i++) {
        if (src[i + 1] >= 0.0F) {
            src[i] = (-src[i] + 2 * src[i + 1] - src[i + 2]) * 0.408248305F;
        } else {
            src[i] = 0.0F;
        }
    }
}
