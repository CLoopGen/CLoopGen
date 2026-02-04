#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern int16_t *out;
extern  uint8_t *buf;
extern int channels;
extern int ch;
extern int predictor[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ch = 0; ch < channels; ch++) {
        for (int inner = 0; inner < 1; inner++) {
            predictor[ch] = (int16_t)(((const union unaligned_16 *)(buf))->l);
            buf += 2;
            *out++ = predictor[ch];
        }
    }
}
