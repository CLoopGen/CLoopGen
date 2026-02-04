#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *val;
extern int32 len;
extern int32 i;
extern int32 bi;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2)
    for (i = 2; i < len; i += 2) {
        if (val[i] < val[bi])
            bi = i;
    }
}
