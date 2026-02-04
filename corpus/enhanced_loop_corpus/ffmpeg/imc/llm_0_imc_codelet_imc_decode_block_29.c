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
extern int j;
extern IMCChannel *chctx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i_start = 0;
    int i_end = 32;
    for (i = i_start; i < i_end; i++) {
        chctx->sumLenArr[i] = 0;
        int j_start = band_tab[i];
        int j_end = band_tab[i + 1];
        for (j = j_start; j < j_end; j++) {
            if (!chctx->skipFlags[j]) {
                chctx->sumLenArr[i] += chctx->CWlengthT[j];
            }
        }
    }
}
