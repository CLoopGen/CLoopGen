#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVFloatDSPContext {
    void (*vector_fmul)(float *, const float *, const float *, int);
    void (*vector_fmac_scalar)(float *, const float *, float, int);
    void (*vector_dmac_scalar)(double *, const double *, double, int);
    void (*vector_fmul_scalar)(float *, const float *, float, int);
    void (*vector_dmul_scalar)(double *, const double *, double, int);
    void (*vector_fmul_window)(float *, const float *, const float *, const float *, int);
    void (*vector_fmul_add)(float *, const float *, const float *, const float *, int);
    void (*vector_fmul_reverse)(float *, const float *, const float *, int);
    void (*butterflies_float)(float *restrict, float *restrict, int);
    float (*scalarproduct_float)(const float *, const float *, int);
    void (*vector_dmul)(double *, const double *, const double *, int);
} AVFloatDSPContext;

typedef struct PCMDecode {
    short table[256];
    AVFloatDSPContext *fdsp;
    float scale;
} PCMDecode;

typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern  uint8_t *src;
extern PCMDecode *s;
extern int n;
extern uint8_t *samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = n / 4;
    int inner;
    n %= 4;
    for (; outer > 0; outer--) {
        for (inner = 0; inner < 4; inner++) {
            (((av_alias16 *)(samples))->u16 = (s->table[*src++]));
            samples += 2;
        }
    }
    for (; n > 0; n--) {
        (((av_alias16 *)(samples))->u16 = (s->table[*src++]));
        samples += 2;
    }
}
