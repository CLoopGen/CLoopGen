#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int16_t ff_gain_val_tab[256][3];
extern const uint8_t ff_gain_exp_tab[256];
extern  int16_t *sblock_data;
extern float data[40];
extern float zero[40];
extern float cba[40];
extern float cb1[40];
extern float cb2[40];
extern int cba_idx;
extern int gain;
extern int i;
extern int n;
extern unsigned int m[3];
extern float g[3];
extern float error;
extern float best_error;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < 256; n++) {
    float temp_g1 = ((ff_gain_val_tab[n][1] * m[1]) >> ff_gain_exp_tab[n]) * (1 / 4096.);
    float temp_g2 = ((ff_gain_val_tab[n][2] * m[2]) >> ff_gain_exp_tab[n]) * (1 / 4096.);
    float temp_error = 0.0f;

    if (cba_idx) {
        float temp_g0 = ((ff_gain_val_tab[n][0] * m[0]) >> ff_gain_exp_tab[n]) * (1 / 4096.);
        for (i = 0; i < 40; i++) {
            float pred = zero[i] + temp_g0 * cba[i] + temp_g1 * cb1[i] + temp_g2 * cb2[i];
            float diff = pred - sblock_data[i];
            temp_error += diff * diff;
        }
    } else {
        for (i = 0; i < 40; i++) {
            float pred = zero[i] + temp_g1 * cb1[i] + temp_g2 * cb2[i];
            float diff = pred - sblock_data[i];
            temp_error += diff * diff;
        }
    }

    if (temp_error < best_error) {
        best_error = temp_error;
        gain = n;
    }
}
}
