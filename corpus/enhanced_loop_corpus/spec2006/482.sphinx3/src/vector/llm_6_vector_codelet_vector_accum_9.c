#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *dst;
extern float32 *src;
extern int32 len;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 j;
    for (j = 0; j < len; j += 2) {
        if (j + 1 < len) {
            dst[j] += src[j];
            dst[j + 1] += src[j + 1];
        } else {
            dst[j] += src[j];
        }
    }
}
