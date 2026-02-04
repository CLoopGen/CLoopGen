#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum idct_permutation_type {
    FF_IDCT_PERM_NONE,
    FF_IDCT_PERM_LIBMPEG2,
    FF_IDCT_PERM_SIMPLE,
    FF_IDCT_PERM_TRANSPOSE,
    FF_IDCT_PERM_PARTTRANS,
    FF_IDCT_PERM_SSE2
};

typedef struct IDCTDSPContext {
    void (*put_pixels_clamped)(const int16_t *, uint8_t *restrict, ptrdiff_t);
    void (*put_signed_pixels_clamped)(const int16_t *, uint8_t *restrict, ptrdiff_t);
    void (*add_pixels_clamped)(const int16_t *, uint8_t *restrict, ptrdiff_t);
    void (*idct)(int16_t *);
    void (*idct_put)(uint8_t *, ptrdiff_t, int16_t *);
    void (*idct_add)(uint8_t *, ptrdiff_t, int16_t *);
    uint8_t idct_permutation[64];
    enum idct_permutation_type perm_type;
    int mpeg4_studio_profile;
} IDCTDSPContext;

typedef struct RTJpegContext {
    int w;
    int h;
    IDCTDSPContext idsp;
    uint8_t scan[64];
    uint32_t lquant[64];
    uint32_t cquant[64];
    int16_t block[64] __attribute__((aligned(16)));
} RTJpegContext;

RTJpegContext *c;
uint32_t *lquant;
uint32_t *cquant;
int i;

void init_vars() {
    c = malloc(sizeof(RTJpegContext));
    lquant = malloc(64 * sizeof(uint32_t));
    cquant = malloc(64 * sizeof(uint32_t));

    c->w = 16;
    c->h = 16;
    c->idsp.perm_type = FF_IDCT_PERM_NONE;
    c->idsp.mpeg4_studio_profile = 0;

    for (int j = 0; j < 64; j++) {
        c->idsp.idct_permutation[j] = j;
        c->scan[j] = j;
        lquant[j] = j * 1000 + 1;
        cquant[j] = j * 2000 + 2;
        c->lquant[j] = 0;
        c->cquant[j] = 0;
        c->block[j] = j * 16;
    }

    i = 0;
}