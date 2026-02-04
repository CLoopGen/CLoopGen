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
    for (i = 0; i < 5; i++) {
        int sum1 = quantizer_output[i] * cb_ma_predictor_sum[ma_predictor][i];
        int sum2 = quantizer_output[i + 5] * cb_ma_predictor_sum[ma_predictor][i + 5];
        for (j = 0; j < 4; j++) {
            sum1 += past_quantizer_outputs[j][i] * cb_ma_predictor[ma_predictor][j][i];
            sum2 += past_quantizer_outputs[j][i + 5] * cb_ma_predictor[ma_predictor][j][i + 5];
        }
        lsfq[i] = sum1 >> 15;
        lsfq[i + 5] = sum2 >> 15;
    }
}
