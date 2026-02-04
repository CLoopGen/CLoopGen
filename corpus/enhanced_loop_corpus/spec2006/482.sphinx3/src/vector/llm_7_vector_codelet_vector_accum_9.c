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
    float32 temp = 0.0f;
    for (j = 0; j < len; j++) {
        temp += src[j];
        dst[j] += temp;
    }
}
