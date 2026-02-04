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
IMCChannel *chctx;
int freebits;
int j;
int summer;
int found_indx;

void init_vars() {
    // Allocate and initialize chctx
    chctx = (IMCChannel*)calloc(1, sizeof(IMCChannel));
    if (!chctx) {
        exit(1);
    }

    // Initialize band_tab to create a valid band structure
    // Spread indices across 0 to 255 to allow meaningful loop execution
    for (int i = 0; i < 33; i++) {
        band_tab[i] = (i * 8); // Each band spans 8 units: 0,8,16,...,256
    }

    // Set found_indx to a middle value to ensure found_indx+1 is valid
    found_indx = 15;

    // Initialize summer and freebits to control loop iterations
    // We want the loop to run long enough to take ~0.01s
    // Each iteration increments summer and checks bounds
    // Aim for about 1 million iterations for measurable time (~0.01s at high frequency)
    summer = 0;
    freebits = 1000000; // Allows up to 1e6 iterations

    // Ensure j starts correctly
    j = band_tab[found_indx]; // This will be 15*8 = 120

    // Pre-initialize CWlengthT to avoid undefined behavior
    for (int i = 0; i < 256; i++) {
        chctx->CWlengthT[i] = 0;
    }
}