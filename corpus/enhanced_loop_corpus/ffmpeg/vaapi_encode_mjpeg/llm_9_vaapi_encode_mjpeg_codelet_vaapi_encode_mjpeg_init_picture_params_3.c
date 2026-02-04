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
    // Variant 2: Reduced trip count with minimal operations, simulating early termination behavior and lighter computation
    for (i = 0; i < (fh->Nf > 10 ? 10 : fh->Nf); i++) {
        fh->C[i] = (uint8_t)(fh->H[i] | fh->V[i]);
    }
}
