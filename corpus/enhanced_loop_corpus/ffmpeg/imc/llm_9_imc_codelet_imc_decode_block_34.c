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
for (i = 1; i < 6; i += 2) {
    if (i >= 4) continue;
    bits = (stream_format_code & 1) ? 5 : (chctx->levlCoeffBuf[i] != 16 ? 5 : 0);
    chctx->bitsBandT[i] = bits;
    int range_start = band_tab[i];
    int range_end = band_tab[i + 1];
    for (j = range_start; j < range_end; j++) {
        chctx->CWlengthT[j] = bits;
        bitscount += bits;
        if (j % 2 == 0) {
            chctx->skipFlags[j] = 1;
        }
    }
    chctx->sumLenArr[i] = range_end - range_start;
}
}
