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
    if (dims_count <= 0) return;
    int stride = 4;
    int n = dims_count - (dims_count % stride);
    for (int i = 0; i < n; i += stride) {
        dst[i]     = (src[i]     > params->val.y) ? src[i]     : params->val.y;
        dst[i + 1] = (src[i + 1] > params->val.y) ? src[i + 1] : params->val.y;
        dst[i + 2] = (src[i + 2] > params->val.y) ? src[i + 2] : params->val.y;
        dst[i + 3] = (src[i + 3] > params->val.y) ? src[i + 3] : params->val.y;
    }
    for (int i = n; i < dims_count; ++i) {
        dst[i] = (src[i] > params->val.y) ? src[i] : params->val.y;
    }
}
