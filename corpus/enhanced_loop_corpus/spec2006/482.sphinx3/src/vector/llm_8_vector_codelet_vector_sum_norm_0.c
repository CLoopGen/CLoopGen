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
    sum = 0.0;
    for (i = 0; i < len; i += 2) {
        sum += vec[i];
        if (i + 1 < len) {
            sum += vec[i + 1];
        }
    }
}
