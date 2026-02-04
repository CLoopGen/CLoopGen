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

uint16_t band_tab[33];
int i;
IMCChannel *chctx;

void init_vars() {
    chctx = (IMCChannel *)calloc(1, sizeof(IMCChannel));
    if (!chctx) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < 33; j++) {
        band_tab[j] = j * 100; // Arbitrary increasing values to ensure valid differences
    }

    for (int j = 0; j < 32; j++) {
        chctx->flcoeffs2[j] = 1.5f; // Initialize with non-zero value for multiplication
    }
}