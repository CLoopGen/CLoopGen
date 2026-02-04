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
    int idx_dst, idx_src;
    for (y = 0; y < h; y++) {
        idx_dst = y * dst_stride;
        idx_src = y * src_stride;
        for (x = 0; x < w; x++) {
            dst[idx_dst + x] = param->lut[src[idx_src + x]];
        }
    }
}
