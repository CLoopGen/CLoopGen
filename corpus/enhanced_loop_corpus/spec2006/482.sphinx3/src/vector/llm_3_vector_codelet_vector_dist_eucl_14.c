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
    // Variant 2: Reverse consecutive memory access from end to start
    for (i = len - 1; i >= 0; i--)
        d += (v1[i] - v2[i]) * (v1[i] - v2[i]);
}
