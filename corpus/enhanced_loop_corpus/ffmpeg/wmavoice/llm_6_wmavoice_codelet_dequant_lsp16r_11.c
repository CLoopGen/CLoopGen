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
    double temp[32];
    for (n = 0; n < 16; n++) {
        double delta = old[n] - i_lsps[n];
        temp[n] = ipol_tab[interpol][0][n] * delta + i_lsps[n];
        temp[16 + n] = ipol_tab[interpol][1][n] * delta + i_lsps[n];
    }
    for (n = 0; n < 32; n++) {
        a1[n] = temp[n];
    }
}
