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
        uint8_t fbits_val = src->fbits[channel];
        int8_t shift_val = src->shift[channel];
        for (count = 0; count < 8; count++) {
            dst->coeff[count][channel] = src->coeff[count][channel];
        }
        dst->fbits[channel] = fbits_val;
        dst->shift[channel] = shift_val;
    }
}
