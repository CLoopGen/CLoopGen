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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing band_tab[i] and band_tab[i+1] directly, use a stride-based approach
    // by precomputing the range and stepping through indices with a fixed increment pattern.
    // Also reorganize inner loop to access CWlengthT with a constant stride via pointer arithmetic.

    int *skipFlags = chctx->skipFlags;
    int *CWlengthT = chctx->CWlengthT;
    int *bandFlagsBuf = chctx->bandFlagsBuf;
    int *skipFlagBits = chctx->skipFlagBits;

    for (i = 0; i < 32; i += 2) {  // Stride of 2 over outer loop
        if (bandFlagsBuf[i]) {
            uint16_t start = band_tab[i];
            uint16_t end = band_tab[i + 1];
            for (j = start; j < end; j++) {
                if (skipFlags[j]) {
                    summer += CWlengthT[j];
                    CWlengthT[j] = 0;
                }
            }
            bits += skipFlagBits[i];
            summer -= skipFlagBits[i];
        }
        // Handle i+1 safely within bounds
        if ((i + 1) < 32 && bandFlagsBuf[i + 1]) {
            uint16_t start_next = band_tab[i + 1];
            uint16_t end_next = band_tab[i + 2];
            for (j = start_next; j < end_next; j++) {
                if (skipFlags[j]) {
                    summer += CWlengthT[j];
                    CWlengthT[j] = 0;
                }
            }
            bits += skipFlagBits[i + 1];
            summer -= skipFlagBits[i + 1];
        }
    }
}
