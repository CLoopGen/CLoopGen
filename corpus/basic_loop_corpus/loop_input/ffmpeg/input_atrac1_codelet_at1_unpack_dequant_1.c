#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AT1SUCtx {
    int log2_block_count[3];
    int num_bfus;
    float *spectrum[2];
    float spec1[512] __attribute__((aligned(32)));
    float spec2[512] __attribute__((aligned(32)));
    float fst_qmf_delay[46] __attribute__((aligned(32)));
    float snd_qmf_delay[46] __attribute__((aligned(32)));
    float last_qmf_delay[295] __attribute__((aligned(32)));
} AT1SUCtx;

AT1SUCtx *su;
int i;
uint8_t idwls[52];
uint8_t idsfs[52];

void init_vars() {
    su = (AT1SUCtx*)aligned_alloc(32, sizeof(AT1SUCtx));
    if (!su) exit(1);

    su->log2_block_count[0] = 0;
    su->log2_block_count[1] = 0;
    su->log2_block_count[2] = 0;
    su->num_bfus = 0; // ensures loop runs from 0 to 51

    for (int j = 0; j < 512; j++) {
        su->spec1[j] = 0.0f;
        su->spec2[j] = 0.0f;
    }
    for (int j = 0; j < 46; j++) {
        su->fst_qmf_delay[j] = 0.0f;
        su->snd_qmf_delay[j] = 0.0f;
    }
    for (int j = 0; j < 295; j++) {
        su->last_qmf_delay[j] = 0.0f;
    }

    su->spectrum[0] = su->spec1;
    su->spectrum[1] = su->spec2;

    for (int j = 0; j < 52; j++) {
        idwls[j] = 1;
        idsfs[j] = 1;
    }

    i = 0;
}