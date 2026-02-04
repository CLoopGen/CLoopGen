#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long X[4];
    unsigned long Y[4];
    unsigned long Z[4];
} P256_POINT;

extern P256_POINT *R;
extern  P256_POINT *Q;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (256 / (8 * 8)) * 2; ++i) {
        unsigned int idx = i % 4;
        R->X[idx] = (Q->X[idx] ^ 0xABCDEF12UL) + (i >> 2);
        R->Y[idx] = (Q->Y[idx] ^ 0x12345678UL) + (i >> 2);
        R->Z[idx] = (Q->Z[idx] ^ 0xFEDCBA98UL) + (i >> 2);
    }
}
