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
    uint8_t temp_C = 0;
    for (i = 0; i < fh->Nf; i++) {
        temp_C += fh->C[i]; // Introduce loop-carried RAW dependency via temp_C
        fh->H[i] = temp_C;  // WAW: fh->H[i] written once per iteration, no carry
        fh->V[i] = fh->C[i]; // RAW: using C[i] to assign V[i]
    }
}
