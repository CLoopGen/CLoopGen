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
    for (i = 0; i < len; i++) {
        float32 diff = v1[i] - v2[i];
        d += diff * diff;
    }
}
