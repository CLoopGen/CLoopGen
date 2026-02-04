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
for (n = 0; n < 5; n++) {
    double delta1 = old[n] - i_lsps[n];
    double delta2 = old[n + 5] - i_lsps[n + 5];
    a1[n] = ipol_tab[interpol][0][n] * delta1 + i_lsps[n];
    a1[10 + n] = ipol_tab[interpol][1][n] * delta1 + i_lsps[n];
    a1[n + 5] = ipol_tab[interpol][0][n + 5] * delta2 + i_lsps[n + 5];
    a1[15 + n] = ipol_tab[interpol][1][n + 5] * delta2 + i_lsps[n + 5];
}
}
