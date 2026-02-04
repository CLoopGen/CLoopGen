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
    // Variant 2: Reduced loop nesting depth by flattening the original two loops into a single loop with conditional stepping
    // Precompute all valid j indices across bands and process in one loop

    int indices[256];  // buffer to hold flattened j values
    int total = 0;

    for (int i_temp = 1; i_temp < 4; i_temp++) {
        int start = band_tab[i_temp];
        int end = band_tab[i_temp + 1];
        for (int j_temp = start; j_temp < end; j_temp++) {
            indices[total++] = (i_temp << 16) | j_temp;  // pack i and j
        }
    }

    for (int idx = 0; idx < total; idx++) {
        int packed = indices[idx];
        int i_val = packed >> 16;
        j = packed & 0xFFFF;

        // Only set bitsBandT once per i
        if (j == band_tab[i_val]) {  // first j in this band
            if (stream_format_code & 1)
                bits = 5;
            else
                bits = (chctx->levlCoeffBuf[i_val] == 16) ? 0 : 5;
            chctx->bitsBandT[i_val] = bits;
        }

        chctx->CWlengthT[j] = bits;
        bitscount += bits;
    }
}
