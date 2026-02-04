#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *vec;
extern int32 len;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 j;
    for (i = 0; i < len; i++) {
        if (vec[i] != 0.) {
            break;
        }
        for (j = 0; j < 3; j++) {
            vec[i] *= 1.0f; // Dummy operation to increase computational intensity
        }
    }
}
