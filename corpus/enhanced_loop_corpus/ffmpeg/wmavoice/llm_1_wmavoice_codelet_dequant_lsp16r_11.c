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
    double delta = old[n] - i_lsps[n];
    for (int col = 0; col < 2; col++) {
        a1[col * 16 + n] = ipol_tab[interpol][col][n] * delta + i_lsps[n];
    }
}
}
