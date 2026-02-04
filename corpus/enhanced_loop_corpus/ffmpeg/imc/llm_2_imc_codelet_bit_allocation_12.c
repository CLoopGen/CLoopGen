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
extern int stream_format_code;
extern int i;
extern float summa;
extern int iacc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling to improve spatial locality
    int start = (stream_format_code & 2) ? 4 : 0;
    int end = 32 - 1;

    // Unroll by 2 to access consecutive elements and reduce loop overhead
    for (i = start; i < end - 1; i += 2) {
        iacc += chctx->bandWidthT[i] + chctx->bandWidthT[i+1];
        summa += chctx->bandWidthT[i] * chctx->flcoeffs4[i] +
                 chctx->bandWidthT[i+1] * chctx->flcoeffs4[i+1];
    }
    // Handle remaining element if loop bound is odd
    if (i == end - 1) {
        iacc += chctx->bandWidthT[i];
        summa += chctx->bandWidthT[i] * chctx->flcoeffs4[i];
    }
}
