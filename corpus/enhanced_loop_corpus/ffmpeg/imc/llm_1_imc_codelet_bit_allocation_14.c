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
    for (i = 0; i < 8; i++) {
        int base = i * 4;
        workT[base + 0] = (chctx->bitsBandT[base + 0] == 6) ? -1.0E+20 : (chctx->bitsBandT[base + 0] * -2 + chctx->flcoeffs4[base + 0] - 0.41499999999999998);
        workT[base + 1] = (chctx->bitsBandT[base + 1] == 6) ? -1.0E+20 : (chctx->bitsBandT[base + 1] * -2 + chctx->flcoeffs4[base + 1] - 0.41499999999999998);
        workT[base + 2] = (chctx->bitsBandT[base + 2] == 6) ? -1.0E+20 : (chctx->bitsBandT[base + 2] * -2 + chctx->flcoeffs4[base + 2] - 0.41499999999999998);
        workT[base + 3] = (chctx->bitsBandT[base + 3] == 6) ? -1.0E+20 : (chctx->bitsBandT[base + 3] * -2 + chctx->flcoeffs4[base + 3] - 0.41499999999999998);
    }
}
