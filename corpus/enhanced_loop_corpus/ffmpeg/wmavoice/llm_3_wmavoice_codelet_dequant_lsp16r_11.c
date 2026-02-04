#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *i_lsps;
extern  double *old;
extern double *a1;
extern  float (*ipol_tab)[2][16];
extern uint16_t interpol;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < 16; n++) {
    int idx = 15 - n; // Reverse access: strided from end to start
    double delta = old[idx] - i_lsps[idx];
    a1[idx] = ipol_tab[interpol][0][idx] * delta + i_lsps[idx];
    a1[16 + idx] = ipol_tab[interpol][1][idx] * delta + i_lsps[idx];
}
}
