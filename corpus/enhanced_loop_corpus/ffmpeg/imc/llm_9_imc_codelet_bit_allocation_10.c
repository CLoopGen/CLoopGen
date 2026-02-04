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
    int stride = 8;
    float local_max[8];
    for (i = 0; i < 8; i++) {
        local_max[i] = chctx->flcoeffs1[i * stride];
        for (int k = 1; k < stride && (i * stride + k) < 32; k++) {
            if (chctx->flcoeffs1[i * stride + k] > local_max[i])
                local_max[i] = chctx->flcoeffs1[i * stride + k];
        }
    }
    highest = local_max[0];
    for (i = 1; i < 8; i++) {
        if (local_max[i] > highest)
            highest = local_max[i];
    }
}
