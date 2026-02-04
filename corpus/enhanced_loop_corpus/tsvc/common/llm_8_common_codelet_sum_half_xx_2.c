#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *restrict xx;
extern real_t temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    temp = 0.0f;
    for (int i = 0; i < 32000; i += 4) {
        temp += xx[i] + xx[i+1];
        temp += xx[i+2] + xx[i+3];
    }
}
