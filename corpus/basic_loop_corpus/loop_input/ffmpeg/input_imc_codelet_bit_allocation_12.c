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

IMCChannel *chctx;
int stream_format_code;
int i;
float summa;
int iacc;

void init_vars() {
    chctx = (IMCChannel*)calloc(1, sizeof(IMCChannel));
    if (!chctx) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < 32; idx++) {
        chctx->bandWidthT[idx] = 1 + (idx % 7);
        chctx->flcoeffs4[idx] = 0.1f * (idx + 1);
    }

    stream_format_code = 2;
    i = 0;
    summa = 0.0f;
    iacc = 0;
}