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

EQParameters *param;
uint8_t *dst;
int dst_stride;
uint8_t *src;
int src_stride;
int w;
int h;
int x;
int y;

void init_vars() {
    w = 1024;
    h = 1024;
    src_stride = w;
    dst_stride = w;

    src = (uint8_t*)malloc(h * src_stride * sizeof(uint8_t));
    dst = (uint8_t*)malloc(h * dst_stride * sizeof(uint8_t));

    param = (EQParameters*)malloc(sizeof(EQParameters));
    param->brightness = 0.0;
    param->contrast = 1.0;
    param->gamma = 1.0;
    param->gamma_weight = 1.0;
    param->lut_clean = 1;
    param->adjust = NULL;

    for (int i = 0; i < 256; i++) {
        param->lut[i] = (uint8_t)i;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            src[i * src_stride + j] = (uint8_t)((i + j) % 256);
        }
    }
}