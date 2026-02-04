#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float ff_aac_pow2sf_tab[428];
float ff_aac_pow34sf_tab[428];
int i;

float exp2_lut[16];

float t1;
float t2;
int t1_inc_cur;
int t2_inc_cur;
int t1_inc_prev;
int t2_inc_prev;

void init_vars() {
    t1 = 1.0f;
    t2 = 1.5f;
    t1_inc_cur = 0;
    t2_inc_cur = 0;
    t1_inc_prev = 0;
    t2_inc_prev = 0;

    for (int j = 0; j < 16; j++) {
        exp2_lut[j] = (float)(1 << j);
    }
}