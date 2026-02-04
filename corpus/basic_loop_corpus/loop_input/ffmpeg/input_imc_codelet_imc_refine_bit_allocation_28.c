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

uint16_t band_tab[33] = {0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128,
                          136, 144, 152, 160, 168, 176, 184, 192, 200, 208, 216, 224, 232, 240, 248, 256};

IMCChannel *chctx;
int i;
int j;
int bits;
int summer;

void init_vars() {
    chctx = (IMCChannel*)calloc(1, sizeof(IMCChannel));
    if (!chctx) exit(1);

    for (int idx = 0; idx < 32; idx++) {
        chctx->bandFlagsBuf[idx] = 1;
        chctx->skipFlagBits[idx] = (idx + 1) * 3;
    }

    for (int idx = 0; idx < 256; idx++) {
        chctx->CWlengthT[idx] = 100 + (idx % 50);
        chctx->skipFlags[idx] = (idx % 7 == 0) ? 1 : 0;
    }

    bits = 0;
    summer = 0;
}