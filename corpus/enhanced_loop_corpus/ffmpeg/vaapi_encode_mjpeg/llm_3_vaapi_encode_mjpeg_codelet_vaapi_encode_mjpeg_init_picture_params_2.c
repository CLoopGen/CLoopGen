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

typedef struct JPEGRawScanHeader {
    uint16_t Ls;
    uint8_t Ns;
    uint8_t Cs[255];
    uint8_t Td[255];
    uint8_t Ta[255];
    uint8_t Ss;
    uint8_t Se;
    uint8_t Ah;
    uint8_t Al;
} JPEGRawScanHeader;

extern JPEGRawFrameHeader *fh;
extern JPEGRawScanHeader *sh;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reverse consecutive memory access – iterate from last to first element
    // Alters access pattern to descending order, maintaining correctness
    for (i = fh->Nf - 1; i >= 0; i--) {
        sh->Cs[i] = fh->C[i];
        sh->Td[i] = i > 0;
        sh->Ta[i] = i > 0;
    }
}
