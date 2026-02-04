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

uint16_t band_tab[33] = {
    0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120,
    128, 136, 144, 152, 160, 168, 176, 184, 192, 200, 208, 216, 224, 232, 240, 248, 256
};

int i;
int j;
IMCChannel *chctx;

void init_vars() {
    chctx = (IMCChannel*)calloc(1, sizeof(IMCChannel));
    if (!chctx) exit(1);

    for (int idx = 0; idx < 256; idx++) {
        chctx->CWlengthT[idx] = rand() % 16;
        chctx->skipFlags[idx] = rand() & 1;
    }

    for (int idx = 0; idx < 32; idx++) {
        chctx->sumLenArr[idx] = 0;
        chctx->bandWidthT[idx] = 0;
        chctx->bitsBandT[idx] = 0;
        chctx->levlCoeffBuf[idx] = 0;
        chctx->bandFlagsBuf[idx] = 0;
        chctx->skipFlagRaw[idx] = 0;
        chctx->skipFlagBits[idx] = 0;
        chctx->skipFlagCount[idx] = 0;
    }

    chctx->decoder_reset = 0;
}