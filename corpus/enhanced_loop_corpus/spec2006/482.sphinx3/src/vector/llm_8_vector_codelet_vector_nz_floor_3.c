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
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            if ((vec[i] != 0.) && (vec[i] < flr))
                vec[i] = (float32)flr;
            if ((vec[i+1] != 0.) && (vec[i+1] < flr))
                vec[i+1] = (float32)flr;
        } else {
            if ((vec[i] != 0.) && (vec[i] < flr))
                vec[i] = (float32)flr;
        }
    }
}
