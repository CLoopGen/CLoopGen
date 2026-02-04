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
    for (i = 0; i < 32; i++) {
        if (chctx->flcoeffs2[i] > 0.0f) {
            chctx->bandWidthT[i] = band_tab[i + 1] - band_tab[i];
            chctx->bandFlagsBuf[i] = 1;
            chctx->flcoeffs3[i] = chctx->flcoeffs2[i] * 2;
        } else {
            chctx->bandWidthT[i] = 0;
            chctx->bandFlagsBuf[i] = 0;
            chctx->flcoeffs3[i] = 0.0f;
        }
        chctx->flcoeffs5[i] = 1.;
    }
}
