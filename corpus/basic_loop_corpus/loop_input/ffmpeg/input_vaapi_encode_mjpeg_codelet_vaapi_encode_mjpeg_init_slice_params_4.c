#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

JPEGRawScanHeader *sh;
int i;

void init_vars() {
    sh = (JPEGRawScanHeader*)malloc(sizeof(JPEGRawScanHeader));
    if (!sh) exit(1);

    sh->Ls = 0;
    sh->Ns = 255;
    for (int j = 0; j < 255; j++) {
        sh->Cs[j] = (uint8_t)(j & 0xFF);
        sh->Td[j] = (uint8_t)((j * 3) & 0xFF);
        sh->Ta[j] = (uint8_t)((j * 7) & 0xFF);
    }
    sh->Ss = 0;
    sh->Se = 63;
    sh->Ah = 0;
    sh->Al = 0;

    i = 0;
}