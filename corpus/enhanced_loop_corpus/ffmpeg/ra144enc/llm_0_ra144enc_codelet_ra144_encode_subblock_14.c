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
    g[1] = ((ff_gain_val_tab[n][1] * m[1]) >> ff_gain_exp_tab[n]) * (1 / 4096.);
    g[2] = ((ff_gain_val_tab[n][2] * m[2]) >> ff_gain_exp_tab[n]) * (1 / 4096.);
    error = 0;
    if (cba_idx) {
        g[0] = ((ff_gain_val_tab[n][0] * m[0]) >> ff_gain_exp_tab[n]) * (1 / 4096.);
        for (i = 0; i < 8; i++) {
            for (int j = 0; j < 5; j++) {
                int idx = i * 5 + j;
                data[idx] = zero[idx] + g[0] * cba[idx] + g[1] * cb1[idx] + g[2] * cb2[idx];
                error += (data[idx] - sblock_data[idx]) * (data[idx] - sblock_data[idx]);
            }
        }
    } else {
        for (i = 0; i < 8; i++) {
            for (int j = 0; j < 5; j++) {
                int idx = i * 5 + j;
                data[idx] = zero[idx] + g[1] * cb1[idx] + g[2] * cb2[idx];
                error += (data[idx] - sblock_data[idx]) * (data[idx] - sblock_data[idx]);
            }
        }
    }
    if (error < best_error) {
        best_error = error;
        gain = n;
    }
}
}
