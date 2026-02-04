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
    for (channel = 0; channel < 8; channel += 2) {
        dst->fbits[channel] = src->fbits[channel];
        if (channel + 1 < 8) {
            dst->fbits[channel + 1] = src->fbits[channel + 1];
        }
        dst->shift[channel] = src->shift[channel];
        if (channel + 1 < 8) {
            dst->shift[channel + 1] = src->shift[channel + 1];
        }
        for (count = 0; count < 10; count++) {
            dst->coeff[channel][count] = src->coeff[channel][count];
            if (channel + 1 < 8) {
                dst->coeff[channel + 1][count] = src->coeff[channel + 1][count];
            }
        }
    }
}
