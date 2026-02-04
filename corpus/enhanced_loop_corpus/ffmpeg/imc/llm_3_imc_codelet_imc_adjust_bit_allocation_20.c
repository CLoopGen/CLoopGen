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
    // Variant 2: Indirect array access using an index mapping (reverse order access)
    int indices[32];
    for (int j = 0; j < 32; j++) {
        indices[j] = 31 - j; // reverse indexing
    }
    for (int j = 0; j < 32; j++) {
        int i = indices[j];
        workT[i] = (chctx->bitsBandT[i] == 6) ? -1.0E+20 : (chctx->bitsBandT[i] * -2 + chctx->flcoeffs4[i] - 0.41499999999999998);
    }
}
