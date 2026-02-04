#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double *i_lsps;
double *old;
double *a1;
float (*ipol_tab)[2][16];
uint16_t interpol;

int n;

static double i_lsps_data[16];
static double old_data[16];
static double a1_data[32];
static float ipol_tab_data[256][2][16];

void init_vars() {
    i_lsps = i_lsps_data;
    old = old_data;
    a1 = a1_data;
    ipol_tab = (float (*)[2][16])ipol_tab_data;
    interpol = 0;

    for (int i = 0; i < 16; i++) {
        i_lsps[i] = 1.0 + i * 0.5;
        old[i] = 2.0 + i * 0.3;
    }

    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 16; k++) {
                ipol_tab[i][j][k] = 0.01f + (i % 10) * 0.1f;
            }
        }
    }
}