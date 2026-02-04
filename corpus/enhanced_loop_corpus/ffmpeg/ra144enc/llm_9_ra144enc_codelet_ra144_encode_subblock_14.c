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
for (n = 0; n < 128; n++) {
    int idx1 = n;
    int idx2 = n + 128;
    
    float g1_1 = ((ff_gain_val_tab[idx1][1] * m[1]) >> ff_gain_exp_tab[idx1]) * (1 / 4096.);
    float g2_1 = ((ff_gain_val_tab[idx1][2] * m[2]) >> ff_gain_exp_tab[idx1]) * (1 / 4096.);
    float g1_2 = ((ff_gain_val_tab[idx2][1] * m[1]) >> ff_gain_exp_tab[idx2]) * (1 / 4096.);
    float g2_2 = ((ff_gain_val_tab[idx2][2] * m[2]) >> ff_gain_exp_tab[idx2]) * (1 / 4096.);
    
    float error1 = 0, error2 = 0;
    
    if (cba_idx) {
        float g0_1 = ((ff_gain_val_tab[idx1][0] * m[0]) >> ff_gain_exp_tab[idx1]) * (1 / 4096.);
        float g0_2 = ((ff_gain_val_tab[idx2][0] * m[0]) >> ff_gain_exp_tab[idx2]) * (1 / 4096.);
        
        for (i = 0; i < 40; i++) {
            float val1 = zero[i] + g0_1 * cba[i] + g1_1 * cb1[i] + g2_1 * cb2[i];
            float val2 = zero[i] + g0_2 * cba[i] + g1_2 * cb1[i] + g2_2 * cb2[i];
            error1 += (val1 - sblock_data[i]) * (val1 - sblock_data[i]);
            error2 += (val2 - sblock_data[i]) * (val2 - sblock_data[i]);
        }
    } else {
        for (i = 0; i < 40; i++) {
            float val1 = zero[i] + g1_1 * cb1[i] + g2_1 * cb2[i];
            float val2 = zero[i] + g1_2 * cb1[i] + g2_2 * cb2[i];
            error1 += (val1 - sblock_data[i]) * (val1 - sblock_data[i]);
            error2 += (val2 - sblock_data[i]) * (val2 - sblock_data[i]);
        }
    }
    
    if (error1 < best_error) {
        best_error = error1;
        gain = idx1;
    }
    if (error2 < best_error) {
        best_error = error2;
        gain = idx2;
    }
}
}
