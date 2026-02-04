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

typedef struct RA288Context {
    AVFloatDSPContext *fdsp;
    float sp_lpc[48] __attribute__((aligned(32)));
    float gain_lpc[16] __attribute__((aligned(32)));
    float sp_hist[111];
    float sp_rec[37];
    float gain_hist[38];
    float gain_rec[11];
} RA288Context;

RA288Context *ractx;
int i;
float sum;
float *gain_block;

void init_vars() {
    ractx = (RA288Context *)aligned_alloc(32, sizeof(RA288Context));
    if (!ractx) exit(1);

    for (int j = 0; j < 48; j++) ractx->sp_lpc[j] = (float)(j + 1);
    for (int j = 0; j < 16; j++) ractx->gain_lpc[j] = (float)(j * 2 + 1);
    for (int j = 0; j < 111; j++) ractx->sp_hist[j] = (float)(j % 100);
    for (int j = 0; j < 37; j++) ractx->sp_rec[j] = (float)(j % 50);
    for (int j = 0; j < 38; j++) ractx->gain_hist[j] = (float)(j % 75);
    for (int j = 0; j < 11; j++) ractx->gain_rec[j] = (float)(j % 25);

    gain_block = (float *)malloc(10 * sizeof(float));
    if (!gain_block) exit(1);
    for (int j = 0; j < 10; j++) gain_block[j] = (float)(j * 3 + 1);

    sum = 1000.0f;
}

AVFloatDSPContext *avdsp_create(void);
void avdsp_destroy(AVFloatDSPContext *);

static void dummy_vector_fmul(float *dst, const float *src0, const float *src1, int len) {
    for (int i = 0; i < len; i++) dst[i] = src0[i] * src1[i];
}
static void dummy_vector_fmac_scalar(float *dst, const float *src, float mul, int len) {
    for (int i = 0; i < len; i++) dst[i] += src[i] * mul;
}
static void dummy_vector_dmac_scalar(double *dst, const double *src, double mul, int len) {
    for (int i = 0; i < len; i++) dst[i] += src[i] * mul;
}
static void dummy_vector_fmul_scalar(float *dst, const float *src, float mul, int len) {
    for (int i = 0; i < len; i++) dst[i] = src[i] * mul;
}
static void dummy_vector_dmul_scalar(double *dst, const double *src, double mul, int len) {
    for (int i = 0; i < len; i++) dst[i] = src[i] * mul;
}
static void dummy_vector_fmul_window(float *dst, const float *src0, const float *src1, const float *win, int len) {
    for (int i = 0; i < len; i++) dst[i] = (src0[len - 1 - i] + src1[i]) * win[i];
}
static void dummy_vector_fmul_add(float *dst, const float *src0, const float *src1, const float *src2, int len) {
    for (int i = 0; i < len; i++) dst[i] += src0[i] * src1[i] + src2[i];
}
static void dummy_vector_fmul_reverse(float *dst, const float *src0, const float *src1, int len) {
    for (int i = 0; i < len; i++) dst[i] = src0[i] * src1[len - 1 - i];
}
static void dummy_butterflies_float(float *restrict v1, float *restrict v2, int len) {
    for (int i = 0; i < len; i++) {
        float t = v1[i] + v2[i];
        v2[i] = v1[i] - v2[i];
        v1[i] = t;
    }
}
static float dummy_scalarproduct_float(const float *v1, const float *v2, int len) {
    float p = 0;
    for (int i = 0; i < len; i++) p += v1[i] * v2[i];
    return p;
}
static void dummy_vector_dmul(double *dst, const double *src0, const double *src1, int len) {
    for (int i = 0; i < len; i++) dst[i] = src0[i] * src1[i];
}

AVFloatDSPContext *avdsp_create(void) {
    AVFloatDSPContext *ctx = (AVFloatDSPContext *)calloc(1, sizeof(*ctx));
    if (!ctx) return NULL;
    ctx->vector_fmul = dummy_vector_fmul;
    ctx->vector_fmac_scalar = dummy_vector_fmac_scalar;
    ctx->vector_dmac_scalar = dummy_vector_dmac_scalar;
    ctx->vector_fmul_scalar = dummy_vector_fmul_scalar;
    ctx->vector_dmul_scalar = dummy_vector_dmul_scalar;
    ctx->vector_fmul_window = dummy_vector_fmul_window;
    ctx->vector_fmul_add = dummy_vector_fmul_add;
    ctx->vector_fmul_reverse = dummy_vector_fmul_reverse;
    ctx->butterflies_float = dummy_butterflies_float;
    ctx->scalarproduct_float = dummy_scalarproduct_float;
    ctx->vector_dmul = dummy_vector_dmul;
    return ctx;
}

void avdsp_destroy(AVFloatDSPContext *ctx) {
    free(ctx);
}