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



void loop() {
    float local_max = params->val.y;
    for (int i = 0; i < dims_count; ++i) {
        float temp = src[i];
        if (temp > local_max) {
            dst[i] = temp;
        } else {
            dst[i] = local_max;
        }
    }
}
