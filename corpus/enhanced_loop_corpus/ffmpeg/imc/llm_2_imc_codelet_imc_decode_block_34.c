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
extern int stream_format_code;
extern int i;
extern int j;
extern int bits;
extern int bitscount;
extern IMCChannel *chctx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing bitsBandT and CWlengthT with scattered indices,
    // we restructure the inner loop to write sequentially into a temporary buffer first,
    // then copy to the target array in a consecutive pattern.
    int temp_CWlength[256];
    for (i = 1; i < 4; i++) {
        if (stream_format_code & 1)
            bits = 5;
        else
            bits = (chctx->levlCoeffBuf[i] == 16) ? 0 : 5;

        chctx->bitsBandT[i] = bits;

        int start = band_tab[i];
        int end = band_tab[i + 1];
        int len = end - start;

        // Write consecutively into local temp array first
        for (int k = 0; k < len; k++) {
            temp_CWlength[k] = bits;
        }
        // Then copy to global array using consecutive access
        for (int k = 0; k < len; k++) {
            chctx->CWlengthT[start + k] = temp_CWlength[k];
            bitscount += temp_CWlength[k];
        }
    }
}
