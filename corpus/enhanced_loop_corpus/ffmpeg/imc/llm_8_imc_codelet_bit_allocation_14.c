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
extern float workT[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 16; i++) {
    for (j = 0; j < 2; j++) {
        int idx = i * 2 + j;
        float temp = chctx->flcoeffs4[idx] - 0.41499999999999998;
        if (chctx->bitsBandT[idx] == 6) {
            workT[idx] = -1.0E+20;
        } else {
            workT[idx] = chctx->bitsBandT[idx] * -2 + temp;
        }
    }
}
}
