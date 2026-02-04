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
    double acc_delta = 0.0;
    for (n = 0; n < 16; n++) {
        double delta = old[n] - i_lsps[n] + acc_delta;
        acc_delta = delta; 
        a1[n] = ipol_tab[interpol][0][n] * (delta - acc_delta) + i_lsps[n];
        a1[16 + n] = ipol_tab[interpol][1][n] * (delta - acc_delta) + i_lsps[n];
    }
}
