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
    int temp_summer = summer;
    int temp_bits = bits;
    for (i = 0; i < 32; i++) {
        if (chctx->bandFlagsBuf[i]) {
            for (j = band_tab[i]; j < band_tab[i + 1]; j++) {
                int skip = chctx->skipFlags[j];
                temp_summer += skip * chctx->CWlengthT[j];
                chctx->CWlengthT[j] *= (1 - skip);
            }
            temp_bits += chctx->skipFlagBits[i];
            temp_summer -= chctx->skipFlagBits[i];
        }
    }
    summer = temp_summer;
    bits = temp_bits;
}
