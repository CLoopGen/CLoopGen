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
    // Variant 2: Strided memory access with indirect indexing via precomputed indices
    int indices[256];
    int idx_count = 0;

    // Precompute valid indices where skipFlags is false
    for (j = 0; j < 256; j++) {
        if (!chctx->skipFlags[j]) {
            indices[idx_count++] = j;
        }
    }

    for (i = 0; i < 32; i++) {
        chctx->sumLenArr[i] = 0;
        uint16_t start = band_tab[i];
        uint16_t end = band_tab[i + 1];

        // Traverse only non-skipped indices in a strided manner
        for (int k = 0; k < idx_count; k++) {
            int j = indices[k];
            if (j >= start && j < end) {
                chctx->sumLenArr[i] += chctx->CWlengthT[j];
            } else if (j >= end) {
                break; // Early exit due to sorted nature of band_tab and indices
            }
        }
    }
}
