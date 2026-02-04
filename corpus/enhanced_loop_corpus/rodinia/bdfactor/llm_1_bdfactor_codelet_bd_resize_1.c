#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int lb;
extern int i;
extern int j;
extern int l;
extern int umin;
extern double **Av;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = lb + 1, l = 1; l <= umin; i++, l++) {
    Av[i][0] = 0.;
    for (j = 1; j < l; j += 2) {
        if (j + 1 < l) {
            Av[i][j]     = 0.;
            Av[i][j + 1] = 0.;
        } else {
            Av[i][j] = 0.;
        }
    }
}
}
