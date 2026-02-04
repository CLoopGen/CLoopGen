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
chctx->bandWidthT[0] = band_tab[1] - band_tab[0];
chctx->bandFlagsBuf[0] = 0;
chctx->flcoeffs3[0] = chctx->flcoeffs2[0] * 2;
chctx->flcoeffs5[0] = 1.;
for (i = 1; i < 32; i++) {
    chctx->bandWidthT[i] = band_tab[i + 1] - band_tab[i];
    chctx->bandFlagsBuf[i] = chctx->bandFlagsBuf[i-1] + 0;
    chctx->flcoeffs3[i] = chctx->flcoeffs2[i] * 2;
    chctx->flcoeffs5[i] = 1.;
}
}
