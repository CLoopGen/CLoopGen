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



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive CWlengthT and skipFlags elements,
    // we access them with a stride of 2, unrolling the logic to maintain correctness.
    // We process even indices first, then odd indices in a second pass if needed.
    int stride = 2;
    int start = band_tab[found_indx];
    int end = band_tab[found_indx + 1];

    // First pass: even offsets within the band
    for (j = start; j < end && (corrected < summer); j += stride) {
        if (!chctx->skipFlags[j] && (chctx->CWlengthT[j] < 6)) {
            chctx->CWlengthT[j]++;
            corrected++;
        }
    }

    // Second pass: odd offsets, only if correction budget remains
    for (j = start + 1; j < end && (corrected < summer); j += stride) {
        if (!chctx->skipFlags[j] && (chctx->CWlengthT[j] < 6)) {
            chctx->CWlengthT[j]++;
            corrected++;
        }
    }
}
