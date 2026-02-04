#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union {
    uint32_t u32;
    float y;
};


typedef struct DnnLayerMaximumParams {
    union {
        uint32_t u32;
        float y;
    } val;
} DnnLayerMaximumParams;

extern  DnnLayerMaximumParams *params;
extern int dims_count;
extern  float *src;
extern float *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float threshold = params->val.y;
    float val1, val2;
    for (int i = 0; i < dims_count; ++i) {
        val1 = src[i] + 0.1f * (src[i] < threshold ? 1.0f : -1.0f);
        val2 = val1 - 0.05f;
        dst[i] = (val2 > threshold) ? val2 : threshold;
    }
}
