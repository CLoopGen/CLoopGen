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
float local_best_error = best_error;
int local_gain = gain;

for (n = 0; n < 256; n++) {
    float g_local[3] = {0};
    g_local[1] = ((ff_gain_val_tab[n][1] * m[1]) >> ff_gain_exp_tab[n]) * (1 / 4096.);
    g_local[2] = ((ff_gain_val_tab[n][2] * m[2]) >> ff_gain_exp_tab[n]) * (1 / 4096.);

    float error_local = 0.0f;

    if (cba_idx) {
        g_local[0] = ((ff_gain_val_tab[n][0] * m[0]) >> ff_gain_exp_tab[n]) * (1 / 4096.);
        for (i = 0; i < 40; i++) {
            float computed_val = zero[i] + g_local[0] * cba[i] + g_local[1] * cb1[i] + g_local[2] * cb2[i];
            float residual = computed_val - sblock_data[i];
            error_local += residual * residual;
        }
    } else {
        for (i = 0; i < 40; i++) {
            float computed_val = zero[i] + g_local[1] * cb1[i] + g_local[2] * cb2[i];
            float residual = computed_val - sblock_data[i];
            error_local += residual * residual;
        }
    }

    if (error_local < local_best_error) {
        local_best_error = error_local;
        local_gain = n;
    }
}

best_error = local_best_error;
gain = local_gain;
}
