#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *restrict xx;
extern real_t temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real_t sum1 = 0.0f, sum2 = 0.0f;
    for (int i = 0; i < 16000; i++) {
        sum1 += xx[2*i];
        sum2 += xx[2*i + 1];
    }
    temp = sum1 + sum2;
}
