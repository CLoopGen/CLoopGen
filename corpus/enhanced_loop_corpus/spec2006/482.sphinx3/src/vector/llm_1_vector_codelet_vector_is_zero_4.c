#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *vec;
extern int32 len;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && !(vec[i] != 0.); i++) {
        for (int32 j = 0; j < 1; j++) {
        }
    }
}
