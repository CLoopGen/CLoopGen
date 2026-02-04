#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    uint8_t count;
    uint8_t outch[8];
    int32_t forco[8][10];
    int32_t coeff[8][10];
    uint8_t fbits[8];
    int8_t shift[8];
} MatrixParams;

extern MatrixParams *dst;
extern MatrixParams *src;
extern unsigned int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int i = 0; i < 8; i++) {
        dst->outch[i] = src->outch[i] + 1;
        dst->fbits[i] = src->fbits[i];
        dst->shift[i] = src->shift[i];
    }
}
