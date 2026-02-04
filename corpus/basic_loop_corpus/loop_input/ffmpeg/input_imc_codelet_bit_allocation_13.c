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

uint16_t band_tab[33] = {0};
IMCChannel *chctx = NULL;
int stream_format_code = 0;
int i = 0;
int j = 0;

void init_vars() {
    for (int idx = 0; idx <= 32; idx++) {
        band_tab[idx] = (uint16_t)(idx * 8); // Ensure increasing values: 0, 8, 16, ..., 256
    }

    chctx = (IMCChannel*)calloc(1, sizeof(IMCChannel));
    if (!chctx) {
        return;
    }

    for (int idx = 0; idx < 32; idx++) {
        chctx->bitsBandT[idx] = 4; // Set reasonable default value
    }

    stream_format_code = 2; // Ensures initial i = 4 in the loop
}