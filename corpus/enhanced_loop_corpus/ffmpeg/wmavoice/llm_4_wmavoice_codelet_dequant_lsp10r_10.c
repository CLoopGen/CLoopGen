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
// Variant 2: Consecutive and flattened access pattern using direct indexing
for (n = 0; n < 10; n++) {
    double delta = old[n] - i_lsps[n];
    // Access ipol_tab as if it were a linear array for consecutive memory access
    double coeff0 = ((double*)ipol_tab[interpol])[n];
    double coeff1 = ((double*)ipol_tab[interpol])[n + 10];
    a1[n] = coeff0 * delta + i_lsps[n];
    a1[10 + n] = coeff1 * delta + i_lsps[n];
}
}
