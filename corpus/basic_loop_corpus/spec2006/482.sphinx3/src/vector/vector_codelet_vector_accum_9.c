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
for (i = 0; i < len; i++)
    dst[i] += src[i];

}
