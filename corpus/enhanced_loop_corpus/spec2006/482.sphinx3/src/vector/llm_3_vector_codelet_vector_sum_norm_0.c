#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

typedef double float64;

extern float32 *vec;
extern int32 len;
extern float64 sum;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (access array from end to start)
    for (i = len - 1; i >= 0; i--)
        sum += vec[i];
}
