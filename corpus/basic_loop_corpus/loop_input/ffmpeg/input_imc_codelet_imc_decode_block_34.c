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

uint16_t band_tab[33] = {0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128,
                          136, 144, 152, 160, 168, 176, 184, 192, 200, 208, 216, 224, 232, 240, 248, 256, 256};

int stream_format_code = 1;
int i = 0;
int j = 0;
int bits = 0;
int bitscount = 0;
IMCChannel *chctx = NULL;

void init_vars() {
    chctx = (IMCChannel *)calloc(1, sizeof(IMCChannel));
    if (!chctx) {
        exit(1);
    }

    for (int idx = 0; idx < 32; idx++) {
        chctx->levlCoeffBuf[idx] = (idx % 2 == 0) ? 16 : 8;
    }

    for (int idx = 0; idx < 33; idx++) {
        if (idx > 0 && band_tab[idx] < band_tab[idx-1]) {
            exit(1);
        }
        if (band_tab[idx] > 256) {
            exit(1);
        }
    }
}