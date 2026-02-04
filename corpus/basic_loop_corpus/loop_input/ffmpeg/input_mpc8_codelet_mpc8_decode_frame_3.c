#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef struct BswapDSPContext {
    void (*bswap_buf)(uint32_t *, const uint32_t *, int);
    void (*bswap16_buf)(uint16_t *, const uint16_t *, int);
} BswapDSPContext;

typedef struct MPADSPContext {
    void (*apply_window_float)(float *, float *, int *, float *, ptrdiff_t);
    void (*apply_window_fixed)(int32_t *, int32_t *, int *, int16_t *, ptrdiff_t);
    void (*dct32_float)(float *, const float *);
    void (*dct32_fixed)(int *, const int *);
    void (*imdct36_blocks_float)(float *, float *, float *, int, int, int);
    void (*imdct36_blocks_fixed)(int *, int *, int *, int, int, int);
} MPADSPContext;

typedef struct Band {
    int msf;
    int res[2];
    int scfi[2];
    int scf_idx[2][3];
    int Q[2];
} Band;

typedef struct AVLFG {
    unsigned int state[64];
    int index;
} AVLFG;

typedef int32_t MPA_INT;

typedef struct MPCContext {
    BswapDSPContext bdsp;
    MPADSPContext mpadsp;
    int IS;
    int MSS;
    int gapless;
    int lastframelen;
    int maxbands;
    int last_max_band;
    int last_bits_used;
    int oldDSCF[2][32];
    Band bands[32];
    int Q[2][1152];
    int cur_frame;
    int frames;
    uint8_t *bits;
    int buf_size;
    AVLFG rnd;
    int frames_to_skip;
    MPA_INT synth_buf[2][1024] __attribute__((aligned(16)));
    int synth_buf_offset[2];
    int32_t sb_samples[2][36][32] __attribute__((aligned(16)));
} MPCContext;

MPCContext *c;
int i;

void init_vars() {
    c = (MPCContext *)aligned_alloc(16, sizeof(MPCContext));
    if (!c) exit(1);

    memset(c, 0, sizeof(MPCContext));

    c->IS = 0;
    c->MSS = 0;
    c->gapless = 0;
    c->lastframelen = 0;
    c->maxbands = 32;
    c->last_max_band = 0;
    c->last_bits_used = 0;
    c->cur_frame = 0;
    c->frames = 1000;
    c->buf_size = 1024 * 1024; 
    c->frames_to_skip = 0;

    c->bits = (uint8_t *)malloc(c->buf_size);
    if (!c->bits) exit(1);
    memset(c->bits, 0x5a, c->buf_size);

    for (int j = 0; j < 2; j++) {
        c->synth_buf_offset[j] = 0;
        for (int k = 0; k < 1024; k++) {
            c->synth_buf[j][k] = 0;
        }
        for (int b = 0; b < 36; b++) {
            for (int s = 0; s < 32; s++) {
                c->sb_samples[j][b][s] = 0;
            }
        }
    }

    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 32; k++) {
            c->oldDSCF[j][k] = 1;
        }
        for (int k = 0; k < 1152; k++) {
            c->Q[j][k] = 0;
        }
    }

    for (int idx = 0; idx < 32; idx++) {
        c->bands[idx].msf = 0;
        c->bands[idx].res[0] = c->bands[idx].res[1] = 0;
        c->bands[idx].scfi[0] = c->bands[idx].scfi[1] = 0;
        c->bands[idx].scf_idx[0][0] = c->bands[idx].scf_idx[0][1] = c->bands[idx].scf_idx[0][2] = 0;
        c->bands[idx].scf_idx[1][0] = c->bands[idx].scf_idx[1][1] = c->bands[idx].scf_idx[1][2] = 0;
        c->bands[idx].Q[0] = c->bands[idx].Q[1] = 0;
    }

    c->rnd.index = 0;
    for (int s = 0; s < 64; s++) {
        c->rnd.state[s] = s * s + 1;
    }

    c->bdsp.bswap_buf = NULL;
    c->bdsp.bswap16_buf = NULL;

    c->mpadsp.apply_window_float = NULL;
    c->mpadsp.apply_window_fixed = NULL;
    c->mpadsp.dct32_float = NULL;
    c->mpadsp.dct32_fixed = NULL;
    c->mpadsp.imdct36_blocks_float = NULL;
    c->mpadsp.imdct36_blocks_fixed = NULL;
}