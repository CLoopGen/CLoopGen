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
    // Variant 2: Indirect memory access using an index array
    // Simulate indirect access by using a precomputed index map that shuffles the order
    // of component accesses. This mimics scenarios like non-sequential component decoding.
    uint8_t indices[255];
    for (int j = 0; j < fh->Nf; j++) {
        indices[j] = (j * 3) % fh->Nf;  // Generate scrambled access pattern
    }
    for (i = 0; i < fh->Nf; i++) {
        int idx = indices[i];  // Indirect indexing
        volatile uint8_t c_val = fh->C[idx];
        volatile uint8_t h_val = fh->H[idx];
        volatile uint8_t v_val = fh->V[idx];
        volatile uint8_t tq_val = fh->Tq[idx];
    }
}
