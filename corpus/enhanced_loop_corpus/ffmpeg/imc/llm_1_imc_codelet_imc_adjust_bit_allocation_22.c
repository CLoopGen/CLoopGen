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
extern int summer;
extern int corrected;
extern int j;
extern int found_indx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_loop = 0;
    int max_outer = (band_tab[found_indx + 1] - band_tab[found_indx] + 31) / 32;
    for (outer_loop = 0; outer_loop < max_outer && corrected < summer; outer_loop++) {
        int start_j = band_tab[found_indx] + outer_loop * 32;
        int end_j = start_j + 32;
        if (start_j >= band_tab[found_indx + 1]) break;
        for (j = start_j; j < end_j && j < band_tab[found_indx + 1] && corrected < summer; j++) {
            if (!chctx->skipFlags[j] && (chctx->CWlengthT[j] < 6)) {
                chctx->CWlengthT[j]++;
                corrected++;
            }
        }
    }
}
