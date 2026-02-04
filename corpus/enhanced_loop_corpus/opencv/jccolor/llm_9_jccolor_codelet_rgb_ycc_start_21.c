#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

extern JLONG *rgb_ycc_tab;
extern JLONG i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JLONG base_shift = (1L << 16);
    JLONG offset_mid = (JLONG)1 << (16 - 1);
    JLONG y_const = ((JLONG)128 << 16) + offset_mid - 1;

    JLONG k_r = (JLONG)(0.29899999999999999 * base_shift + 0.5);
    JLONG k_g = (JLONG)(0.58699999999999997 * base_shift + 0.5);
    JLONG k_b = (JLONG)(0.114 * base_shift + 0.5);
    JLONG c_u_r = (JLONG)(0.16874 * base_shift + 0.5);
    JLONG c_u_g = (JLONG)(0.33126 * base_shift + 0.5);
    JLONG c_v_g = (JLONG)(0.41869000000000001 * base_shift + 0.5);
    JLONG c_v_b = (JLONG)(0.081309999999999993 * base_shift + 0.5);

    for (i = 0; i <= 127; i++) {
        JLONG idx = i * 2;
        JLONG tab_offset = 255 + 1;

        rgb_ycc_tab[idx + 0] = k_r * idx;
        rgb_ycc_tab[idx + tab_offset * 1] = k_g * idx;
        rgb_ycc_tab[idx + tab_offset * 2] = k_b * idx + offset_mid;
        rgb_ycc_tab[idx + tab_offset * 3] = (-c_u_r) * idx;
        rgb_ycc_tab[idx + tab_offset * 4] = (-c_u_g) * idx;
        rgb_ycc_tab[idx + tab_offset * 5] = ((JLONG)0.5 * base_shift + 0.5) * idx + y_const;
        rgb_ycc_tab[idx + tab_offset * 6] = (-c_v_g) * idx;
        rgb_ycc_tab[idx + tab_offset * 7] = (-c_v_b) * idx;

        idx += 1;
        rgb_ycc_tab[idx + 0] = k_r * idx;
        rgb_ycc_tab[idx + tab_offset * 1] = k_g * idx;
        rgb_ycc_tab[idx + tab_offset * 2] = k_b * idx + offset_mid;
        rgb_ycc_tab[idx + tab_offset * 3] = (-c_u_r) * idx;
        rgb_ycc_tab[idx + tab_offset * 4] = (-c_u_g) * idx;
        rgb_ycc_tab[idx + tab_offset * 5] = ((JLONG)0.5 * base_shift + 0.5) * idx + y_const;
        rgb_ycc_tab[idx + tab_offset * 6] = (-c_v_g) * idx;
        rgb_ycc_tab[idx + tab_offset * 7] = (-c_v_b) * idx;
    }
}
