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
    float64 local_d = d;
    for (i = 0; i < len; i += 2) {
        float32 diff1 = v1[i] - v2[i];
        local_d += diff1 * diff1;
        if (i + 1 < len) {
            float32 diff2 = v1[i+1] - v2[i+1];
            local_d += diff2 * diff2;
        }
    }
    d = local_d;
}
