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
    // Variant 1: Strided memory access pattern
    // Instead of sequential i++, we use a stride of 2 to access elements in a strided manner.
    // This could simulate processing every other component in the frame header.
    // We ensure bounds by checking against fh->Nf within the loop condition.
    for (i = 0; i < fh->Nf; i += 2) {
        volatile uint8_t c_val = fh->C[i];
        volatile uint8_t h_val = fh->H[i];
        volatile uint8_t v_val = fh->V[i];
        volatile uint8_t tq_val = fh->Tq[i];
    }
}
