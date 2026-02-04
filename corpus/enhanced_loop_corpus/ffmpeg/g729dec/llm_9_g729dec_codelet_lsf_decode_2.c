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
    for (i = 0; i < 10; i += 2) {
        int sum_even = quantizer_output[i] * cb_ma_predictor_sum[ma_predictor][i];
        int sum_odd = (i + 1 < 10) ? quantizer_output[i + 1] * cb_ma_predictor_sum[ma_predictor][i + 1] : 0;
        for (j = 0; j < 3; j++) { // Reduced iterations in inner loop
            sum_even += past_quantizer_outputs[j][i] * cb_ma_predictor[ma_predictor][j][i];
            if (i + 1 < 10)
                sum_odd += past_quantizer_outputs[j][i + 1] * cb_ma_predictor[ma_predictor][j][i + 1];
        }
        lsfq[i] = sum_even >> 15;
        if (i + 1 < 10)
            lsfq[i + 1] = sum_odd >> 15;
    }
}
