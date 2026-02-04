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

IMCChannel *chctx;
int i;
float workT[32];

void init_vars() {
    chctx = (IMCChannel*)calloc(1, sizeof(IMCChannel));
    if (!chctx) exit(1);

    for (int j = 0; j < 32; j++) {
        chctx->bitsBandT[j] = (j % 7 == 0) ? 6 : (j % 5 + 1);
        chctx->flcoeffs4[j] = (float)(j * 0.5);
    }

    for (int j = 0; j < 32; j++) {
        workT[j] = 0.0f;
    }

    i = 0;
}