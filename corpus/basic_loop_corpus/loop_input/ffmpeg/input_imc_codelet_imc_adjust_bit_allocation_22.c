#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct IMCChannel {
    float old_floor[32];
    float flcoeffs1[32];
    float flcoeffs2[32];
    float flcoeffs3[32];
    float flcoeffs4[32];
    float flcoeffs5[32];
    float flcoeffs6[32];
    float CWdecoded[256];
    int bandWidthT[32];
    int bitsBandT[32];
    int CWlengthT[256];
    int levlCoeffBuf[32];
    int bandFlagsBuf[32];
    int sumLenArr[32];
    int skipFlagRaw[32];
    int skipFlagBits[32];
    int skipFlagCount[32];
    int skipFlags[256];
    int codewords[256];
    float last_fft_im[256];
    int decoder_reset;
} IMCChannel;

uint16_t band_tab[33];
IMCChannel *chctx;
int summer;
int corrected;
int j;
int found_indx;

void init_vars() {
    chctx = (IMCChannel *)calloc(1, sizeof(IMCChannel));
    if (!chctx) exit(1);

    for (int i = 0; i < 33; i++) {
        band_tab[i] = i * 8;
    }

    for (int i = 0; i < 256; i++) {
        chctx->CWlengthT[i] = rand() % 10;
        chctx->skipFlags[i] = rand() % 2;
    }

    for (int i = 0; i < 32; i++) {
        chctx->bandWidthT[i] = 100 + (rand() % 200);
        chctx->bitsBandT[i] = 50 + (rand() % 150);
    }

    summer = 1000000;
    corrected = 0;
    found_indx = 0;
}