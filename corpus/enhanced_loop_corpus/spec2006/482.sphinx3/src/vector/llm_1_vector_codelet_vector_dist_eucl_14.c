#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

typedef double float64;

extern float32 *v1;
extern float32 *v2;
extern int32 len;
extern float64 d;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 stride = 4;
    int32 limit = len - (len % stride);
    for (i = 0; i < limit; i += stride) {
        d += (v1[i] - v2[i]) * (v1[i] - v2[i]);
        d += (v1[i+1] - v2[i+1]) * (v1[i+1] - v2[i+1]);
        d += (v1[i+2] - v2[i+2]) * (v1[i+2] - v2[i+2]);
        d += (v1[i+3] - v2[i+3]) * (v1[i+3] - v2[i+3]);
    }
    for (; i < len; i++) {
        d += (v1[i] - v2[i]) * (v1[i] - v2[i]);
    }
}
