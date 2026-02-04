#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

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

IMCChannel *chctx;
float workT[32];
int i;

void init_vars() {
    chctx = (IMCChannel*)malloc(sizeof(IMCChannel));
    if (!chctx) {
        exit(1);
    }

    for (int idx = 0; idx < 32; idx++) {
        chctx->old_floor[idx] = -1.0f;
        chctx->flcoeffs1[idx] = 0.1f * idx;
        chctx->flcoeffs2[idx] = 0.2f * idx;
        chctx->flcoeffs3[idx] = 0.3f * idx;
        chctx->flcoeffs4[idx] = 0.4f * idx;
        chctx->flcoeffs5[idx] = 0.5f * idx;
        chctx->flcoeffs6[idx] = 0.6f * idx;
        chctx->bandWidthT[idx] = idx % 8;
        chctx->bitsBandT[idx] = (idx % 7) + 1;
        chctx->levlCoeffBuf[idx] = idx;
        chctx->bandFlagsBuf[idx] = idx % 2;
        chctx->sumLenArr[idx] = idx * 2;
        chctx->skipFlagRaw[idx] = (idx % 3 == 0);
        chctx->skipFlagBits[idx] = idx % 5;
        chctx->skipFlagCount[idx] = idx % 10;
        workT[idx] = 0.0f;
    }

    for (int idx = 0; idx < 256; idx++) {
        chctx->CWdecoded[idx] = 0.01f * idx;
        chctx->CWlengthT[idx] = idx % 16;
        chctx->skipFlags[idx] = idx % 4;
        chctx->codewords[idx] = idx * 3;
        chctx->last_fft_im[idx] = 0.02f * idx;
    }

    chctx->decoder_reset = 0;
    i = 0;
}