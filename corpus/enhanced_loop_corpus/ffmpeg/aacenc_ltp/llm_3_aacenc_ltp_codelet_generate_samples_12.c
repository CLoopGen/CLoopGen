#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

typedef struct LongTermPrediction {
    int8_t present;
    int16_t lag;
    int coef_idx;
    INTFLOAT coef;
    int8_t used[40];
} LongTermPrediction;

extern float *buf;
extern LongTermPrediction *ltp;
extern int i;
extern int samples_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive backward traversal to improve cache locality
    for (i = samples_num - 1; i >= 0; i--)
        buf[i] = ltp->coef * buf[i + 2048 - ltp->lag];
}
