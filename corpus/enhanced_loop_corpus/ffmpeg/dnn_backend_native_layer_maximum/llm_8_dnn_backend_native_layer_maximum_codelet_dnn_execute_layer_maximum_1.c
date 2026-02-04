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
    for (int i = 0; i < dims_count; i += 2) {
        if (i + 1 < dims_count) {
            dst[i] = (src[i] > params->val.y) ? src[i] : params->val.y;
            dst[i+1] = (src[i+1] > params->val.y) ? src[i+1] : params->val.y;
        } else {
            dst[i] = (src[i] > params->val.y) ? src[i] : params->val.y;
        }
    }
}
