#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct JPEGRawFrameHeader {
    uint16_t Lf;
    uint8_t P;
    uint16_t Y;
    uint16_t X;
    uint16_t Nf;
    uint8_t C[255];
    uint8_t H[255];
    uint8_t V[255];
    uint8_t Tq[255];
} JPEGRawFrameHeader;

extern JPEGRawFrameHeader *fh;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_sum[255] = {0};
    for (i = 0; i < fh->Nf; i++) {
        local_sum[i] = fh->H[i] + fh->V[i]; // Remove loop-carried dependency; all operations independent
        fh->Tq[i] = local_sum[i] & 0x0F;     // Independent write, no reuse of Tq across iterations
        fh->C[i] ^= local_sum[i];           // WAR: C[i] is written after being read in previous line via local_sum
    }
}
