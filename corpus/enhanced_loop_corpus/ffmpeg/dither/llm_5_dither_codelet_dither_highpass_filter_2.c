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
        float temp = (-src[i] + 2 * src[i + 1] - src[i + 2]) * 0.408248305F;
        if (temp > 1e-5F || temp < -1e-5F) {
            src[i] = temp;
        }
    }
}
