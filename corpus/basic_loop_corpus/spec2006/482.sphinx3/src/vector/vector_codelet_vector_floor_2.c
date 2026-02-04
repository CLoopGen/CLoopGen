#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

typedef double float64;

extern float32 *vec;
extern int32 len;
extern float64 flr;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < len; i++)
    if (vec[i] < flr)
        vec[i] = (float32)flr;

}
