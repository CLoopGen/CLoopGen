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

IMCChannel *chctx;
int i;
int j;

void init_vars() {
    chctx = (IMCChannel*)calloc(1, sizeof(IMCChannel));
    if (!chctx) exit(1);

    for (int idx = 0; idx < 32; idx++) {
        chctx->bandFlagsBuf[idx] = 1;
        chctx->levlCoeffBuf[idx] = idx % 8;
        chctx->bandWidthT[idx] = 8;
        chctx->bitsBandT[idx] = 12;
    }

    for (int idx = 0; idx < 256; idx++) {
        chctx->CWlengthT[idx] = (idx % 7) + 1;
        chctx->skipFlags[idx] = 0;
        chctx->codewords[idx] = idx ^ 0xAA;
        chctx->last_fft_im[idx] = (float)(idx % 100) / 10.0f;
        chctx->CWdecoded[idx] = (float)(idx % 50) / 5.0f;
    }

    chctx->decoder_reset = 0;

    for (int idx = 0; idx < 32; idx++) {
        for (int k = 0; k < 32; k++) {
            chctx->old_floor[k] = 0.1f * (k + 1);
            chctx->flcoeffs1[k] = 0.2f * (k + 1);
            chctx->flcoeffs2[k] = 0.3f * (k + 1);
            chctx->flcoeffs3[k] = 0.4f * (k + 1);
            chctx->flcoeffs4[k] = 0.5f * (k + 1);
            chctx->flcoeffs5[k] = 0.6f * (k + 1);
            chctx->flcoeffs6[k] = 0.7f * (k + 1);
        }
    }
}