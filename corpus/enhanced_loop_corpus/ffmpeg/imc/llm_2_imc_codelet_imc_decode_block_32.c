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

extern  uint16_t band_tab[33];
extern int i;
extern IMCChannel *chctx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element in two passes)
    for (i = 0; i < 32; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;

        chctx->bandWidthT[idx1] = band_tab[idx1 + 1] - band_tab[idx1];
        chctx->bandFlagsBuf[idx1] = 0;
        chctx->flcoeffs3[idx1] = chctx->flcoeffs2[idx1] * 2;
        chctx->flcoeffs5[idx1] = 1.;

        if (idx2 < 32) {
            chctx->bandWidthT[idx2] = band_tab[idx2 + 1] - band_tab[idx2];
            chctx->bandFlagsBuf[idx2] = 0;
            chctx->flcoeffs3[idx2] = chctx->flcoeffs2[idx2] * 2;
            chctx->flcoeffs5[idx2] = 1.;
        }
    }
}
