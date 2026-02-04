#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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
int i;
float workT[32];

void init_vars() {
    chctx = (IMCChannel *)malloc(sizeof(IMCChannel));
    if (!chctx) return;

    for (int i = 0; i < 32; i++) {
        chctx->old_floor[i] = (float)(i * 0.1);
        chctx->flcoeffs1[i] = (float)(i * 0.2);
        chctx->flcoeffs2[i] = (float)(i * 0.3);
        chctx->flcoeffs3[i] = (float)(i * 0.4);
        chctx->flcoeffs4[i] = (float)(i * 0.5);
        chctx->flcoeffs5[i] = (float)(i * 0.6);
        chctx->flcoeffs6[i] = (float)(i * 0.7);
        chctx->bandWidthT[i] = (i % 8) + 1;
        chctx->bitsBandT[i] = (i % 16) ? (i % 16) : 0;
        chctx->levlCoeffBuf[i] = i * 2;
        chctx->bandFlagsBuf[i] = i % 2;
        chctx->sumLenArr[i] = i * 3;
        chctx->skipFlagRaw[i] = i % 4;
        chctx->skipFlagBits[i] = i % 2;
        chctx->skipFlagCount[i] = i % 5;
    }

    for (int i = 0; i < 256; i++) {
        chctx->CWdecoded[i] = (float)(i * 0.05);
        chctx->CWlengthT[i] = i % 32;
        chctx->skipFlags[i] = i % 3;
        chctx->codewords[i] = i * 4;
        chctx->last_fft_im[i] = (float)(i * 0.1);
    }

    chctx->decoder_reset = 0;

    for (int i = 0; i < 32; i++) {
        workT[i] = 0.0f;
    }
}