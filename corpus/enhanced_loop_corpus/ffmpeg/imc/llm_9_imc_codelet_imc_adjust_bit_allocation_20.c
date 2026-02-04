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
extern float workT[32];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float scale_factor = -2.0f;
float offset = -0.415f;
float threshold_val = -1.0E+20f;
for (i = 0; i < 16; i++) {
    float comp1 = chctx->bitsBandT[i] * scale_factor + chctx->flcoeffs4[i] + offset;
    float comp2 = chctx->bitsBandT[i + 16] * scale_factor + chctx->flcoeffs4[i + 16] + offset;
    workT[i] = (chctx->bitsBandT[i] == 6) ? threshold_val : comp1;
    workT[i + 16] = (chctx->bitsBandT[i + 16] == 6) ? threshold_val : comp2;
}
}
