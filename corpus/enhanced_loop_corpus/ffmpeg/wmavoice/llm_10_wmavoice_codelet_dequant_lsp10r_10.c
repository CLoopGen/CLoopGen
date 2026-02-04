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
for (n = 0; n < 10; n += 2) {
    double delta0 = old[n] - i_lsps[n];
    double temp0 = ipol_tab[interpol][0][n] * delta0;
    a1[n] = temp0 + i_lsps[n];
    a1[10 + n] = ipol_tab[interpol][1][n] * delta0 + i_lsps[n];

    if (n + 1 < 10) {
        double delta1 = old[n + 1] - i_lsps[n + 1];
        double temp1 = ipol_tab[interpol][0][n + 1] * delta1;
        a1[n + 1] = temp1 + i_lsps[n + 1];
        a1[11 + n] = ipol_tab[interpol][1][n + 1] * delta1 + i_lsps[n + 1];
    }
}
}
