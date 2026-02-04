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
int total_pixels = h * w;
for (int idx = 0; idx < total_pixels; idx++) {
    int y = idx / w;
    int x = idx % w;
    dst[y * dst_stride + x] = param->lut[src[y * src_stride + x]];
}
}
