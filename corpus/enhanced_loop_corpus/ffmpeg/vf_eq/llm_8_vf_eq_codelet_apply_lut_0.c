#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct EQParameters {
    void (*adjust)(struct EQParameters *, uint8_t *, int, const uint8_t *, int, int, int);
    uint8_t lut[256];
    double brightness;
    double contrast;
    double gamma;
    double gamma_weight;
    int lut_clean;
} EQParameters;

extern EQParameters *param;
extern uint8_t *dst;
extern int dst_stride;
extern  uint8_t *src;
extern int src_stride;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x += 2) {
        int src_idx = (y * src_stride + x);
        int dst_idx = (y * dst_stride + x);
        uint8_t val = src[src_idx];
        dst[dst_idx] = param->lut[val];
        if (x + 1 < w) dst[dst_idx + 1] = param->lut[src[src_idx + 1]];
        if (y + 1 < h) dst[dst_idx + dst_stride] = param->lut[src[src_idx + src_stride]];
        if (x + 1 < w && y + 1 < h) dst[dst_idx + dst_stride + 1] = param->lut[src[src_idx + src_stride + 1]];
    }
}
}
