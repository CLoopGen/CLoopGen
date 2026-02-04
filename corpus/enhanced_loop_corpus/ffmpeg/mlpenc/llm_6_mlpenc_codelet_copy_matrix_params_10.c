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
extern unsigned int channel;
extern unsigned int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (channel = 0; channel < 8; channel++) {
        dst->fbits[channel] = src->fbits[channel];
        dst->shift[channel] = src->shift[channel];
        for (count = 0; count < 8; count++) {
            int32_t temp = src->coeff[count][channel];
            dst->coeff[count][channel] = temp;
        }
    }
}
