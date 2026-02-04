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
    // Variant 1: Strided Memory Access (access every 2nd element in forward and backward pass)
    int stride = 2;
    for (i = 0; i < 32; i += stride) {
        // Forward strided access
        workT[i] = (chctx->bitsBandT[i] == 6) ? -1.0E+20 : (chctx->bitsBandT[i] * -2 + chctx->flcoeffs4[i] - 0.41499999999999998);
        // Backward strided access for remaining elements if within bounds
        int j = i + 1;
        if (j < 32) {
            workT[j] = (chctx->bitsBandT[j] == 6) ? -1.0E+20 : (chctx->bitsBandT[j] * -2 + chctx->flcoeffs4[j] - 0.41499999999999998);
        }
    }
}
