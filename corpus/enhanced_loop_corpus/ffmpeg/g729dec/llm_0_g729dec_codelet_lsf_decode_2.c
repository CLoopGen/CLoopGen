#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t cb_ma_predictor[2][4][10];
extern  int16_t cb_ma_predictor_sum[2][10];
extern int16_t *lsfq;
extern int16_t *past_quantizer_outputs[5];
extern int16_t ma_predictor;
extern int i;
extern int j;
extern int16_t *quantizer_output;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 10; i++) {
    int sum = quantizer_output[i] * cb_ma_predictor_sum[ma_predictor][i];
    j = 0;
    for (; j < 4; j++) {
        sum += past_quantizer_outputs[j][i] * cb_ma_predictor[ma_predictor][j][i];
    }
    lsfq[i] = sum >> 15;
}
}
