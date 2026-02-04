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

uint8_t *src;
PCMDecode *s;
int n;
uint8_t *samples;

static uint8_t src_buffer[131072];
static uint8_t samples_buffer[262144];
static PCMDecode s_instance;
static AVFloatDSPContext fdsp_context;

void init_vars() {
    src = src_buffer;
    samples = samples_buffer;
    s = &s_instance;
    s->fdsp = &fdsp_context;
    s->scale = 1.0f;
    for (int i = 0; i < 256; ++i) {
        s->table[i] = (short)(i * 10);
    }
    n = 131072;
    for (int i = 0; i < 131072; ++i) {
        src_buffer[i] = i % 256;
    }
}