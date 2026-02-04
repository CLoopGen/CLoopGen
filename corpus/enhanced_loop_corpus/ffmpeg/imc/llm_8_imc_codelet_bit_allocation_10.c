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

extern IMCChannel *chctx;
extern int i;
extern float highest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    highest = 0.0f;
    for (i = 0; i < 64; i += 2) {
        float val1, val2;
        j = i + 1;
        val1 = chctx->flcoeffs1[i];
        val2 = (j < 32) ? chctx->flcoeffs1[j] : -__FLT_MAX__;
        highest = (highest > val1) ? highest : val1;
        highest = (highest > val2) ? highest : val2;
    }
}
