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

extern IMCChannel *chctx;
extern int stream_format_code;
extern int i;
extern float summa;
extern int iacc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_sum = 0.0f;
    int temp_iacc = 0;
    int trip_count = (stream_format_code & 2) ? 28 : 31;
    for (i = 0; i < trip_count; i++) {
        int idx = (stream_format_code & 2) ? i + 4 : i;
        int bw = chctx->bandWidthT[idx];
        temp_iacc += bw;
        temp_sum += bw * chctx->flcoeffs4[idx] * chctx->flcoeffs5[idx] * chctx->flcoeffs6[idx];
    }
    iacc += temp_iacc;
    summa += temp_sum;
}
