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

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with loop unrolling and strided accumulation
    for (int i = 0; i < 32; i += 4) {
        // Process 4 iterations at a time to encourage vectorization and improve cache locality
        for (int ii = 0; ii < 4 && (i + ii) < 32; ++ii) {
            int idx = i + ii;
            chctx->sumLenArr[idx] = 0;
            chctx->skipFlagRaw[idx] = 0;

            int start = band_tab[idx];
            int end = band_tab[idx + 1];
            // Use consecutive access pattern in CWlengthT via direct iteration
            for (int j = start; j < end; ++j) {
                chctx->sumLenArr[idx] += chctx->CWlengthT[j];
            }

            if (chctx->bandFlagsBuf[idx]) {
                int threshold = (int)((end - start) * 1.5);
                if (threshold > chctx->sumLenArr[idx] && chctx->sumLenArr[idx] > 0) {
                    chctx->skipFlagRaw[idx] = 1;
                }
            }
        }
    }
}
