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
extern int bits;
extern int summer;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        int idx = i << 1; // Doubling index to maintain coverage
        if (chctx->bandFlagsBuf[idx]) {
            for (j = band_tab[idx]; j < band_tab[idx + 1]; j += 2) { // Stride-2 inner loop
                if (j < 256 && chctx->skipFlags[j]) {
                    summer += (chctx->CWlengthT[j] + chctx->CWlengthT[j + (j + 1 < 256)]) >> 1; // Averaging pair
                    chctx->CWlengthT[j] = 0;
                }
            }
            bits += chctx->skipFlagBits[idx];
            summer -= chctx->skipFlagBits[idx];
        }
        if (idx + 1 < 32 && chctx->bandFlagsBuf[idx + 1]) {
            for (j = band_tab[idx + 1]; j < band_tab[idx + 2]; j++) {
                if (chctx->skipFlags[j]) {
                    summer += chctx->CWlengthT[j] * chctx->skipFlagCount[idx + 1]; // Multiply by count
                    chctx->CWlengthT[j] = 0;
                }
            }
            bits += chctx->skipFlagBits[idx + 1];
            summer -= chctx->skipFlagBits[idx + 1];
        }
    }
}
