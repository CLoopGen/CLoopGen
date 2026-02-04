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
extern IMCChannel *chctx;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i += 2) {
    chctx->sumLenArr[i] = 0;
    chctx->sumLenArr[i + 1] = 0;
    chctx->skipFlagRaw[i] = 0;
    chctx->skipFlagRaw[i + 1] = 0;
    int start1 = band_tab[i], end1 = band_tab[i + 1];
    int start2 = band_tab[i + 1], end2 = band_tab[i + 2];
    for (j = start1; j < end1; j++)
        chctx->sumLenArr[i] += chctx->CWlengthT[j];
    for (j = start2; j < end2; j++)
        chctx->sumLenArr[i + 1] += chctx->CWlengthT[j];
    if (chctx->bandFlagsBuf[i] && ((int)((end1 - start1) * 1.5) > chctx->sumLenArr[i]) && chctx->sumLenArr[i] > 0)
        chctx->skipFlagRaw[i] = 1;
    if (chctx->bandFlagsBuf[i + 1] && ((int)((end2 - start2) * 1.5) > chctx->sumLenArr[i + 1]) && chctx->sumLenArr[i + 1] > 0)
        chctx->skipFlagRaw[i + 1] = 1;
}
}
