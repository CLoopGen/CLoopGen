#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT32 temp_vals[8];
    INT32 factor_r = (INT32)((0.29899999999999999) * (1L << 16) + 0.5);
    INT32 factor_g = (INT32)((0.58699999999999997) * (1L << 16) + 0.5);
    INT32 factor_b = (INT32)((0.114) * (1L << 16) + 0.5);
    INT32 factor_cb_r = (INT32)((0.16874) * (1L << 16) + 0.5);
    INT32 factor_cb_g = (INT32)((0.33126) * (1L << 16) + 0.5);
    INT32 factor_cr_g = (INT32)((0.41869000000000001) * (1L << 16) + 0.5);
    INT32 factor_cr_b = (INT32)((0.081309999999999993) * (1L << 16) + 0.5);

    for (i = 0; i <= 255; i++) {
        temp_vals[0] = factor_r * i;
        temp_vals[1] = factor_g * i;
        temp_vals[2] = factor_b * i + ((INT32)1 << (16 - 1));
        temp_vals[3] = (-factor_cb_r) * i;
        temp_vals[4] = (-factor_cb_g) * i;
        temp_vals[5] = ((INT32)((0.5) * (1L << 16) + 0.5)) * i + ((INT32)128 << 16) + ((INT32)1 << (16 - 1)) - 1;
        temp_vals[6] = (-factor_cr_g) * i;
        temp_vals[7] = (-factor_cr_b) * i;

        for (INT32 j = 0; j < 8; j++) {
            rgb_ycc_tab[i + j * (255 + 1)] = temp_vals[j];
        }
    }
}
