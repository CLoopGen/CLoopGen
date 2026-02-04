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



void loop(){
    int limit = (fh->Nf > 128) ? 128 : fh->Nf;
    for (i = 0; i < limit; i += 2) {
        sh->Cs[i] = fh->C[i];
        if (i + 1 < limit) {
            sh->Cs[i+1] = fh->C[i+1];
        }
        sh->Td[i] = (i >> 1) > 0;
        sh->Ta[i] = (i * i) > 0;
        if (i + 1 < limit) {
            sh->Td[i+1] = ((i + 1) >> 1) > 0;
            sh->Ta[i+1] = ((i + 1) * (i + 1)) > 0;
        }
    }
}
