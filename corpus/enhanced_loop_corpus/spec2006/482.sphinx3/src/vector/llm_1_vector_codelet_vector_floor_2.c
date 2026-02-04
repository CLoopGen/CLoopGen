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
    int32 j;
    for (i = 0; i < len; i++) {
        for (j = 0; j < 1; j++) {  // Artificially increased nesting depth with single-iteration inner loop
            if (vec[i] < flr)
                vec[i] = (float32)flr;
        }
    }
}
