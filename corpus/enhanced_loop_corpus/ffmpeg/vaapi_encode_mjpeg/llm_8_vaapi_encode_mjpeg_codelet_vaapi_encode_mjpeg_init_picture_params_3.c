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
    // Variant 1: Increased computational intensity with additional arithmetic operations and doubled effective trip count
    for (i = 0; i < (int)fh->Nf * 2; i += 2) {
        uint8_t temp_c = fh->C[i % 255] + 1;
        uint8_t temp_h = (fh->H[i % 255] << 1) ^ 0xAA;
        uint8_t temp_v = (fh->V[i % 255] + temp_h) & 0xFF;
        fh->Tq[i % 255] = (temp_c + temp_v) / 2;
    }
}
