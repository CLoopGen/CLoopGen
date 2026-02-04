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
    uint8_t *local_buf = buf;
    int16_t local_pred[2];
    for (ch = 0; ch < channels; ch++) {
        local_pred[ch] = (int16_t)(((const union unaligned_16 *)(local_buf))->l);
        local_buf += 2;
    }
    for (ch = 0; ch < channels; ch++) {
        predictor[ch] = local_pred[ch];
        *out++ = local_pred[ch];
    }
    buf = local_buf;
}
