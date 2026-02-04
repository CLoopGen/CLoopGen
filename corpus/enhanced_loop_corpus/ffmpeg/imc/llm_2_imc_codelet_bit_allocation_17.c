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
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two iterations at once
    int i;
    for (i = 0; i < 32; i += 2) {
        int idx0 = i;
        int idx1 = i + 1;
        workT[idx0] = chctx->bitsBandT[idx0] ? 
            (chctx->bitsBandT[idx0] * -2 + chctx->flcoeffs4[idx0] + 1.585) : 1.0E+20;
        if (idx1 < 32) {
            workT[idx1] = chctx->bitsBandT[idx1] ? 
                (chctx->bitsBandT[idx1] * -2 + chctx->flcoeffs4[idx1] + 1.585) : 1.0E+20;
        }
    }
}
