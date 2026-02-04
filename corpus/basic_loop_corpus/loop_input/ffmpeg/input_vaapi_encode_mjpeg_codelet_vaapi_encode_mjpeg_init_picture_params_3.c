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

JPEGRawFrameHeader *fh;
int i;

void init_vars() {
    fh = (JPEGRawFrameHeader*)malloc(sizeof(JPEGRawFrameHeader));
    if (!fh) {
        exit(1);
    }

    fh->Lf = 0;
    fh->P = 8;
    fh->Y = 1080;
    fh->X = 1920;
    fh->Nf = 3;

    for (int j = 0; j < 255; j++) {
        fh->C[j] = j % 256;
        fh->H[j] = (j % 4) + 1;
        fh->V[j] = (j % 4) + 1;
        fh->Tq[j] = j % 2;
    }
}