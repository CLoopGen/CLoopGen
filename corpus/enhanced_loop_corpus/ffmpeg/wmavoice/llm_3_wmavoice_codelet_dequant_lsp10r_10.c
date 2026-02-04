#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *i_lsps;
extern  double *old;
extern double *a1;
extern  float (*ipol_tab)[2][10];
extern uint16_t interpol;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant 1: Strided memory access with stride of 2, processing alternating elements
for (n = 0; n < 20; n += 2) {
    int idx = n / 2;
    double delta = old[idx] - i_lsps[idx];
    a1[n] = ipol_tab[interpol][0][idx] * delta + i_lsps[idx];
    a1[n + 1] = ipol_tab[interpol][1][idx] * delta + i_lsps[idx];
}
}
