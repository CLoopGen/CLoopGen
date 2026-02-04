#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t cb_ma_predictor[2][4][10];
extern  int16_t cb_ma_predictor_sum_inv[2][10];
extern int16_t *lsfq;
extern int16_t *past_quantizer_outputs[5];
extern int ma_predictor_prev;
extern int16_t *quantizer_output;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 10; i += 2) {
    int tmp1 = lsfq[i] << 15;
    int tmp2 = lsfq[i+1] << 15;
    for (k = 0; k < 4; k++) {
        tmp1 -= past_quantizer_outputs[k][i] * cb_ma_predictor[ma_predictor_prev][k][i];
        tmp2 -= past_quantizer_outputs[k][i+1] * cb_ma_predictor[ma_predictor_prev][k][i+1];
    }
    quantizer_output[i]   = ((tmp1 >> 15) * cb_ma_predictor_sum_inv[ma_predictor_prev][i]) >> 12;
    quantizer_output[i+1] = ((tmp2 >> 15) * cb_ma_predictor_sum_inv[ma_predictor_prev][i+1]) >> 12;
}
}
