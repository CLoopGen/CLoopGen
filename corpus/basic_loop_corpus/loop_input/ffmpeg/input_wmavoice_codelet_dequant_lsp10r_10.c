#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *i_lsps;
double *old;
double *a1;
float (*ipol_tab)[2][10];
uint16_t interpol;

int n;

static double i_lsps_data[10];
static double old_data[10];
static double a1_data[20];
static float ipol_tab_data[1][2][10];

void init_vars() {
    i_lsps = i_lsps_data;
    old = old_data;
    a1 = a1_data;
    ipol_tab = (float (*)[2][10])ipol_tab_data;
    interpol = 0;

    for (int i = 0; i < 10; i++) {
        i_lsps[i] = (double)(i + 1) * 1.5;
        old[i] = (double)(i + 1) * 1.7;
        ipol_tab[0][0][i] = 0.1f * (i + 1);
        ipol_tab[0][1][i] = 0.2f * (i + 1);
    }
}