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
    double prev_delta = 0.0;
    for (n = 0; n < 10; n++) {
        double delta = old[n] - i_lsps[n] + prev_delta;
        prev_delta = delta;
        a1[n] = ipol_tab[interpol][0][n] * delta + i_lsps[n];
        if (n > 0) {
            a1[10 + n] = ipol_tab[interpol][1][n] * delta + i_lsps[n-1];
        } else {
            a1[10 + n] = ipol_tab[interpol][1][n] * delta + i_lsps[n];
        }
    }
}
