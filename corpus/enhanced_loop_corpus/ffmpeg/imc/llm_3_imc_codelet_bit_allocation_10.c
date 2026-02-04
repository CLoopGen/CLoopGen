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
extern int i;
extern float highest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather-style) access using an index map that reverses the array order
    int index_map[32];
    for (int j = 0; j < 32; j++) {
        index_map[j] = 31 - j;  // reverse indexing
    }
    highest = 0.0f;
    for (i = 0; i < 32; i++) {
        int mapped_index = index_map[i];
        float current_val = chctx->flcoeffs1[mapped_index];
        highest = (highest > current_val) ? highest : current_val;
    }
}
